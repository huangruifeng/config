#ifndef _UTILS_STRING_
#define _UTILS_STRING_
#include<algorithm>
#include <string>

namespace utils
{
    std::string& ltrim(std::string & str)
    {
        str.erase(str.begin(),std::find_if(str.begin(),str.end(), 
                              std::not1(std::ptr_fun(::isspace))));
        return str;
    }

    std::string& rtrim(std::string& str)
    {
        str.erase(std::find_if(str.rbegin(),str.rend(),
                               std::not1(std::ptr_fun(::isspace))).base(),str.end());
        return str;
    } 

    std::string& trim(std::string& str)
    {
        return rtrim(ltrim(str));
    }
}
#endif // !_CUTILS_STRING_
