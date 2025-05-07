#include "PriceFeed.h"
#include <iostream>
#include <map>

PriceFeed::PriceFeed() {
    // 
}

PriceFeed::~PriceFeed() {

}

void PriceFeed::start() {
    std::cout << "Starting price feed..." << std::endl;
}
void PriceFeed::stop() {
    std::cout << "Stopping price feed..." << std::endl;

}

void PriceFeed::updatePrice(const std::string& symbol, double price) {
    priceData[symbol] = price;
}

double PriceFeed::getPrice(const std::string& symbol) {
    if (priceData.find(symbol) != priceData.end()) {
        return priceData[symbol];
    }
    return 0.0; // return 0 if the symbol isnt found 

}