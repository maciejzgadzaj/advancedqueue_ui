<?php

/**
 * Implements hook_action_info().
 */
function advancedqueue_ui_action_info() {
  $actions = array();

  $actions['advancedqueue_ui_process_item_action'] = array(
    'type' => 'advancedqueue_item',
    'label' => t('Process item'),
    'configurable' => FALSE,
    'vbo_configurable' => FALSE,
    'triggers' => array('any'),
  );

  $actions['advancedqueue_ui_mark_item_as_processed_action'] = array(
    'type' => 'advancedqueue_item',
    'label' => t('Mark item as processed'),
    'configurable' => TRUE,
    'vbo_configurable' => FALSE,
    'triggers' => array('any'),
  );

  $actions['advancedqueue_ui_release_item_action'] = array(
    'type' => 'advancedqueue_item',
    'label' => t('Release item'),
    'configurable' => FALSE,
    'vbo_configurable' => FALSE,
    'triggers' => array('any'),
  );

  $actions['advancedqueue_ui_requeue_item_action'] = array(
    'type' => 'advancedqueue_item',
    'label' => t('Requeue item'),
    'configurable' => FALSE,
    'vbo_configurable' => FALSE,
    'triggers' => array('any'),
  );

  $actions['advancedqueue_ui_reset_attempt_counter_action'] = array(
    'type' => 'advancedqueue_item',
    'label' => t('Reset attempt counter'),
    'configurable' => FALSE,
    'vbo_configurable' => FALSE,
    'triggers' => array('any'),
  );

  $actions['advancedqueue_ui_delete_item_action'] = array(
    'type' => 'advancedqueue_item',
    'label' => t('Delete item'),
    'configurable' => FALSE,
    'vbo_configurable' => FALSE,
    'triggers' => array('any'),
  );

  return $actions;
}

/**
 * Action callback: delete queue item.
 *
 * @param object $item
 *   A queue item to delete.
 * @param array $context
 *   Additional operation information.
 *
 * @see advancedqueue_ui_action_info()
 *
 * @ingroup actions
 */
function advancedqueue_ui_delete_item_action($item, $context = array()) {
  db_delete('advancedqueue')
    ->condition('name', $item->name)
    ->condition('item_id', $item->item_id)
    ->execute();

  advancedqueue_ui_log_message('Deleted item %item_id from queue %queue_name.', $item);
}

/**
 * Action settings form callback: mark queue item as processed.
 *
 * @see advancedqueue_ui_action_info()
 * @see advancedqueue_ui_mark_item_as_processed_action_submit()
 * @see advancedqueue_ui_mark_item_as_processed_action()
 */
function advancedqueue_ui_mark_item_as_processed_action_form($settings, &$form_state) {
  $form = array();

  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('New status'),
    '#description' => t("The <em>Mark items as processed</em> action will set selected items' <em>processed</em> property to current time. It is also advised to change items' status to either <em>Processed</em> or <em>Failed</em>."),
    '#options' => array('-' => t('- no change -')) + _advancedqueue_status_options(),
    '#default_value' => ADVANCEDQUEUE_STATUS_SUCCESS,
  );

  return $form;
}

/**
 * Action settings form submit callback: mark queue item as processed.
 *
 * @see advancedqueue_ui_action_info()
 * @see advancedqueue_ui_mark_item_as_processed_action_form()
 * @see advancedqueue_ui_mark_item_as_processed_action()
 */
function advancedqueue_ui_mark_item_as_processed_action_submit($form, &$form_state) {
  return array(
    'status' => $form_state['values']['status'],
  );
}

/**
 * Action callback: mark queue item as processed.
 *
 * @param object $item
 *   A queue item to delete.
 * @param array $context
 *   Additional operation information.
 *
 * @see advancedqueue_ui_action_info()
 *
 * @ingroup actions
 */
function advancedqueue_ui_mark_item_as_processed_action($item, $context = array()) {
  if ($context['status'] != '-') {
    $item->status = $context['status'];
  }

  /** @var AdvancedQueue $queue */
  $queue = DrupalQueue::get($item->name);
  $queue->deleteItem($item);

  advancedqueue_ui_log_message('Marked item %item_id as processed in queue %queue_name.', $item);
}

/**
 * Action callback: process queue item.
 *
 * @param object $item
 *   A queue item to process.
 * @param array $context
 *   Additional operation information.
 *
 * @see advancedqueue_ui_action_info()
 *
 * @ingroup actions
 */
function advancedqueue_ui_process_item_action($item, $context = array()) {
  $queues_info = advancedqueue_get_queues_info();

  // Do not allow to process items from undefined queues,
  // as we don't know what their worker function is.
  if (!in_array($item->name, array_keys($queues_info))) {
    drupal_set_message(t('Unable to process item %item_id from an undefined queue %queue_name (unknown worker callback).', array(
      '%item_id' => $item->item_id,
      '%queue_name' => $item->name,
    )), 'error');
    return FALSE;
  }

  /** @var AdvancedQueue $queue */
  $queue = DrupalQueue::get($item->name);

  // Claim the item.
  $update = db_update('advancedqueue')
    ->fields(array(
      'status' => ADVANCEDQUEUE_STATUS_PROCESSING,
      'expire' => time() + 30,
    ))
    ->condition('item_id', $item->item_id)
    ->condition('expire', 0);
  if (!$update->execute()) {
    drupal_set_message(t('Unable to claim item %item_id.', array('%item_id' => $item->item_id)), 'error');
    return FALSE;
  }

  // Process the item.
  advancedqueue_process_item($queue, $item->name, $queues_info[$item->name], $item);

  advancedqueue_ui_log_message('Processed item %item_id from queue %queue_name.', $item);
}

/**
 * Action callback: release queue item.
 *
 * @param object $item
 *   A queue item to release.
 * @param array $context
 *   Additional operation information.
 *
 * @see advancedqueue_ui_action_info()
 *
 * @ingroup actions
 */
function advancedqueue_ui_release_item_action($item, $context = array()) {
  /** @var AdvancedQueue $queue */
  $queue = DrupalQueue::get($item->name);
  $queue->releaseItem($item);

  advancedqueue_ui_log_message('Released item %item_id in queue %queue_name.', $item);
}

/**
 * Action callback: requeue queue item.
 *
 * @param object $item
 *   A queue item to requeue.
 * @param array $context
 *   Additional operation information.
 *
 * @see advancedqueue_ui_action_info()
 *
 * @ingroup actions
 */
function advancedqueue_ui_requeue_item_action($item, $context = array()) {
  /** @var AdvancedQueue $queue */
  $queue = DrupalQueue::get($item->name);
  $queue->requeueItem($item);

  advancedqueue_ui_log_message('Requeued item %item_id in queue %queue_name.', $item);
}

/**
 * Action callback: reset attempt counter.
 *
 * @param object $item
 *   A queue item to reset attempt counter for.
 * @param array $context
 *   Additional operation information.
 *
 * @see advancedqueue_ui_action_info()
 *
 * @ingroup actions
 */
function advancedqueue_ui_reset_attempt_counter_action($item, $context = array()) {
  if (isset($item->data['advancedqueue_attempt'])) {
    unset($item->data['advancedqueue_attempt']);

    db_update('advancedqueue')
      ->fields(array(
        'data' => serialize($item->data),
      ))
      ->condition('item_id', $item->item_id)
      ->execute();

    advancedqueue_ui_log_message('Reset attempt counter for item %item_id in queue %queue_name.', $item);
  }
}
