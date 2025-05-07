#include "PricingEngine.h"
#include <limits>
#include <algorithm>
#include "PriceFeed.h"
#include "OrderBook.h"
#include <iostream>


PricingEngine::PricingEngine(PriceFeed& pf, OrderBook& ob)
    : priceFeed(pf), orderBook(ob) {}

void PricingEngine::calculatePricing() {
    std::string symbol = "EUR/USD"; // placeholder — you can loop over symbols later
    double midPrice = calculateMidPrice(symbol);
    std::cout << "Mid price for " << symbol << " is: " << midPrice << std::endl;
} 

double PricingEngine::getBestBid(const std::string& symbol) const {
    double bestBid = 0.0;
    for (const auto& order : orderBook.getBuyOrders(symbol)) {
        bestBid = std::max(bestBid, order.getPrice());
    }
    return bestBid;
}

double PricingEngine::getBestAsk(const std::string& symbol) const {
    double bestAsk = std::numeric_limits<double>::max();
    for (const auto& order : orderBook.getSellOrders(symbol)) {
        bestAsk = std::min(bestAsk, order.getPrice());
    }
    return (bestAsk == std::numeric_limits<double>::max()) ? 0.0 : bestAsk;
}

double PricingEngine::calculateMidPrice(const std::string& symbol) const {
    double bid = getBestBid(symbol);
    double ask = getBestAsk(symbol);
    if (bid > 0.0 && ask > 0.0) {
        return (bid + ask) / 2.0;
    }
    return 0.0;
}
