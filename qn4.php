#!/usr/bin/php
<?php
echo "Enter the first number: ";
$number1 = trim(fgets(STDIN));

echo "Enter the second number: ";
$number2 = trim(fgets(STDIN));

$sum = $number1 + $number2;

echo "The sum of $number1 and $number2 is $sum.\n";
?>

