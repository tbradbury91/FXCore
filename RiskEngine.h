#ifndef RISK_ENGINE_H
#define RISK_ENGINE_H

#include <string>
#include <unordered_map>

class RiskEngine {
public:
    void updatePosition(const std::string& symbol, int quantity, double price, bool isBuy);
    double getPnL(const std::string& symbol) const;
    int getNetPosition(const std::string& symbol) const;

private:
    std::unordered_map<std::string, int> positions;
    std::unordered_map<std::string, double> averagePrice;
};

#endif 
