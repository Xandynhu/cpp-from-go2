#include "bridge.hpp"
#include "src/string_collector.hpp"

void* NewStringCollector() {
    return new StringCollector();
}

void DeleteStringCollector(void* sc) {
    auto ptr = reinterpret_cast<StringCollector*>(sc);
    delete ptr;
}

void StringCollector_Add(void* sc, const char* str) {
    auto ptr = reinterpret_cast<StringCollector*>(sc);
    ptr->Add(str);
}

void StringCollector_Print(void* sc) {
    auto ptr = reinterpret_cast<StringCollector*>(sc);
    ptr->Print();
}

const char* StringCollector_Get(void* sc) {
    auto ptr = reinterpret_cast<StringCollector*>(sc);
    return ptr->Get();;
}

void FreeString(char* str) {
    delete[] str;
}