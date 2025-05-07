#include <iostream>
#include <vector>
#include <chrono>
#include "OrderBook.h"
#include "Order.h"

void runBenchmark(OrderBook& orderBook, int numOrders = 1000) {
    std::vector<Order> orders;

    // Generate BUY and SELL orders alternately
    for (int i = 0; i < numOrders; ++i) {
        std::string id = "ORD" + std::to_string(i);
        double price = 1.1000 + (i % 50) * 0.0001; // Vary price a bit
        int quantity = 100 + (i % 10) * 10;

        OrderType type = (i % 2 == 0) ? OrderType::BUY : OrderType::SELL;
        orders.emplace_back(id, "EUR/USD", price, quantity, type);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& order : orders) {
        orderBook.addOrder(order);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Matched " << numOrders << " orders in " << duration.count() << " microseconds." << std::endl;
}
