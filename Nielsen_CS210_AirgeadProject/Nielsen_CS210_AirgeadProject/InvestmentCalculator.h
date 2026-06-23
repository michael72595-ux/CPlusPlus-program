#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

#include <vector>

class InvestmentCalculator {
public:
    // Users numbers
    InvestmentCalculator(double start, double monthly, double rate, int years);

    // NO monthly deposits
    std::vector<std::pair<double, double>> calculateNoDeposits();

    // WITH monthly deposits
    std::vector<std::pair<double, double>> calculateWithDeposits();

private:
    double initialAmount;
    double monthlyDeposit;
    double annualInterest;
    int years;
};

#endif
