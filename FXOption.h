#ifndef FXOPTION_H
#define FXOPTION_H

#include <string>

enum class OptionType {
    CALL,
    PUT
};

class FXOption {
public:
    std::string symbol;
    double strike;
    double volatility;
    double interestRate;
    int timeToMaturity;
    OptionType optionType;
    std::string expiry;
    
    // Constructor for easy creation of FXOption objects
    FXOption(const std::string& symbol, double strike, double volatility, double interestRate, 
             int timeToMaturity, OptionType optionType, const std::string& expiry)
        : symbol(symbol), strike(strike), volatility(volatility), interestRate(interestRate),
          timeToMaturity(timeToMaturity), optionType(optionType), expiry(expiry) {}
};

#endif
