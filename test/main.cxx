
#include"../src/config.h"
#include<iostream>
#include "../log/log.h"
#include<future>
#include<chrono>
void log_test()
{
    log ss(debug);
    ss.init_log("./a.log");
    ss.log_core(debug,"hahahha");
    ss.log_core(info,"2222222");
    ss.log_core(warnning,"333333");
}

void log_test_thread(log& l)
{
    std::thread ([&l] {
            int i = 10;
            do
            {
                l.log_core(debug, "hahahha");
                l.log_core(info, "2222222");
                l.log_core(warnning, "333333");
                l.log_core(warnning, "4444444");
                l.log_core(info, "555555555");
                l.log_core(info, "666666666666");
                i--;
            } while (i >= 0);
        }).detach();

}

void thread_test()
{
    log* ss = new log(debug);
    ss->init_log("a.log");
    for(int i = 0;i<40;i++)
    {
        log_test_thread(*ss);
    }
    std::this_thread::sleep_for(std::chrono::seconds(20));
    delete ss;
}

int main()
{
    thread_test();
    
        //log_test();
    return 0;
    utils::config config;
    auto result = config.load_config("./text.conf");
    if(result)
    {
        std::cout << config.get_string("age1") << std::endl;
        std::cout << config.get_string("age2") << std::endl;
        std::cout << config.get_string("age3") << std::endl;
        std::cout << config.get_string("age4") << std::endl;
        std::cout << config.get_string("age5") << std::endl;
        std::cout << config.get_int_default("age1", 0) << std::endl;
        std::cout << config.get_int_default("age2", 0) << std::endl;
        std::cout << config.get_int_default("age3", 0) << std::endl;
        std::cout << config.get_int_default("age4", 0) << std::endl;
        std::cout << config.get_int_default("age5", 0) << std::endl;
        std::cout<<"end"<<std::endl;
    }

    return 0;
}