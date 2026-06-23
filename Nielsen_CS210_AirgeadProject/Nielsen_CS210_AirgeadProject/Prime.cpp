#include <iostream>
#include <iomanip>
#include "InvestmentCalculator.h"

using namespace std;

int main() {

    bool keepGoing = true;

    while (keepGoing) {

        system("clear");

        cout << "Welcome to the Airgead Investment Calculator!" << endl;
        cout << "Let's plug in some numbers and see how your money grows." << endl << endl;

        double startAmount;
        double monthlyDeposit;
        double interestRate;
        int years;

        cout << "Starting amount you're investing: ";
        cin >> startAmount;

        cout << "How much do you want to toss in each month? ";
        cin >> monthlyDeposit;

        cout << "Annual interest rate (as a percent): ";
        cin >> interestRate;

        cout << "How many years do you want this to grow? ";
        cin >> years;

        // Check
        while (startAmount <= 0) {
            cout << "Starting amount must be more than zero. Try again: ";
            cin >> startAmount;
        }

        while (monthlyDeposit < 0) {
            cout << "Monthly deposit can't be negative. Try again: ";
            cin >> monthlyDeposit;
        }

        while (interestRate <= 0) {
            cout << "Interest rate must be above zero. Try again: ";
            cin >> interestRate;
        }

        while (years <= 0) {
            cout << "Years must be at least 1. Try again: ";
            cin >> years;
        }

        cout << endl << "Cool. Press ENTER when you're ready to see the results.";
        cin.ignore();
        cin.get();

        InvestmentCalculator calc(startAmount, monthlyDeposit, interestRate, years);

        // No Monthly Deposits

        cout << endl << "(No Monthly Deposits)" << endl;
        cout << "Year | Balance | Interest Earned" << endl;

        auto noDep = calc.calculateNoDeposits();

        for (int i = 0; i < years; i++) {
            cout << (i + 1) << "    $"
                << fixed << setprecision(2) << noDep[i].first
                << "    $" << noDep[i].second << endl;
        }

        // Monthly Deposits
        cout << endl << "(With Monthly Deposits)" << endl;
        cout << "Year | Balance | Interest Earned" << endl;

        auto withDep = calc.calculateWithDeposits();

        for (int i = 0; i < years; i++) {
            cout << (i + 1) << "    $"
                << fixed << setprecision(2) << withDep[i].first
                << "    $" << withDep[i].second << endl;
        }

        cout << endl << "Want to try different numbers? (Y/N): ";
        char answer;
        cin >> answer;

        if (answer == 'Y' || answer == 'y') {
            keepGoing = true;
        }
        else {
            keepGoing = false;
        }
    }

    cout << "Thanks for checking out your investment growth!" << endl;

    return 0;
}