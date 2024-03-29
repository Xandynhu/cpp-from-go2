#pragma once

#include <string>
#include <vector>
#include <iostream>

class StringCollector {
private:
    std::vector<std::string> m_strings;

public:
    StringCollector(){};
    ~StringCollector(){};

    void add(const std::string& str);
    void print() const;
};