#!/usr/bin/php
<?php
// First name: Sanam
// Last name: Dev
// Student ID: 202104362
echo "Enter your age (in years): ";
$age_in_years = trim(fgets(STDIN));

$months_in_year = 12;
$days_in_month = 30; // Approximation, you can adjust this as needed

$age_in_months = $age_in_years * $months_in_year;
$age_in_days = $age_in_years * $months_in_year * $days_in_month;

echo "You are $age_in_months months and $age_in_days days old.\n";
?>
