<?php

/**
 * @file
 * Token callbacks for the subscriptions module.
 */

/**
 * Implements hook_token_info().
 *
 * @return array
 */
function subscriptions_token_info() {
  $info = array(
    'types' => array(
      'subs' => array(
        'name' => t('Subscriptions information'),
        'description' => t('Tokens related to the %Subscriptions module.', array('%Subscriptions' => 'Subscriptions')),
        'needs-data' => 'subs',
      ),
    ),
    'tokens' => array(
      'subs' => array(
        'type' => array(
          'name' => t('Type'),
          'description' => t('The type of the subscription.'),
        ),
        'manage-url' => array(
          'name' => t('Manage URL'),
          'description' => t("The URL of the user's @Subscriptions page (requires log-in).", array('@Subscriptions' => t('Subscriptions'))),
          'type' => 'url',
        ),
        'unsubscribe-url' => array(
          'name' => t('Unsubscribe URL'),
          'description' => t('The URL for immediate canceling of the subscription that caused this notification.'),
          'type' => 'url',
        ),
        'is-new' => array(
          'name' => t('Is new'),
          'description' => t('Whether the item is new.'),
        ),
        'is-updated' => array(
          'name' => t('Is updated'),
          'description' => t('Whether the item is updated (or new and subsequently updated).'),
        ),
        'is-old' => array(
          'name' => t('Is old'),
          'description' => t('Whether the item is not new nor updated.'),
        ),
        'is-published' => array(
          'name' => t('Is published'),
          'description' => t('Whether the item is published.'),
        ),
        'forum' => array(
          'name' => t('Forum'),
          'description' => t('The forum (taxonomy term), if the item is in a forum.'),
          'type' => 'term',
        ),
        'comments' => array(
          'name' => t('Comments'),
          'description' => t('The array of formatted comments that have not been sent yet (for inclusion in a node).'),
          'type' => 'array',
        ),
        'items' => array(
          'name' => t('Digest Items'),
          'description' => t('The array of formatted items to send to one recipient (for inclusion in a digest).'),
        ),
        'subs-module' => array(
          'name' => t('Subscription module'),
          'description' => t('The module of the item that triggered the notification.'),
        ),
        'subs-field' => array(
          'name' => t('Subscription field'),
          'description' => t('The field (property) of the item that triggered the notification.'),
        ),
        'subs-value' => array(
          'name' => t('Subscription value'),
          'description' => t('The value of the field of the item that triggered the notification.'),
        ),
        'files:field_FILES' => array(
          'name' => t('Files'),
          'description' => t('The array of attached files in the %field field, if such a field exists.', array('%field' => 'field_FILES')),
          'type' => 'list<file>',
        ),
      ),
    ),
  );
  return $info;
}

