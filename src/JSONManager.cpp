#include "JSONManager.h"

JSONManager::JSONManager() { 
    LittleFS.begin(true);
}

bool JSONManager::exists(const char *p_filePath) {
    return LittleFS.exists(p_filePath);
}

void JSONManager::write(const char *p_filePath, const JsonDocument &p_doc) {

    File file = LittleFS.open(p_filePath, FILE_WRITE);
    if (!file) {
        Serial.println(String("Erreur : Impossible d'ouvrir le fichier pour écrire: ") + p_filePath);
        return;
    }

    if (serializeJson(p_doc, file) == 0) {
        Serial.println("Erreur : Échec de l'écriture dans le fichier!");
        file.close();
        return;
    } 

    file.close();
    Serial.println(String("Fichier écrit avec succès: ") + p_filePath);
      
}

void JSONManager::read(const char *p_filePath, JsonDocument &p_doc) {

    if (!exists(p_filePath)) {
        Serial.println("Erreur : Le fichier n'existe pas!");
        return;
    }

    File file = LittleFS.open(p_filePath, FILE_READ);
    if (!file) {
        Serial.println(String("Erreur : Impossible d'ouvrir le fichier pour lecture: ") + p_filePath);
        return;
    }

    DeserializationError error = deserializeJson(p_doc, file);
    file.close();
    if (error) {
        Serial.println(String("Erreur : Échec de la désérialisation JSON: ") + error.c_str());
        return;
    } 

    Serial.println(String("Fichier lu avec succès: ") + p_filePath);  
}

void JSONManager::remove(const char *p_filePath) {

    if (!exists(p_filePath)) {
        Serial.println(String("Erreur : Le fichier n'existe pas: ") + p_filePath);
        return;
    }
    if (!LittleFS.remove(p_filePath)) {
        Serial.println(String("Erreur : Échec de la suppression du fichier: ")+ p_filePath);
        return;
    } 

    Serial.println(String("Fichier supprimé avec succès: ") + p_filePath);
}
