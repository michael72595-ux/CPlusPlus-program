#include "InvestmentCalculator.h"

// Adds inputs
InvestmentCalculator::InvestmentCalculator(double start, double monthly, double rate, int yrs) {
    initialAmount = start;
    monthlyDeposit = monthly;
    annualInterest = rate;
    years = yrs;
}

// NO monthly deposits
std::vector<std::pair<double, double>> InvestmentCalculator::calculateNoDeposits() {
    std::vector<std::pair<double, double>> results;

    double balance = initialAmount;
    double monthlyRate = (annualInterest / 100.0) / 12.0;

    for (int y = 1; y <= years; y++) {
        double interestEarned = 0;

        for (int m = 1; m <= 12; m++) {
            double interest = balance * monthlyRate;
            interestEarned += interest;
            balance += interest;
        }

        results.push_back({ balance, interestEarned });
    }

    return results;
}

// WITH monthly deposits
std::vector<std::pair<double, double>> InvestmentCalculator::calculateWithDeposits() {
    std::vector<std::pair<double, double>> results;

    double balance = initialAmount;
    double monthlyRate = (annualInterest / 100.0) / 12.0;

    for (int y = 1; y <= years; y++) {
        double interestEarned = 0;

        for (int m = 1; m <= 12; m++) {
            balance += monthlyDeposit; 
            double interest = balance * monthlyRate;
            interestEarned += interest;
            balance += interest;
        }

        results.push_back({ balance, interestEarned });
    }

    return results;
}