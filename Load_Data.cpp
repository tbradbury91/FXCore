#include "Load_Data.h"
#include "FXOption.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<FXOption> loadFXOptions(const std::string& filename) {
    std::vector<FXOption> options;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return options;
    }

    bool isHeader = true;
    while (std::getline(file, line)) {
        if (isHeader) {
            isHeader = false;
            continue; // Skip header row
        }

        std::istringstream ss(line);
        std::string spotStr, strikeStr, volStr, rateStr, ttmStr, typeStr, expiryStr;

        std::getline(ss, spotStr, ',');
        std::getline(ss, strikeStr, ',');
        std::getline(ss, volStr, ',');
        std::getline(ss, rateStr, ',');
        std::getline(ss, ttmStr, ',');
        std::getline(ss, typeStr, ',');
        std::getline(ss, expiryStr, ',');

        try {
            double spot = std::stod(spotStr);
            double strike = std::stod(strikeStr);
            double vol = std::stod(volStr);
            double rate = std::stod(rateStr);
            int ttm = std::stoi(ttmStr);
            OptionType optionType = (typeStr == "Call") ? OptionType::CALL : OptionType::PUT;

            FXOption option("EUR/USD", strike, vol, rate, ttm, optionType, expiryStr);
            options.push_back(option);
        } catch (const std::exception& e) {
            std::cerr << "Invalid data on line: " << line << "\nError: " << e.what() << std::endl;
            continue;
        }
    }

    return options;
}