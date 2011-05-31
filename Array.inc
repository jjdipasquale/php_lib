<?php

// $Id$

/**
 * @file
 *
 */

/**
 * Recusively copy's an array cloning any references. Perserves Keys, Objects shallow copy unless they implement __clone.
 */
function array_copy_recursive(array &$array) {
  $output = array();
  foreach ($array as $key => $value) {
    if (is_array($value)) {
      $output[$key] = array_copy_recursive($value);
    }
    if (is_object($value)) {
      $output[$key] = clone $value;
    }
    else { // Default type copyed by default.
      $output[$key] = $value;
    }
  }
  return $output;
}

/**
 *
 * @param array $array
 * @param type $key
 * @param type $value 
 */
function array_add(array &$array, $key, $value) {
  if (isset($key)) {
    $array[$key] = $value;
  }
  else {
    $array[] = $value;
  }
}