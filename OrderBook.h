#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <vector>
#include <string>
#include "Order.h"
#include "Trade.h"
#include <vector>

class OrderBook {
public:
    void addOrder(const Order& order);
    void matchOrders(const std::string& symbol);
    std::vector<Order> getBuyOrders(const std::string& symbol) const;
    std::vector<Order> getSellOrders(const std::string& symbol) const;
    std::vector<Trade> getTradeHistory() const;

private:
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;
    std::vector<Trade> tradeHistory;
};

#endif