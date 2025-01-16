#include "WIFI_Manager.h"
#include "config.h"


WIFI_Manager::WIFI_Manager(
    char const* p_portalSSID,
    char const* p_portalPassWord,
    IPAddress p_portalIP,
    IPAddress p_gatewayIP,
    IPAddress p_portalMask,
    uint8_t p_timeout,
    JSONManager* p_JSONManager
    ) : m_portalSSID(p_portalSSID),
        m_portalPassWord(p_portalPassWord),
        m_portalIP(p_portalIP),
        m_gatewayIP(p_gatewayIP),
        m_portalMask(p_portalMask),
        m_customParameters(PARAM_1, PARAM_2, PARAM_3, PARAM_4), // En ajouter autant que besoin!!!
        m_timeout(p_timeout),
        m_debugOutput(false),
        m_JSONManager(p_JSONManager) {
            setupManager();
    }

void WIFI_Manager::setupManager() {

    this->m_WiFiManager.setDebugOutput(this->m_debugOutput);
    this->m_WiFiManager.setAPCallback([](WiFiManager* p_wiFiManager) {
        Serial.println("Échec connexion réseau WIFI. Lancement portail");
    });
    this->m_WiFiManager.setConfigPortalTimeout(this->m_timeout);
    this->m_WiFiManager.setSaveParamsCallback([this] () {
        Serial.println("Sauvegarde de la configuration par l'utilisateur dans le portail.");
        Serial.println(String("Nouvelle valeur du paramètre: ") + this->m_customParameters.getValue()); // En ajouter autant que besoin!!!
        
        StaticJsonDocument<512> jsonDoc;

        jsonDoc["WiFiSSID"] = WiFi.SSID();
        jsonDoc["WiFiPassword"] = WiFi.psk();
        jsonDoc["MQTTServerIP"];
        jsonDoc["MQTTUser"];
        jsonDoc["MQTTPasword"];
        jsonDoc["TemperatureTopic"];
        // jsonDoc["networkIP"] = WiFi.localIP().toString();
        // Ajouter des params autant que besoin!!!

        this->m_JSONManager->write(JSON_FILE_PATH, jsonDoc);

    });
    this->m_WiFiManager.addParameter(&this->m_customParameters);
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

  //  this->m_WiFiManager->autoConnect("abc","abc");     Connecter à MQTT

    Serial.println(WiFi.localIP());
    // this->m_webServer.on(UriRegex("/*"), [this]() {
    //     this->m_webServer.send(200, "text/plain", "Bienvenue sur mon site web!");
    // });
    // if (WiFi.isConnected()) {
    //     this->m_webServer.begin();
    //     Serial.println("connecté au réseau: " + WiFi.SSID());
    //     Serial.println("Adresse IP: " + WiFi.localIP().toString());
    // }   
}
void WIFI_Manager::tick() {
    // if (WiFi.isConnected()) {
    //     this->m_webServer.handleClient();
    // }
}
/***** Pas utilisé pour l'instant *****/
void WIFI_Manager::toggleDebugMode() {
    this->m_debugOutput ?  this->m_WiFiManager.setDebugOutput(false) : this->m_WiFiManager.setDebugOutput(true);
    Serial.println("DebugOutPut: " + this->m_debugOutput);    
}
/**************************************/
void WIFI_Manager::startConfigPortal() {
    Serial.println("Lancement manuel du portail!");
    this->m_WiFiManager.startConfigPortal();
}
void WIFI_Manager::eraseWIFIConfig() {
    Serial.println("erase");
    this->m_WiFiManager.erase();
    Serial.println("Restart");
    delay(2000);
    ESP.restart();
}
