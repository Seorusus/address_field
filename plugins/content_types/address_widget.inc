<?php

$plugin = array(
  'title' => t('Adding address field plugin'),
  'description' => t('Adding address field.'),
  'content_types' => array('no_context_content_type'),
  'render callback' => 'address_widget_static_block_render',
  'defaults' => array(),
  'category' => t('Custom panels'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'icon' => 'favicon.ico',
  'single' => TRUE,
);

/**
 * Render the custom content type.
 */
function address_widget_static_block_render($subtype, $conf, $panel_args, $context) {

	$node= $context->data;

  	$block = new stdClass();
  	$block->module  = 'address_field';
  	$block->content = field_view_field('node', $node, 'address');
  	$output = render($block->content);
  	return $block;
}
