#include "RiskEngine.h"

void RiskEngine::updatePosition(const std::string& symbol, int quantity, double price, bool isBuy) {
    int& pos = positions[symbol];
    double& avgPrice = averagePrice[symbol];

    if (isBuy) {
        double totalCost = avgPrice * pos + price * quantity;
        pos += quantity;
        avgPrice = pos ? totalCost / pos : 0.0;
    } else {
        pos -= quantity;
    }
}

double RiskEngine::getPnL(const std::string& symbol) const {
    auto posIt = positions.find(symbol);
    auto priceIt = averagePrice.find(symbol);
    if (posIt == positions.end() || priceIt == averagePrice.end()) return 0.0;

    int netPos = posIt->second;
    double avgPrice = priceIt->second;

    // assume current market price is same as avgPrice for simplicity?
    return netPos * (avgPrice - avgPrice);  // replace with market price later
}

int RiskEngine::getNetPosition(const std::string& symbol) const {
    auto it = positions.find(symbol);
    return it != positions.end() ? it->second : 0;
}
