#!/usr/bin/php
<?php
// First name: Sanam
// Last name: Dev
// Student ID: 202104362
echo "Enter a sentence: ";
$input_sentence = trim(fgets(STDIN));

if (stripos($input_sentence, "PHP") !== false) {
    echo "Your input contains the word 'PHP'.\n";
} else {
    echo "The word 'PHP' was not found in your input.\n";
}
?>

