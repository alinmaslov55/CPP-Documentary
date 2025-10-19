#include "logger.hpp"

#include <exception>

namespace alin {

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::setLogFile(const std::string& filename){
    std::lock_guard<std::mutex> lock(loggerMutex_);
    flush();

    if(logFile_.is_open()){
        logFile_.close();
    }

    if(filename.empty()){
        logToFile_ = false;
    } else {
        logFile_.open(filename, std::ios::app);
        logToFile_ = logFile_.is_open();
        if(!logFile_){
            throw std::runtime_error("Failed to open log file: " + filename);
        }
    }
}

void Logger::setBufferSize(size_t size){
    std::lock_guard<std::mutex> lock(loggerMutex_);
    maxBufferSize_ = size;
}

void Logger::log(LogLevel level, const std::string& message){
    std::lock_guard<std::mutex> lock(loggerMutex_);

    logStream_ << "[" << getTimeStamp() << "] "
               << "[" << levelToString(level) << "] "
               << "[Thread " << std::this_thread::get_id() << "] "
               << message << std::endl;

    if(static_cast<size_t>(logStream_.tellp()) >= maxBufferSize_){
        flush();
    }
}

Logger::Logger()
    : logToFile_(false), maxBufferSize_(1024) // Default buffer size 1KB
{}

Logger::~Logger(){
    std::lock_guard<std::mutex> lock(loggerMutex_);
    flush();
    if(logFile_.is_open()){
        logFile_.close();
    }
}

void Logger::flush(){
    if(logStream_.str().empty()){
        return;
    }

    std::ostream& output = logToFile_ ? logFile_ : std::cout;
    output << logStream_.str();
    output.flush();
    logStream_.str("");
    logStream_.clear();
}

std::string Logger::levelToString(LogLevel level){
    switch(level){
        case LogLevel::DEBUG:   return "DEBUG";
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR:   return "ERROR";
        default:                return "UNKNOWN";
    }
}

std::string Logger::getTimeStamp(){
    auto now  = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;

    #ifdef _WIN32
        std::tm timeinfo;
        localtime_s(&timeinfo, &in_time_t);
        ss << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");
    #else
        std::tm* timeinfo = std::localtime(&in_time_t);
        localtime_r(&in_time_t, timeinfo);
        ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    #endif

    ss << '.' << std::setfill('0') << std::setw(3) << 
        std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()
        ).count() % 1000;
    return ss.str();
}

} // namespace alin