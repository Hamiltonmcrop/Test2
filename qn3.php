#!/usr/bin/php
<?php
echo "Enter your age (in years): ";
$ageInYears = trim(fgets(STDIN));

$monthsInYear = 12;
$daysInMonth = 30; // Approximation, you can adjust this as needed

$ageInMonths = $ageInYears * $monthsInYear;
$ageInDays = $ageInYears * $monthsInYear * $daysInMonth;

echo "You are $ageInMonths months and $ageInDays days old.\n";
?>

