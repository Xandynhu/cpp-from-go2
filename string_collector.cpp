#include "string_collector.hpp"

void StringCollector::add(const std::string& str) {
    m_strings.push_back(str);
}

void StringCollector::print() const {
    for (const auto& str : m_strings) {
        std::cout << str << std::endl;
    }
}