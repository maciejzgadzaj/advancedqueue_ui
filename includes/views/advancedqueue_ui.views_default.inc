<?php

/**
 * Implements hook_views_default_views().
 */
function advancedqueue_ui_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'advancedqueue_ui';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'advancedqueue';
  $view->human_name = 'Advanced Queue UI';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  if (advancedqueue_ui_db_supports_group_concat()) {
    $handler->display->display_options['group_by'] = TRUE;
  }
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer advancedqueue_ui';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50, 100, 200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'queue_name' => 'queue_name',
    'queue_machine_name' => 'queue_machine_name',
    'item_id' => 'item_id',
    'item_key' => 'item_id',
    'title' => 'title',
    'tag' => 'title',
    'created' => 'created',
    'name' => 'name',
    'status' => 'status',
    'expire' => 'status',
    'processed' => 'processed',
    'data' => 'data',
    'result' => 'result',
  );
  $handler->display->display_options['style_options']['default'] = 'item_id';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'queue_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'queue_machine_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'item_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'item_key' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'tag' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'expire' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'processed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'data' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'result' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No queue items found for the specified criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Queue: Item Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'advancedqueue';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Item Owner';
  /* Field: Bulk operations: Queue */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::advancedqueue_ui_process_item_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::advancedqueue_ui_mark_item_as_processed_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::advancedqueue_ui_release_item_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::advancedqueue_ui_requeue_item_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::advancedqueue_ui_reset_attempt_counter_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::advancedqueue_ui_delete_item_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Queue: Queue name */
  $handler->display->display_options['fields']['queue_name']['id'] = 'queue_name';
  $handler->display->display_options['fields']['queue_name']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['queue_name']['field'] = 'name';
  /* Field: Queue: Queue name */
  $handler->display->display_options['fields']['queue_machine_name']['id'] = 'queue_machine_name';
  $handler->display->display_options['fields']['queue_machine_name']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['queue_machine_name']['field'] = 'name';
  $handler->display->display_options['fields']['queue_machine_name']['label'] = 'Queue machine name';
  $handler->display->display_options['fields']['queue_machine_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['queue_machine_name']['queue_name_source'] = 'machine_name';
  /* Field: Queue: Item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['item_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['item_id']['alter']['path'] = 'admin/structure/queues/!1/[item_id]';
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Queue: Item key */
  $handler->display->display_options['fields']['item_key']['id'] = 'item_key';
  $handler->display->display_options['fields']['item_key']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['item_key']['field'] = 'item_key';
  $handler->display->display_options['fields']['item_key']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['item_key']['alter']['text'] = '<div class="description">[item_key]</div>';
  /* Field: Queue: Item title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  /* Field: GROUP_CONCAT(DISTINCT NULLIF(Queue: Tag, '') SEPARATOR ', ') */
  if (advancedqueue_ui_db_supports_group_concat()) {
    $handler->display->display_options['fields']['tag']['id'] = 'tag';
    $handler->display->display_options['fields']['tag']['table'] = 'advancedqueue_tags';
    $handler->display->display_options['fields']['tag']['field'] = 'tag';
    $handler->display->display_options['fields']['tag']['group_type'] = 'group_concat_distinct';
    $handler->display->display_options['fields']['tag']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['tag']['alter']['text'] = '<div class="description">[tag]</div>';
  }
  /* Field: Queue: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Owner';
  /* Field: Queue: Item status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Queue: Claim expiration */
  $handler->display->display_options['fields']['expire']['id'] = 'expire';
  $handler->display->display_options['fields']['expire']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['expire']['field'] = 'expire';
  $handler->display->display_options['fields']['expire']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['expire']['alter']['text'] = '<div class="description" title="Claim expiration">[expire]</div>';
  $handler->display->display_options['fields']['expire']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['expire']['date_format'] = 'custom';
  $handler->display->display_options['fields']['expire']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['expire']['second_date_format'] = 'long';
  /* Field: Queue: Processed date */
  $handler->display->display_options['fields']['processed']['id'] = 'processed';
  $handler->display->display_options['fields']['processed']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['processed']['field'] = 'processed';
  $handler->display->display_options['fields']['processed']['label'] = 'Processed';
  $handler->display->display_options['fields']['processed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['processed']['custom_date_format'] = 'Y-m-d H:i:s';
  $handler->display->display_options['fields']['processed']['second_date_format'] = 'long';
  /* Field: Queue: Item data */
  $handler->display->display_options['fields']['data']['id'] = 'data';
  $handler->display->display_options['fields']['data']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['data']['field'] = 'data';
  $handler->display->display_options['fields']['data']['label'] = 'Attempts';
  $handler->display->display_options['fields']['data']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['data']['format'] = 'key';
  $handler->display->display_options['fields']['data']['key'] = 'advancedqueue_attempt';
  /* Field: Queue: Result */
  $handler->display->display_options['fields']['result']['id'] = 'result';
  $handler->display->display_options['fields']['result']['table'] = 'advancedqueue';
  $handler->display->display_options['fields']['result']['field'] = 'result';
  /* Contextual filter: Queue: Queue name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'advancedqueue';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['name']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['exception']['title'] = 'All items';
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = '%1';
  $handler->display->display_options['arguments']['name']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine_name_machine_name']['id'] = 'combine_name_machine_name';
  $handler->display->display_options['filters']['combine_name_machine_name']['table'] = 'views';
  $handler->display->display_options['filters']['combine_name_machine_name']['field'] = 'combine';
  $handler->display->display_options['filters']['combine_name_machine_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine_name_machine_name']['group'] = 1;
  $handler->display->display_options['filters']['combine_name_machine_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine_name_machine_name']['expose']['operator_id'] = 'combine_name_machine_name_op';
  $handler->display->display_options['filters']['combine_name_machine_name']['expose']['label'] = 'Queue name';
  $handler->display->display_options['filters']['combine_name_machine_name']['expose']['operator'] = 'combine_name_machine_name_op';
  $handler->display->display_options['filters']['combine_name_machine_name']['expose']['identifier'] = 'name_machine_name';
  $handler->display->display_options['filters']['combine_name_machine_name']['fields'] = array(
    'queue_name' => 'queue_name',
    'queue_machine_name' => 'queue_machine_name',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine_item_id_key']['id'] = 'combine_item_id_key';
  $handler->display->display_options['filters']['combine_item_id_key']['table'] = 'views';
  $handler->display->display_options['filters']['combine_item_id_key']['field'] = 'combine';
  $handler->display->display_options['filters']['combine_item_id_key']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine_item_id_key']['group'] = 1;
  $handler->display->display_options['filters']['combine_item_id_key']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine_item_id_key']['expose']['operator_id'] = 'combine_item_id_key_op';
  $handler->display->display_options['filters']['combine_item_id_key']['expose']['label'] = 'Item ID/key';
  $handler->display->display_options['filters']['combine_item_id_key']['expose']['operator'] = 'combine_item_id_key_op';
  $handler->display->display_options['filters']['combine_item_id_key']['expose']['identifier'] = 'item_id_key';
  $handler->display->display_options['filters']['combine_item_id_key']['fields'] = array(
    'item_id' => 'item_id',
    'item_key' => 'item_key',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine_title_tag']['id'] = 'combine_title_tag';
  $handler->display->display_options['filters']['combine_title_tag']['table'] = 'views';
  $handler->display->display_options['filters']['combine_title_tag']['field'] = 'combine';
  $handler->display->display_options['filters']['combine_title_tag']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine_title_tag']['group'] = 1;
  $handler->display->display_options['filters']['combine_title_tag']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine_title_tag']['expose']['operator_id'] = 'combine_title_tag_op';
  $handler->display->display_options['filters']['combine_title_tag']['expose']['label'] = 'Item title/tag';
  $handler->display->display_options['filters']['combine_title_tag']['expose']['operator'] = 'combine_title_tag_op';
  $handler->display->display_options['filters']['combine_title_tag']['expose']['identifier'] = 'item_title_tag';
  $handler->display->display_options['filters']['combine_title_tag']['fields'] = array(
    'title' => 'title',
    'tag' => 'tag',
  );
  /* Filter criterion: Queue: Created date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'Format: CCYY-MM-DD HH:MM:SS';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Owner';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  /* Filter criterion: Queue: Item status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  /* Filter criterion: Queue: Processed date */
  $handler->display->display_options['filters']['processed']['id'] = 'processed';
  $handler->display->display_options['filters']['processed']['table'] = 'advancedqueue';
  $handler->display->display_options['filters']['processed']['field'] = 'processed';
  $handler->display->display_options['filters']['processed']['operator'] = 'between';
  $handler->display->display_options['filters']['processed']['group'] = 1;
  $handler->display->display_options['filters']['processed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['processed']['expose']['operator_id'] = 'processed_op';
  $handler->display->display_options['filters']['processed']['expose']['label'] = 'Processed';
  $handler->display->display_options['filters']['processed']['expose']['description'] = 'Format: CCYY-MM-DD HH:MM:SS';
  $handler->display->display_options['filters']['processed']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['processed']['expose']['operator'] = 'processed_op';
  $handler->display->display_options['filters']['processed']['expose']['identifier'] = 'processed';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine_data_result']['id'] = 'combine_data_result';
  $handler->display->display_options['filters']['combine_data_result']['table'] = 'views';
  $handler->display->display_options['filters']['combine_data_result']['field'] = 'combine';
  $handler->display->display_options['filters']['combine_data_result']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine_data_result']['group'] = 1;
  $handler->display->display_options['filters']['combine_data_result']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine_data_result']['expose']['operator_id'] = 'combine_data_result_op';
  $handler->display->display_options['filters']['combine_data_result']['expose']['label'] = 'Data/result';
  $handler->display->display_options['filters']['combine_data_result']['expose']['operator'] = 'combine_data_result_op';
  $handler->display->display_options['filters']['combine_data_result']['expose']['identifier'] = 'item_data_result';
  $handler->display->display_options['filters']['combine_data_result']['fields'] = array(
    'data' => 'data',
    'result' => 'result',
  );
  $translatables['advancedqueue_ui'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No queue items found for the specified criteria.'),
    t('Item Owner'),
    t('Queue'),
    t('- Choose an operation -'),
    t('Queue name'),
    t('Queue machine name'),
    t('Item ID'),
    t('.'),
    t('Item key'),
    t('<div class="description">[item_key]</div>'),
    t('Title'),
    t('Tag'),
    t('<div class="description">[tag]</div>'),
    t('Created'),
    t('Owner'),
    t('Status'),
    t('Claim expiration'),
    t('<div class="description" title="Claim expiration">[expire]</div>'),
    t('Processed'),
    t('Attempts'),
    t('Result'),
    t('All items'),
    t('%1'),
    t('Item ID/key'),
    t('Item title/tag'),
    t('Format: CCYY-MM-DD HH:MM:SS'),
    t('Data/result'),
  );
  $views[$view->name] = $view;

  return $views;
}

/**
 * Checks if current database type supports GROUP_CONCAT() function.
 *
 * @return bool
 *   TRUE if current database type supports GROUP_CONCAT() function,
 *   FALSE otherwise.
 *
 * @see advancedqueue_ui_views_default_views()
 */
function advancedqueue_ui_db_supports_group_concat() {
  return in_array(Database::getConnection()->databaseType(), array('mysql', 'mysqli', 'sqlite'));
}
