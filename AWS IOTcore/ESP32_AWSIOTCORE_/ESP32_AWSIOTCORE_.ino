
#define THINGNAME "ESP32_MQTT-WALTER"

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
MIIDWTCCAkGgAwIBAgIUNX7OP3iQYkcnzKI4oudI8xXQSP0wDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMTExOTE2MzAz
MVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALlmS0Zw57af1s8j37VN
JeHL866i+9Yl3+U9GnjLj85DkuhQNtvkc7RsGGZrA8fC0ho9T4b+IecFW6ei5tHe
Qejp43JqgWWVAqYIX81PCfV+rAGeUfNBnarLSiUnxqHgO8JslN1Im42pco2eE+nj
gftHj7l+zdMLvpl26DxTZTQ06zmUHUYqCn5kcxOxjcwpjbsmJ4qAGooMp9YIGvNg
Xj9oDgy9w3IyVEl0RP+hfyhid2AzA4M1SzdIg6ZxmEIAaHesp5tDOLE/GEp4FrXi
W++d9QhI+N5ycEJi8LoxyxdrZHOQuLtvOY1TPZcFJeHg3BXEbsDgft9eEl6PmXgQ
+QUCAwEAAaNgMF4wHwYDVR0jBBgwFoAU3evB6J9WdZOZdRP8vIpfUaeN7lkwHQYD
VR0OBBYEFNISGjUxOdFLcyASqv57grT1gGNtMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQCYG86L7G/fQFaPPkeqv7h69gHq
JGkb0v2FABTI2+QpkMI2iGT5On/R8BRkMg3n2yvFCiuxWx2rPBCuWZKmj3IqPG6W
/w2z9FquxK2dDg+B4s45zJTCgPqwxjKn9trQmKRST7+ZmhBb8SGVP1CRa+WX8uFw
n6W0S0OperELgu/5KJvk8uht/ZELnOwJ633EWFMzcB+P0pZI+mTA9Ce+4oExLWjK
90Ht13hYckQAm0l89sbgFoU4vO936Kcy7tZvGLZFHhllE3W8fnZaZpRdVfxdkcu5
G0hsvWuuunKRTSNjo9979RDP22Gax/r4oQ75MPvTLpzUfzYnXEskKaT8nWCr
-----END CERTIFICATE-----
)KEY";

// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAuWZLRnDntp/WzyPftU0l4cvzrqL71iXf5T0aeMuPzkOS6FA2
2+RztGwYZmsDx8LSGj1Phv4h5wVbp6Lm0d5B6OnjcmqBZZUCpghfzU8J9X6sAZ5R
80GdqstKJSfGoeA7wmyU3UibjalyjZ4T6eOB+0ePuX7N0wu+mXboPFNlNDTrOZQd
RioKfmRzE7GNzCmNuyYnioAaigyn1gga82BeP2gODL3DcjJUSXRE/6F/KGJ3YDMD
gzVLN0iDpnGYQgBod6ynm0M4sT8YSngWteJb7531CEj43nJwQmLwujHLF2tkc5C4
u285jVM9lwUl4eDcFcRuwOB+314SXo+ZeBD5BQIDAQABAoIBAQCNXsAlfXBipC0T
FCLAR4yMSY2N67+mgojgbyBhXa9RM9uwg4HhWKkVuZs9dXqTdy3oTjn3EI9fbol+
IUxqWVTeuoHxu97hS6eSXS5YCl3osWeNcGDC4ZTNKGhoPpVK2AYZcdxtg7EBa2Tr
Mc+zeASkS+P/KP7fX8Q9lxrs7RZtoGKz+Rb92U4gU6e7V/MAlCbwfOHd8lV33FRl
xqFh020j9ByvsnUa4bzERfpBKuMx8zMatTwJ/oznR7w6GcjgH1eH2nWbARS8VQP1
fY7M7tenOSHReR7Bu2gYagVzJTT6v/kxrBmnfoELsMlXeivUkyLh0blGd6uPlGyr
tJH7plZdAoGBAO/78HfnAjMhX34hsQw8AQcAsWLaaeLRgiyWGCRzKfgjHJgKJMMO
G1CD8tQpfsKOhu0GzXzbqihUPuSvH40hRQHJh4qCryYA1qLfvKpzeQNqs4A7+S87
ffJzYWrgKtGDCVR4CMQnC+n5Pm3eoQDDsNPHvvLNbMbK1f12X90n3e7HAoGBAMXF
yw48K7WGNSA6Qp5mznnDtCFHEF2GoDC+YzgdspMsbiDqtu9TRx07SiH3MoIDREe9
BGzdg5IKoM/KweogojLomIWo15zmMsfkD+visHeegqIHbb/g4NImmCsyxptSKUrP
IBww4ewhEihbr94+6Xq3hD3ORCIv0MRuyoGXAn3TAoGAT94mKpFsLv4VXNHzrWGu
6di2MHMGOGGHlDUjtcXKGvX8hzEhCPWB66ruPuPMdw2eI/ZWnw4wNBnNkKgjtQF0
iOK8REG37srqo+wYSxYBGT0CnlPXW3vOL8lsi3gtZ+rXSRBlwnpIQcccms40ASAf
kmvwxbfOUt6glyk1QFILT3MCgYAVdw8/30X7MLLJaalbWdslGhmN1xGupPLz92X7
bDW6hYL6bZ8nQImiYZH9N8Aynjol8xzs1+n0ytSDWQVM7PfNwLL1JssoC1ANo/Ia
bwMqKHkTLu05eyXLiUbQwXUO3I8AwJRCmweaQkifOrxOydM7b3mZ365Da58kAsZV
5Fbv4wKBgA7oGm+jwbziLnoeCq0JvG/OiV5cr5WEGL6suwQmP+ai+s0EQm+6MkiB
uMXJscCrJloNiOzNs12UNnP8RQCtL+S693zS1O9UhLUaV817+fbu0J2i+TzMeIxU
4L5YIqENHWmdwJ/XgBk+V7Krk4J4gGpRJZnPb5V+X2QYVNWNFDzW
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
const char* mqtt_server = "a2s6m6f7fsxbyw-ats.iot.us-east-2.amazonaws.com"; // Relace with your MQTT END point
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
