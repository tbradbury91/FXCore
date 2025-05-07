#include "Trade.h"

Trade::Trade(const std::string& tradeId,
             const std::string& symbol,
             double price,
             int quantity)
    : tradeId(tradeId), symbol(symbol), price(price), quantity(quantity) {}

std::string Trade::getTradeId() const {
    return tradeId;
}

std::string Trade::getSymbol() const {
    return symbol;
}

double Trade::getPrice() const {
    return price;
}

int Trade::getQuantity() const {
    return quantity;
}