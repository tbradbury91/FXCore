#ifndef PRICEFEED_H
#define PRICEFEED_H

#include <string>
#include <map>

class PriceFeed {
public:
    PriceFeed();

    ~PriceFeed();

    void start();
    void stop();
    void updatePrice(const std::string& symbol, double price);
    double getPrice(const std::string& symbol);
private:
    std::map<std::string, double> priceData;

};

#endif