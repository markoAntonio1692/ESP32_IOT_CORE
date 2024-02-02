
#define THINGNAME "ESP32_MQTT-MARCO"

// Copy contents from CA1 pem
static const char cacert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Copy contents from XXXXXXXX-certificate.pem.crt here ▼
static const char client_cert[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAPffUb5Q9N+3LKbCX/ZClpoKSyAWMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzAzMTkxNjUz
MjVaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCg9Soe7PCsigxLEzkD
0xwm8ixU1y/n7FllJdDpW/tNqu26IQBgU7rYLpdX/6MIvHzQ5TDMjbpcwSF5TVhx
DeYf5CTl7OukK+L2LMeiO+/iOgpKCClQljcNHCeoXj2QjE/YJODm/EuURktYHtts
qjDqkxEJf5RRaTUpbJs/ryQ/T/ZL9NBHzjqFXh2IH7kGpcFmP6XuamY/N7K5fdOm
wREFKPmVvJOE2DDjtktevdn8EZJv0vxNbuYL8wbSe/WgdnBp/iJua1kT0AS//dG5
g6siKrTIJspdDVBjUHJPEze85+pyCt0WgDtJNjBxYcjyR2Xa/VBEQ1DxW6Z91RaZ
/Pb/AgMBAAGjYDBeMB8GA1UdIwQYMBaAFP4I6atbNDi2D4Z1Elzz+T1SRE8xMB0G
A1UdDgQWBBRA58dkBnR4LOo1S/3pUuwfN2kOHDAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAHB/nv95c4UwWpZ8fJ8Tf2xDU
anS4tq8Pk7Mj2TjQo9644MrdlYc7+RjYmwvSKGGB9AqXvbE9JAYYLUpGeGsxuD3I
ycNiMR7FIbQ2X98WdkRy1hQfuZxn4w5uEQz1UVPuyrnRQV0dDfYid4GzU2m28oe7
BEqf6TnDTDTAGvaxxle9/RWE6kwh7Ce57YnlLP3+8K3XJNdvJ/SSzJ4hXTdBwQjX
VNqnTtZMpCom2exmdPB9UcQCAI10GEw11ULX+gn5/xjx72eUgm98nxRRhWd956wV
60F0XzBf2Z5PjykvdMUC3URKdirWy2JNOsMbxphnwuMlh0FPGyzmPDMd3d1VOQ==
-----END CERTIFICATE-----
)KEY";

// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEAoPUqHuzwrIoMSxM5A9McJvIsVNcv5+xZZSXQ6Vv7TartuiEA
YFO62C6XV/+jCLx80OUwzI26XMEheU1YcQ3mH+Qk5ezrpCvi9izHojvv4joKSggp
UJY3DRwnqF49kIxP2CTg5vxLlEZLWB7bbKow6pMRCX+UUWk1KWybP68kP0/2S/TQ
R846hV4diB+5BqXBZj+l7mpmPzeyuX3TpsERBSj5lbyThNgw47ZLXr3Z/BGSb9L8
TW7mC/MG0nv1oHZwaf4ibmtZE9AEv/3RuYOrIiq0yCbKXQ1QY1ByTxM3vOfqcgrd
FoA7STYwcWHI8kdl2v1QRENQ8VumfdUWmfz2/wIDAQABAoIBAQCOEPaVh0LCt7I0
DYp0YsBla7lPRQPGq+kXivJDFunP2r+rWnePjjfLmgwBIuTO0DdG1hRlZ+8G8XxP
KcKXPtJQcblTq/Ms24OfD1VBT6/iuKHeSCfXNk7u5lvmkw+55u6Oc7aCiktXW1gj
NlEsL2evlBEklhPea4L9xhudcUQIEHA1zjwxzaJD0gIasN0Js0TLV1WsRwjNyDoZ
/AvCU+rKBYxFMx7LVK7iXP2ZJd62jmkog71WeTe3uCY1zdYWuWxrfmw5nDghhbyH
B04p4P0La8kv+EZ0qekfzIkAVCUEZaXU2zwLflsGXQ/NVySv0r8ZXdYcvE18rc12
XJl9d6yxAoGBANSj1ejFdOQ063tuk/kKVg3gAoV00h7S6HE1u3Q9Jeiuk2VK+IGY
ZfIWu1nzU4QCH0spmj0eC7K9c812nClzYeveO4fpX7kaLkfNIpHlkWoaF4BBDF0u
9XPaJcgBSlsBTqv2lTB67THXNeIzz/+/TGJ1GywFwvN7zfPdxLOMk07nAoGBAMHH
bPM8pW5UgB0teF3u+J27/eXghvcyPatEs88iug6GGuicLquCIubfTYi9Yne7rEZ0
tXYhZUnYujWDYs0CkwBYHAUjHiSRXoM/mzWyZR8QJwwGipVFosl8G7CZAZjfU//z
UGOKu6zRfg8Thr1NoBEu6//vD0j6Pb1Mkwyx6YwpAoGBAJAFN4ik1HsMbMH5Lzfq
DEbxhkOlz/sYll63KfOcxuRF+YcNtCrycXn6c4KFD/fFCDT8RH9IrlutfZWX1EUu
5Q/AQUnYgwD3/oibI+L1PfxDF8/CPwGOIKkLA7PnS9k/lW1bYcioOaccQF6pASQT
CUVWU8UJUfVf0Spu9h82Az/ZAoGAIoYBJyS65HkxigE73KBistd3WKkz4n6U9hp7
Xn/1XfkOejq5Jd09kpxeF+qFzIcnHjZUzgMNJKb0JeyOga/fuMP52gBzslgj2oZO
hLaPxYT/L+lKb2XEptjxpfjci/vd30/eFp306ck5CD6WVsuppOYTLbnNo1bSARPP
bweTcGECgYEAx60z7IoUqnlnAos06/L+6nlgoTmdv3dJdYFFK8fC6QMq/9xxWsiP
7dJ+qXwq6iPWG7EjdyUwM1rd/uteAb01mbC5uN10xV2uVlAj/KRBl5kW3FAl0wPb
0W3cupiGBM7uHhugt7BjkkBbSu9MQciaHg8JAFJoFq818Yju6f1QKGI=
-----END RSA PRIVATE KEY-----
)KEY";


/////////////////////////////////////////////////////////////////////////


#include "SPIFFS.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT.h>  // library for getting data from DHT
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson (use v6.xx)


// Enter your WiFi ssid and password
const char* ssid = "marcou"; //Provide your SSID
const char* password = "12345678"; // Provide Password
///////////////////////////////////////////////////////////
const char* mqtt_server = "a2cwbdq08ub58x-ats.iot.us-east-2.amazonaws.com"; // Relace with your MQTT END point
const int   mqtt_port = 8883;
String MQTT_PUB_TOPIC;
String MQTT_SUB_TOPIC;
////////////////////////////////////////

long FrecData_Seg =5; //frecuencia de envio de datos
long chipID;
String Read_rootca;
String Read_cert;
String Read_privatekey;
#define BUFFER_LEN 256
long lastMsg = 0;
char msg[BUFFER_LEN];
int Value = 0;
byte mac[6];
char mac_Id[18];

WiFiClientSecure espClient;
PubSubClient client(espClient);



#define DHTPIN 4        //pin where the DHT22 is connected 
DHT dht(DHTPIN, DHT11);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  String str_topic = String(topic);
  String str_payload ="";
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    str_payload += (char)payload[i];  //concatenar contenido de mensaje en string
  }
  Serial.println();
// String input;

StaticJsonDocument<64> doc;
DeserializationError error = deserializeJson(doc, str_payload );
if (error) {
  Serial.print(F("deserializeJson() failed: "));
  Serial.println(error.f_str());
  return;
}
FrecData_Seg = doc["FrecData_Seg"]; // 1

}
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
//    String clientId = "ESP32-";
//    clientId += String(random(0xffff), HEX);
//    // Attempt to connect

    if (client.connect(String(chipID).c_str() )) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      // ... and resubscribe
      client.subscribe(MQTT_SUB_TOPIC.c_str());
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  setup_wifi();
  delay(1000);
  
  
  //Root CA File Reading. 
    Read_rootca = cacert;
    //Serial.println(Read_rootca);
    Read_cert =  client_cert;
    Read_privatekey = privkey;
  
  char* pRead_rootca;
  pRead_rootca = (char *)malloc(sizeof(char) * (Read_rootca.length() + 1));
  strcpy(pRead_rootca, Read_rootca.c_str());

  char* pRead_cert;
  pRead_cert = (char *)malloc(sizeof(char) * (Read_cert.length() + 1));
  strcpy(pRead_cert, Read_cert.c_str());

  char* pRead_privatekey;
  pRead_privatekey = (char *)malloc(sizeof(char) * (Read_privatekey.length() + 1));
  strcpy(pRead_privatekey, Read_privatekey.c_str());

  Serial.println("================================================================================================");
  Serial.println("Certificates that passing to espClient Method");
  Serial.println();
  Serial.println("Root CA:");
  Serial.write(pRead_rootca);
  Serial.println("================================================================================================");
  Serial.println();
  Serial.println("Cert:");
  Serial.write(pRead_cert);
  Serial.println("================================================================================================");
  Serial.println();
  Serial.println("privateKey:");
  Serial.write(pRead_privatekey);
  Serial.println("================================================================================================");

  espClient.setCACert(pRead_rootca);
  espClient.setCertificate(pRead_cert);
  espClient.setPrivateKey(pRead_privatekey);

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  //====================================================================================================================
  WiFi.macAddress(mac);
  snprintf(mac_Id, sizeof(mac_Id), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  Serial.print(mac_Id);
  //=====================================================================================================================

chipID = ESP.getEfuseMac();

MQTT_PUB_TOPIC = String(chipID) + "/out";
MQTT_SUB_TOPIC = String(chipID) + "/in";

Serial.println("");
Serial.println("");
Serial.print(" ID: "); Serial.println(chipID);
Serial.print(" TOPIC PUB: "); Serial.println(MQTT_PUB_TOPIC);
Serial.print(" TOPIC SUB: "); Serial.print(MQTT_SUB_TOPIC);
Serial.println("");
Serial.println("");

  delay(2000);

}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > FrecData_Seg*1000L) {
     lastMsg = now;

     StaticJsonDocument<128> doc;
     doc["ID"] = chipID;
     doc["Temp_C"] = random(20,25);
     doc["Hum_%"] = random(28,90);
     doc["CO2_ppm"] = random(1800,2000);
     doc["NH3_ppm"] = random(300,342);

    String output;
    serializeJson(doc, output);
    Serial.println(output);    
    client.publish(MQTT_PUB_TOPIC.c_str(), output.c_str());
  }

}
