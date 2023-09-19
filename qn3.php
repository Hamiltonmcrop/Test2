#!/usr/bin/php
<?php
//First name:Navjot
//Second name:singh
//Studnet Id:202104362
echo "Enter your age (in years): ";
$ageInYears = trim(fgets(STDIN));

$monthsInYear = 12;
$daysInMonth = 30; // Approximation, you can adjust this as needed

$ageInMonths = $ageInYears * $monthsInYear;
$ageInDays = $ageInYears * $monthsInYear * $daysInMonth;

echo "You are $ageInMonths months and $ageInDays days old.\n";
?>

