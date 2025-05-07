#ifndef ORDER_H
#define ORDER_H

#include <string>

enum class OrderType {
    BUY,
    SELL
};

class Order {
public:
    Order(const std::string& id, const std::string& symbol, double price, int quantity, OrderType type);

    std::string getId() const;
    std::string getSymbol() const;
    double getPrice() const;
    int getQuantity() const;
    OrderType getType() const;

private:
    std::string id;
    std::string symbol;
    double price;
    int quantity;
    OrderType type;
};

#endif