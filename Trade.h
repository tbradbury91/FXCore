#ifndef TRADE_H
#define TRADE_H

#include <string>

class Trade {
public:
    Trade(const std::string& tradeId,
          const std::string& symbol,
          double price,
          int quantity);

    std::string getTradeId() const;
    std::string getSymbol() const;
    double getPrice() const;
    int getQuantity() const;

private:
    std::string tradeId;
    std::string symbol;
    double price;
    int quantity;
};

#endif
