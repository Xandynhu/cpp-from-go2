#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void*  NewStringCollector();
void   DeleteStringCollector(void* sc);

void   StringCollector_Add(void* sc, const char* str);
void   StringCollector_Print(void* sc);

void   FreeString(char* str);

#ifdef __cplusplus
}  // extern "C"
#endif