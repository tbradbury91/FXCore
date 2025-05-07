#include "OrderBook.h"
#include "Trade.h"

#include <algorithm>

void OrderBook::addOrder(const Order& order) {
    if (order.getType() == OrderType::BUY) {
        buyOrders.push_back(order);
    } else {
        sellOrders.push_back(order);
    }

    matchOrders(order.getSymbol());
}

std::vector<Order> OrderBook::getBuyOrders(const std::string& symbol) const {
    std::vector<Order> result;
    for (const auto& order : buyOrders) {
        if (order.getSymbol() == symbol) {
            result.push_back(order);
        }
    }
    return result;
}

std::vector<Order> OrderBook::getSellOrders(const std::string& symbol) const {
    std::vector<Order> result;
    for (const auto& order : sellOrders) {
        if (order.getSymbol() == symbol) {
            result.push_back(order);
        }
    }
    return result;
}

std::vector<Trade> OrderBook::getTradeHistory() const {
    return tradeHistory;
}

void OrderBook::matchOrders(const std::string& symbol) {
    auto buyIt = buyOrders.begin();
    while (buyIt != buyOrders.end()) {
        if (buyIt->getSymbol() != symbol) {
            ++buyIt;
            continue;
        }

        auto sellIt = sellOrders.begin();
        while (sellIt != sellOrders.end()) {
            if (sellIt->getSymbol() != symbol) {
                ++sellIt;
                continue;
            }

            if (buyIt->getPrice() >= sellIt->getPrice()) {
                int matchedQuantity = std::min(buyIt->getQuantity(), sellIt->getQuantity());
                double matchedPrice = sellIt->getPrice(); 

                Trade executedTrade("T123", symbol, matchedPrice, matchedQuantity);
                tradeHistory.push_back(executedTrade);

                if (buyIt->getQuantity() > matchedQuantity) {
                    *buyIt = Order(buyIt->getId(), symbol, buyIt->getPrice(), buyIt->getQuantity() - matchedQuantity, buyIt->getType());
                } else {
                    buyIt = buyOrders.erase(buyIt);
                }

                if (sellIt->getQuantity() > matchedQuantity) {
                    *sellIt = Order(sellIt->getId(), symbol, sellIt->getPrice(), sellIt->getQuantity() - matchedQuantity, sellIt->getType());
                } else {
                    sellIt = sellOrders.erase(sellIt);
                }

                break; 
            } else {
                ++sellIt;
            }
        }

        if (sellIt == sellOrders.end()) {
            ++buyIt;
        }
    }
}