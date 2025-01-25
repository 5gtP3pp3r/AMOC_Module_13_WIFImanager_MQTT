#pragma once
#include <ArduinoJson.h>
#include <LittleFS.h>

class JSONManager {
private:
    bool exists(const char* p_filePath);
public:
    JSONManager();    
    void write(const char* p_filePath, const JsonDocument& p_doc);
    JsonDocument read(const char* p_filePath);
    void remove(const char* p_filePath);  
};