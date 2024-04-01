#include "string_collector_impl.hpp"

void StringCollectorImpl::add(const std::string& str) {
    m_strings.push_back(str);
}

void StringCollectorImpl::print() const {
    for (const auto& str : m_strings) {
        std::cout << str << std::endl;
    }
}

std::string StringCollectorImpl::get() {
    std::string result;
    for (const auto& str : m_strings) {
        result += " " + str;
    }
    return result;
}