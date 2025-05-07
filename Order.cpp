#include "Order.h"

Order::Order(const std::string& id, const std::string& symbol, double price, int quantity, OrderType type)
    : id(id), symbol(symbol), price(price), quantity(quantity), type(type) {}

std::string Order::getId() const {
    return id;
}

std::string Order::getSymbol() const {
    return symbol;
}

double Order::getPrice() const {
    return price;
}

int Order::getQuantity() const {
    return quantity;
}

OrderType Order::getType() const {
    return type;
}