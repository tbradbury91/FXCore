#include <iostream>
#include "PriceFeed.h"
#include "OrderBook.h"
#include "PricingEngine.h"
#include "Logger.h"
#include "Trade.h"
#include "Load_Data.cpp"
#include "PerformanceBenchmark.cpp"
#include "Load_Data.h"

int main() {
    std::cout << "Starting program...\n";

    // sreate instances of the components
    PriceFeed priceFeed;
    OrderBook orderBook;
    PricingEngine pricingEngine(priceFeed, orderBook);

    // start the price feed (simulate receiving data)
    std::cout << "Starting price feed...\n";
    priceFeed.start();

    // FX data
    std::cout << "Loading FX options...\n";
    std::vector<FXOption> options = loadFXOptions("synthetic_data/data_samples/synthetic_fx_data.csv");

    // add some test orders 
    std::cout << "Adding orders...\n";
    Order buyOrder("O001", "EUR/USD", 1.1200, 1000, OrderType::BUY);
    Order sellOrder("O002", "EUR/USD", 1.1210, 500, OrderType::SELL);
    orderBook.addOrder(buyOrder);
    orderBook.addOrder(sellOrder);

    // print the trade history (if any) after orders are matched
    std::cout << "Printing trade history...\n";
    std::vector<Trade> trades = orderBook.getTradeHistory();
    for (const auto& trade : trades) {
        std::cout << "Trade ID: " << trade.getTradeId() << ", Symbol: " << trade.getSymbol()
          << ", Price: " << trade.getPrice() << ", Quantity: " << trade.getQuantity() << std::endl;
    }

    // perform pricing (based on matched orders)
    std::cout << "Performing pricing...\n";
    pricingEngine.calculatePricing();

    // stop the price feed
    std::cout << "Stopping price feed...\n";
    priceFeed.stop();

    runBenchmark(orderBook, 1000);

    return 0;
}