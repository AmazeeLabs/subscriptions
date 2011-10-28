<?php

/**
 * @file
 * Token callbacks for the subscriptions_content module.
 */

/**
 * Implements hook_tokens().
 *
 * @param string $type
 * @param array $tokens
 * @param array $data
 * @param array $options
 *
 * @return array
 */
function subscriptions_content_tokens($type, array $tokens, array $data = array(), array $options = array()) {
  //dpm($tokens, "subscriptions_content_tokens($type) - tokens");
  //dpm($data, "subscriptions_content_tokens($type) - data");
  $sanitize = !empty($options['sanitize']);

  $replacements = array();

  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        // Simple key values on the node.
        case 'node-html':
          $replacements[$original] = $node->nid;
          break;
      }
    }
  }

  if ($type == 'subs' && !empty($data['comment'])) {
    $comment = $data['comment'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'is-new':
          $replacements[$original] = (int) !empty($comment->_subscriptions_is_new);
          break;
        case 'is-updated':
          $replacements[$original] = (int) empty($comment->_subscriptions_is_new);
          break;
        case 'is-old':
          $replacements[$original] = 0;
          break;
        case 'is-published':
          $replacements[$original] = (int) ($comment->status == COMMENT_PUBLISHED);
          break;
      }
    }

    // files:field_FILE
    if (user_access('view uploaded files')) {
      $replacements += _subscriptions_content_tokens_field_array($type, $tokens, $data, $options, 'comment', 'files', 'list<file>');
    }
  }
  elseif ($type == 'subs' && !empty($data['node'])) {
    $node = $data['node'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'is-new':
          $replacements[$original] = (int) !empty($node->_subscriptions_is_new);
          break;
        case 'is-updated':
          $replacements[$original] = (int) !empty($node->_subscriptions_is_updated);
          break;
        case 'is-old':
          $replacements[$original] = (int) (empty($node->_subscriptions_is_new) && empty($node->_subscriptions_is_updated));
          break;
        case 'is-published':
          $replacements[$original] = $node->status;
          break;
      }
    }

    if (($comments_tokens = token_find_with_prefix($tokens, 'comments')) && !empty($node->_subscriptions_comments)) {
      if (empty($node->_subscriptions_comments_rendered)) {
        foreach ($node->_subscriptions_comments as $comment) {
          $node->_subscriptions_comments_rendered[] = mail_edit_format($data['template']['subscriptions_comment_body'], $data + array('comment' => $comment), $options);
        }
      }
      $replacements += token_generate('array', $comments_tokens, array(
        'array' => (isset($node->_subscriptions_comments_rendered) ? $node->_subscriptions_comments_rendered : array()),
      ), array('sanitize' => FALSE) + $options);
    }

    // files:field_FILE
    if (user_access('view uploaded files')) {
      $replacements += _subscriptions_content_tokens_field_array($type, $tokens, $data, $options, 'node', 'files', 'list<file>');
    }
  }

  return $replacements;
}

/**
 * Helper function to resolve a field which is a files array.
 *
 * @param $type
 * @param $tokens
 * @param array $data
 * @param array $options
 * @param $data_type
 * @param $token
 * @param $token_type
 *
 * @return array
 */
function _subscriptions_content_tokens_field_array($type, $tokens, array $data, array $options, $data_type, $token, $token_type)
{
  $replacements = array();

  if ($files_tokens = token_find_with_prefix($tokens, $token)) {

    $url_options = array('absolute' => TRUE);
    if (isset($options['language'])) {
      $url_options['language'] = $options['language'];
      $language_code = $options['language']->language;
    }
    else {
      $language_code = NULL;
    }

    $tokenss = array();
    foreach ($files_tokens as $files_token => $original) {
      $files_field = strtok($files_token, ':');
      $tokenss[$files_field][substr($files_token, strlen($files_field) + 1)] = $original;
    }
    foreach ($tokenss as $files_field => $tokens) {
      if ($files = field_get_items($data_type, $data[$data_type], $files_field, $language_code)) {
        foreach ($files as $key => $file) {
          $file_objs[$key] = (object) $file;
        }
        if (!empty($file_objs)) {
          $replacements += token_generate($token_type, $tokens, array($token_type => $file_objs), $options);
        }
      }
    }
  }
  return $replacements;
}

