#pragma once

#include <string>
#include <vector>

class StringCollector {
private:
    std::vector<std::string> m_strings;
    
public:
    StringCollector(){};
    ~StringCollector(){};

    void Add(const std::string& str);
    void Print() const;
    const char* Get();
};