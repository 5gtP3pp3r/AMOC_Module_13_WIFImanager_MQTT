#include "MQTT_Service.h"

MQTT_Service::MQTT_Service()
  : 
    m_espClient(nullptr),
    m_pubSubClient(nullptr) {
        setupMQTT();
    }

void MQTT_Service::setupMQTT() {
    m_espClient = new WiFiClient();
    m_pubSubClient = new PubSubClient(*m_espClient);
    m_pubSubClient->setBufferSize(1024);
    m_pubSubClient->setServer(MQTT_SERVER, MQTT_PORT);
    m_espUnique = String("ESP32Client") + String(ESP.getEfuseMac(), HEX);
    m_lastSentMessageTime = DEFAULT_ZERO;
    m_interval = INTERVAL_5;
}

bool MQTT_Service::reconnectMQTTIfNeeded() {
    if (!m_pubSubClient->connected()) {
        if(m_pubSubClient->connect(m_espUnique.c_str(), MQTT_USER, MQTT_PASSWORD,
                                  (m_espUnique + "/status").c_str(), 0, 0,"offline")) {
            Serial.println("Connecté au broker MQTT");
            m_pubSubClient->publish((m_espUnique + "/status").c_str(), "online");
            m_pubSubClient->subscribe("broadcat/#");
            m_pubSubClient->setCallback(
                [](char*topic, byte*payload, uint16_t length) {
                     Serial.print("Message reçu...");
                });
        } else {
             Serial.print("Echec de connexion au broker MQTT : ");
        }
    }
    return m_pubSubClient->connected();
}

void MQTT_Service::continuousMessageSending() {
    uint64_t messageId = DEFAULT_ZERO;
    if (reconnectMQTTIfNeeded()) {
        m_pubSubClient->loop();
        if (m_lastSentMessageTime + m_interval < millis()) {
            m_lastSentMessageTime = millis();
            String topic = m_espUnique + "/data";
            String payload = String("Hello World! -") + String(messageId++);
            m_pubSubClient->publish(topic.c_str(), payload.c_str());
        }
    }
}

void MQTT_Service::tick() {
    continuousMessageSending();
}
