#!/usr/bin/php
<?php
echo "Enter the length of the rectangle: ";
$length = trim(fgets(STDIN));

echo "Enter the width of the rectangle: ";
$width = trim(fgets(STDIN));

$area = $length * $width;

echo "The total area of the rectangle is $area.\n";
?>

