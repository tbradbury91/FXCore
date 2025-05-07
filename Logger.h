#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
public:
    Logger(const std::string& filename = "fxcore.log");
    ~Logger();

    void logInfo(const std::string& message);
    void logError(const std::string& message);

private:
    std::ofstream logFile;
    std::string getCurrentTimestamp() const;
};

#endif
