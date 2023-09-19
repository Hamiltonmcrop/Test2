#!/usr/bin/php
<?php
// Additional information
// first name :- Navjot
// last name :- Singh
// student id :- 202104362

// This script takes user input for first name and last name

// Prompt the user for their first name
echo "Enter your first name: ";
$first_name = trim(fgets(STDIN));

// Prompt the user for their last name
echo "Enter your last name: ";
$last_name = trim(fgets(STDIN));

// Display a greeting message
echo "Hello, $first_name $last_name!\n";
?>

