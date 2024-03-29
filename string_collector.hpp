#include <string>
#include <vector>
#include <iostream>

class StringCollector {
private:
    std::vector<std::string> m_strings;

public:
    void add(const std::string& str) {
        m_strings.push_back(str);
    }

    void print() const {
        for (const auto& str : m_strings) {
            std::cout << str << std::endl;
        }
    }

    void clear() {
        m_strings.clear();
    }

    int size() const {
        return m_strings.size();
    }

};