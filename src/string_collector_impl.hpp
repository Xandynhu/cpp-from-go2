#pragma once

#include <string>
#include <vector>
#include <iostream>

class StringCollectorImpl {
private:
    std::vector<std::string> m_strings;

public:
    StringCollectorImpl(){};
    ~StringCollectorImpl(){};

    void add(const std::string& str);
    void print() const;
    std::string get();
};