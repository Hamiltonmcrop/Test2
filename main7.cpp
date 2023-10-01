//Web Billing
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Function to check if an account number is valid
 */
bool is_valid_account_number(int accountNumber) {
    int sum = 0;
    int temp = accountNumber;

    /**Calculate the sum of digits according to the validation rule
     */
    for (int i = 1; i <= 5; i++) {
        int digit = temp % 10;
        sum += digit * i;
        temp /= 10;
    }

    /**
     * Check if the check digit is valid
     */
    return (sum % 10 == accountNumber / 100000);
}

/**
 * Function to calculate the customer's bill
 */
void calculate_bill(double baseCharge, double diskLimit, double maxUsage, double endUsage, double& overLimitSurcharge, double& endOfMonthPenaltySurcharge, double& gst, double& totalAmountDue) {
    /**
     * Calculate the over-limit surcharge based on the provided table
     */
    double overLimit = maxUsage - diskLimit;
    if (overLimit > 0) {
        if (overLimit <= 50.0) {
            overLimitSurcharge = overLimit * 0.15;
        } else if (overLimit <= 250.0) {
            overLimitSurcharge = 50.0 * 0.15 + (overLimit - 50.0) * 0.26;
        } else if (overLimit <= 500.0) {
            overLimitSurcharge = 50.0 * 0.15 + 200.0 * 0.26 + (overLimit - 250.0) * 0.37;
        } else {
            overLimitSurcharge = 50.0 * 0.15 + 200.0 * 0.26 + 250.0 * 0.37 + (overLimit - 500.0) * 0.48;
        }
    }

    /**
     * Calculate the end-of-month penalty surcharge
     */
    if (endUsage > diskLimit) {
        endOfMonthPenaltySurcharge = max(0.05 * (endUsage - diskLimit), 5.0);
    }

    /**
     * Calculate GST
     */
    gst = (baseCharge + overLimitSurcharge + endOfMonthPenaltySurcharge) * 0.05;

    /**
     * Calculate total amount due
     */
    totalAmountDue = baseCharge + overLimitSurcharge + endOfMonthPenaltySurcharge + gst;
}

/**
 * Function to print the customer's bill
 */
void print_bill(int accountNumber, double diskLimit, double startDiskUsage, double maxDiskUsage, double endDiskUsage, double baseCharge, double overLimitSurcharge, double endOfMonthPenaltySurcharge, double gst, double totalAmountDue) {
    cout << "Account Number:\t\t" << accountNumber << endl;
    cout << endl;
    cout << "Disk Allotment:\t\t" << fixed << setprecision(3) << diskLimit << " MB" << endl;
    cout << "Beginning of Month:\t" << fixed << setprecision(3) << startDiskUsage << " MB" << endl;
    cout << "Maximum during Month:\t" << fixed << setprecision(3) << maxDiskUsage << " MB" << endl;
    cout << "End of Month:\t\t" << fixed << setprecision(3) << endDiskUsage << " MB" << endl;
    cout << endl;
    cout << "Base Charge:\t\t" << fixed << setprecision(2) << baseCharge << endl;

    if (overLimitSurcharge > 0) {
        cout << "Over-limit Surcharge:\t" << fixed << setprecision(2) << overLimitSurcharge << endl;
    }

    if (endOfMonthPenaltySurcharge > 0) {
        cout << "Penalty Surcharge:\t" << fixed << setprecision(2) << endOfMonthPenaltySurcharge << endl;
    }

    cout << "GST:\t\t\t" << fixed << setprecision(2) << gst << endl;
    cout << "Amount Due:     $ \t" << fixed << setprecision(2) << totalAmountDue << endl;
}

int main() {
    int accountNumber;
    double baseCharge, diskLimit, startDiskUsage, maxDiskUsage, endDiskUsage;
    char transactionFlag;

    /**
     * Read the header record
     */
    cin >> accountNumber >> baseCharge >> diskLimit >> startDiskUsage;

    /**
     * Read the transaction record
     */
    cin >> maxDiskUsage >> endDiskUsage >> transactionFlag;

    /**
     * Check if the account number is valid
     */
    if (!is_valid_account_number(accountNumber)) {
        cout << "Invalid account number " << accountNumber << " found" << endl;
        cout << "*** Account " << accountNumber << " not processed due to errors ***" << endl;
    } else {
        double overLimitSurcharge = 0.0, endOfMonthPenaltySurcharge = 0.0, gst = 0.0, totalAmountDue = 0.0;
        calculate_bill(baseCharge, diskLimit, maxDiskUsage, endDiskUsage, overLimitSurcharge, endOfMonthPenaltySurcharge, gst, totalAmountDue);

        print_bill(accountNumber, diskLimit, startDiskUsage, maxDiskUsage, endDiskUsage, baseCharge, overLimitSurcharge, endOfMonthPenaltySurcharge, gst, totalAmountDue);
    }

    return 0;
}

