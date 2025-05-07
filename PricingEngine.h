#ifndef PRICINGENGINE_H
#define PRICINGENGINE_H

#include "PriceFeed.h"
#include "OrderBook.h"

class PricingEngine {

public:
    void calculatePricing();

    PricingEngine(PriceFeed& priceFeed, OrderBook& orderBook);

    double calculateMidPrice(const std::string& symbol) const;
    double getBestBid(const std::string& symbol) const;
    double getBestAsk(const std::string& symbol) const;

private:
    PriceFeed& priceFeed;
    OrderBook& orderBook;
};

#endif
