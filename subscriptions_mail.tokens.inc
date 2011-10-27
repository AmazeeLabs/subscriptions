<?php

/**
 * @file
 * Token callbacks for the subscriptions_mail module.
 */

/**
 * Implements hook_tokens().
 *
 * @param $type
 * @param $tokens
 * @param array $data
 * @param array $options
 *
 * @return array
 */
function subscriptions_mail_tokens($type, $tokens, array $data = array(), array $options = array())
{
  global $user;

  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }
  $sanitize = !empty($options['sanitize']);

  $replacements = array();
  if ($type == 'subs' && isset($data['subs'])) {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'type':
          $replacements[$original] = $data['subs']['type'];
          break;
        case 'manage-url':
          $replacements[$original] = url('user/' . $user->uid . '/subscriptions', $url_options);
          break;
        case 'unsubscribe-url':
          $replacements[$original] = url($data['subs']['unsubscribe_path'], $url_options);
          break;
        case 'subs-module':
          $replacements[$original] = $data['subs']['module'];
          break;
        case 'subs-field':
          $replacements[$original] = $data['subs']['field'];
          break;
        case 'subs-value':
          $replacements[$original] = $data['subs']['value'];
          break;
        case 'forum':
          if (isset($data['node']['forum_tid'])) {
            $replacements[$original] = render(taxonomy_term_view(taxonomy_term_load($data['node']['forum_tid']), 'full', $language_code));
          }
          break;
      }
    }

    // Chained token relationships.
    if ($url_tokens = token_find_with_prefix($tokens, 'manage-url')) {
      $replacements += token_generate('url', $url_tokens, array('path' => 'user/' . $user->uid . '/subscriptions'), $options);
    }
    if ($url_tokens = token_find_with_prefix($tokens, 'unsubscribe-url')) {
      $replacements += token_generate('url', $url_tokens, array('path' => $data['subs']['unsubscribe_path']), $options);
    }
    if ($forum_tokens = token_find_with_prefix($tokens, 'forum')) {
      $replacements += token_generate('term', $forum_tokens, array('term' => taxonomy_term_load($data['node']->forum_tid)), $options);
    }
  }
  return $replacements;
}

