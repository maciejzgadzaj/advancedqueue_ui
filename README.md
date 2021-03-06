# Advanced Queue UI

## Description

_Advanced Queue UI_ module is an extension to [_Advanced Queue_](https://www.drupal.org/project/advancedqueue) module, providing alternative admin user interface for viewing and managing queue items.


## Features

* Page listing all queues defined by `hook_advanced_queue_info()` implementations and number of items in them by their status
  - optionally also listing undefined queues (not defined by `hook_advanced_queue_info()` implementations - for example _Update_ or _Views Bulk Operations_ module queues), if enabled on the module settings page
  - support for queue groups (`group` property - see [#2013687](https://www.drupal.org/node/2013687)) and descriptions (unofficial `description` property)
  - support for queue and group operations:
    - process all unprocessed items in the queue/group
    - delete all items from the queue/group

  ![Queues](http://i.imgur.com/DFlsOrU.png "Queues")

* Pages listing all/selected items for each queue, and for all queues together
  - filters for all queue item properties
  - [_Views Bulk Operations_](https://www.drupal.org/project/views_bulk_operations) support for operations on queue items:
    - process item
    - mark item as processed
    - release item
    - requeue item
    - reset attempt counter
    - modify entity values
    - delete item

  ![Queue items](http://i.imgur.com/981RVlt.png "Queue items")

* Separate user permissions for viewing and managing queues and queue items

  ![User permissions](http://i.imgur.com/yfuaGTd.png "User permissions")

* [_Devel_](https://www.drupal.org/project/devel) module support for displaying queue and queue item details

  ![Queue devel](http://i.imgur.com/snDU206.png "Queue devel")
