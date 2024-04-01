#include "string_collector.hpp"
#include "string_collector_impl.hpp"

void StringCollector::Add(const std::string& str) {
    m_strings.push_back(str);
}

void StringCollector::Print() const {
    for (const auto& str : m_strings) {
        std::cout << str << std::endl;
    }
}

const char* StringCollector::Get() {
    auto sci = new StringCollectorImpl();
    std::string result = "empty string";

    for (const auto& str : m_strings) {
        sci->add(str);
    }
    result = sci->get();

    char* c_result = new char[result.size() + 1];
    std::copy(result.begin(), result.end(), c_result);
    c_result[result.size()] = '\0';

    delete sci;
    return c_result;
}