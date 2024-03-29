#include "bridge.h"
#include "string_collector.hpp"

void* NewStringCollector() {
    return new StringCollector();
}

void DeleteStringCollector(void* sc) {
    auto ptr = reinterpret_cast<StringCollector*>(sc);
    delete ptr;
}

void StringCollector_Add(void* sc, const char* str) {
    auto ptr = reinterpret_cast<StringCollector*>(sc);
    ptr->add(str);
}

void StringCollector_Print(void* sc) {
    auto ptr = reinterpret_cast<StringCollector*>(sc);
    ptr->print();
}

void FreeString(char* str) {
    delete[] str;
}