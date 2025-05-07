#include "Logger.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::logInfo(const std::string& message) {
    if (logFile.is_open()) {
        logFile << "[INFO] " << getCurrentTimestamp() << " - " << message << std::endl;
    }
}

void Logger::logError(const std::string& message) {
    if (logFile.is_open()) {
        logFile << "[ERROR] " << getCurrentTimestamp() << " - " << message << std::endl;
    }
}

std::string Logger::getCurrentTimestamp() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    
    std::tm tm_buf;
#ifdef _WIN32
    localtime_s(&tm_buf, &now_c);
#else
    localtime_r(&now_c, &tm_buf);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}