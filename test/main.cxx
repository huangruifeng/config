
#include"../src/config.h"
#include<iostream>

int main()
{
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