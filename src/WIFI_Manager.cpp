#include "WIFI_Manager.h"

WIFI_Manager::WIFI_Manager(
    char const* p_portalSSID,
    char const* p_portalPassWord,
    IPAddress p_portalIP,
    IPAddress p_gatewayIP,
    IPAddress p_portalMasck,
    WiFiManagerParameter p_custmParameters,
    uint8_t p_timeout
    ) : m_portalSSID(p_portalSSID),
        m_portalPassWord(p_portalPassWord),
        m_portalIP(p_portalIP),
        m_gatewayIP(p_gatewayIP),
        m_portalMask(p_portalMasck),
        m_custmParameters(p_custmParameters),
        m_timeout(p_timeout),
        m_debugOutput(false) {
            setupManager();
    }

void WIFI_Manager::setupManager() {
    this->m_WiFiManager.setDebugOutput(this->m_debugOutput);
    this->m_WiFiManager.setAPCallback([](WiFiManager* p_wiFiManager) {
        Serial.println("Échec connexion réseau WIFI. Lancement portail");
    });
    this->m_WiFiManager.setConfigPortalTimeout(this->m_timeout);
    this->m_WiFiManager.setSaveParamsCallback([&this->m_custmParameters] () {       // voir pour régler l'erreur
        Serial.println("Sauvegarde de la configuration par l'utilisateur dans le portail.");
        Serial.println(String("Nouvelle valeur du paramètre: ") + this->m_custmParameters.getValue());  // raison erreur lambda
        //ajouter sauvegarde dans un .json
    });
    this->m_WiFiManager.addParameter(&this->m_custmParameters);
    this->m_WiFiManager.setAPStaticIPConfig(
        this->m_portalIP,
        this->m_gatewayIP,
        this->m_portalMask
        );
    this->m_WiFiManager.setParamsPage(true);
    this->m_WiFiManager.autoConnect(
        this->m_portalSSID, 
        this->m_portalPassWord
        );
    this->m_webServer.on(UriRegex("/*"), []() {
        this->m_webServer.send(200, "text/plain", "Bienvenue sur mon site web!");       // raison erreur lambda
    });
    if (WiFi.isConnected()) {
        this->m_webServer.begin();
        Serial.println("connecté au réseau: " + WiFi.SSID());
        Serial.println("Adresse IP: " + WiFi.localIP().toString());
    }
}

void WIFI_Manager::tick() {
    if (WiFi.isConnected()) {
        this->m_webServer.handleClient();
    }
}
void WIFI_Manager::toggleDebugMode() {
    this->m_debugOutput ?  this->m_WiFiManager.setDebugOutput(false) : this->m_WiFiManager.setDebugOutput(true);
    Serial.println("DebugOutPut: " + this->m_debugOutput);    
}
void WIFI_Manager::startConfigPortal() {
    Serial.println("Lancement manuel du portail!");
    this->m_WiFiManager.startConfigPortal();
}
void WIFI_Manager::eraseConfig() {
    this->m_WiFiManager.erase();
}
