#ifndef _CONFIG_20200802_
#define _CONFIG_20200802_
#include <list>
#include <string>

namespace utils
{
    class config
    {
    public:
        static const std::string default_string;
        bool load_config(const std::string& conf_name);
        const std::string& get_string(const std::string item_name);
        int get_int_default(const std::string& item_name,int def);
    private:
        using config_list = std::list<std::pair<std::string, std::string>>;
        config_list _configs;
    };
}
#endif //_CONFIG20200802_