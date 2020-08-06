#include "config.h"
#include "utils.h"
#include <fstream>
namespace utils
{
    const std::string config::default_string = "";
    bool config::load_config(const std::string &conf_name)
    {
        std::ifstream file(conf_name,std::ios::in);
        if(!file.is_open())
        {
            return false;
        }

        std::string buffer;
        while(getline(file,buffer))
        {
            if(buffer.empty())
                continue;
            if (buffer[0] == ';' || buffer[0] == ' ' || buffer[0] == '#' || buffer[0] == '\t' || buffer[0] == '\n')
                continue;

            if(*buffer.begin() == 0)
                continue;
            if(*buffer.begin() == '[')
                continue;
            
            auto index = buffer.find_first_of('=');

            if(index != std::string::npos)
            {
                auto k = std::move(buffer.substr(0, index));
                auto v = buffer.substr(index + 1, buffer.length() - 1);
                ;
                _configs.emplace_back(std::make_pair(trim(k), trim(v)));
            }
        }
        file.close();
        return true;
        
    }
    const std::string &config::get_string(const std::string item_name)
    {
        auto  it = std::find_if(_configs.begin(),_configs.end(),
        [&item_name](config_list::value_type& it)
        {
            return item_name == it.first;
        });
        if(it != _configs.end())
        {
            return it->second;
        }
        return default_string;
    }

    int config::get_int_default(const std::string &item_name, int def)
    {
        auto it = std::find_if(_configs.begin(), _configs.end(),
                               [&item_name](config_list::value_type& it) {
                                   return item_name == it.first;
                               });
        if (it != _configs.end())
        {
            return std::atoi(it->second.c_str());
        }
        return def;
    }
}