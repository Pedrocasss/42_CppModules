#include "replace.hpp"

void    replaceString(std::string& content, const std::string& toFind, const std::string& toReplace)
{
    size_t pos = content.find(toFind);
    
    while(pos != std::string::npos)
    {
        content.erase(pos, toFind.length());
        content.insert(pos, toReplace);
        pos = content.find(toFind, pos + toReplace.length());
    }
}