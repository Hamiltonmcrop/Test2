#!/usr/bin/php
<?php
//First name:Navjot
//Second name:singh
//Studnet Id:202104362
echo "Enter a sentence: ";
$sentence = trim(fgets(STDIN));

if (stripos($sentence, "PHP") !== false) {
    echo "Your input contains the word 'PHP'.\n";
} else {
    echo "The word 'PHP' was not found in your input.\n";
}
?>

