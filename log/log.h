#ifndef __LOG20200809__
#define __LOG20200809__

#include<string>
#include<fstream>
#include<iostream>

#include "thread_pool.h"

enum log_level
{
    error,
    warnning,
    info,
    debug,

    count
};

class log
{
public:
    log()=default;
    log(log_level level):_level(level),_log_thread(1){_log_thread.run();}
    
    bool init_log (const std::string&path);

    inline void set_log_level(log_level lev)
    {
        _level = lev;
    }

    inline log_level get_log_level() const
    { 
        return _level;
    }

    void close_log()
    {
        if (_log_file.is_open())
            _log_file.close();
    }

    ~log()
    {
        close_log();
    }
    void log_core(log_level,const std::string &log);
    void log_core_thread_safe(log_level, const std::string &log);

private:
    std::ofstream _log_file;
    log_level _level;
    const static char *levels[log_level::count];
    utils::thread_pool _log_thread;
};


#endif