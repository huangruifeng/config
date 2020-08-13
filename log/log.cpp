#include"log.h"
#include<sstream>
#include<chrono>
#include<thread>

#include<vector>
#include<climits>
#include<functional>
#include<mutex>

const char *log::levels[] = {
    "[  error ]",
    "[warnning]",
    "[  info  ]",
    "[  debug ]",
};

std::string GetCurrentSystemTime()
{
    auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm *pTimeNow = localtime(&timeNow);
    char szDate[60] = {0};
    sprintf(szDate, "%d-%02d-%02d %02d:%02d:%02d",
            (int)pTimeNow->tm_year + 1900, (int)pTimeNow->tm_mon + 1, (int)pTimeNow->tm_mday,
            (int)pTimeNow->tm_hour, (int)pTimeNow->tm_min, (int)pTimeNow->tm_sec);

    return std::string(szDate);
}

bool log::init_log(const std::string& path)
{
    if(path.empty())
        return false;
    
    _log_file.open(path,std::ios::out |std::ios::app);
    if(!_log_file.is_open())
    {
        return false;
    }
    return true;
}

void log::log_core(log_level level,const std::string &log)
{
    if (level > _level)
        return;
    std::ostringstream logmessage;
    logmessage << levels[level];
    logmessage<<GetCurrentSystemTime();
    logmessage<<"["<<std::this_thread::get_id()<<"]";
    logmessage<<log<<" ";
    logmessage<<__FILE__<<" "<<__LINE__<<std::endl;
    auto message = logmessage.str();
    if(_log_file.is_open())
    {
        _log_file.write(message.c_str(), message.size());
    }else
    {
        std::cout.write(message.c_str(),message.size());
    }
    
}

void log::log_core_thread_safe(log_level level, const std::string &log)
{
    if (level > _level)
        return;
    std::ostringstream logmessage;
    logmessage << levels[level];
    logmessage << GetCurrentSystemTime();
    logmessage << "[" << std::this_thread::get_id() << "]";
    logmessage << log << " ";
    logmessage << __FILE__ << " " << __LINE__ << std::endl;
    auto message = logmessage.str();

    _log_thread.push([message,this] {
        if (_log_file.is_open())
        {
            _log_file.write(message.c_str(), message.size());
        }
        else
        {
            std::cout.write(message.c_str(), message.size());
        }
    });
}