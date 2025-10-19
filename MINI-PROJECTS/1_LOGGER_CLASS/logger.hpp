#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <thread>
#include <sstream>
#include <memory>

namespace alin{

class Logger {
public:
    
    enum class LogLevel {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    static Logger& getInstance();
    
    void setLogFile(const std::string& filename);
    void setBufferSize(size_t size);
    void log(LogLevel level, const std::string& message);
private:
    Logger();
    ~Logger();
    
    void flush();
    std::string levelToString(LogLevel level);
    std::string getTimeStamp();
    
    std::mutex loggerMutex_;
    std::ofstream logFile_;
    bool logToFile_;
    std::stringstream logStream_;
    size_t maxBufferSize_;
};

}

#define LOG_DEBUG(msg) alin::Logger::getInstance().log(alin::Logger::LogLevel::DEBUG, msg)
#define LOG_INFO(msg) alin::Logger::getInstance().log(alin::Logger::LogLevel::INFO, msg)
#define LOG_WARNING(msg) alin::Logger::getInstance().log(alin::Logger::LogLevel::WARNING, msg)
#define LOG_ERROR(msg) alin::Logger::getInstance().log(alin::Logger::LogLevel::ERROR, msg)

#endif // LOGGER_HPP