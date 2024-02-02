
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
MIIDWjCCAkKgAwIBAgIVAMg44ZwGSNmHVqcTFGOPr1vGS7GhMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjA1MTQyMjA4
MjdaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCwzNt3UpH4yHnMke5E
Urf+59YQ0Jra2qsUQ7Pi2ZJsFVNONNDEZDqyHyk0wR0cx107kLkX8B3r3i1oWSnX
CoIETBgQ7NDo9xWI81w+ZQV+5qleYoGqtL+n9hc/yKnazhy1xM2yObjRO6IizEIs
yHE5mB6tINliQKw+PuY3Y+mb1ElhOhtayK7kfZmaKttJA6LbtOFR7ti0GekA9ZFs
Ah8A236bwWpbX9EfGtKi2MIor/++3vsL/3pHOW7Virjakw6c44q5L00vUNPtJ5UV
WMnrXz9Dr+OTZ4LyLcBEBVcTo3yHhw9/xSZIhJEEdRsMh7W1VS1UBGAmeZw+ohiF
84eFAgMBAAGjYDBeMB8GA1UdIwQYMBaAFBNcAEG+6WzfSmuGKl/uaDS7c779MB0G
A1UdDgQWBBQ6T38wESCYa5kaNB5VZ3H+tcBqUjAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAuSJNPou/o3cBbuafZj0o5fOG
CVuzwg5tyb263diZCpRGzFhhvpQJg4+O6hU9A06zkWtmgwlaNLLpGymnjKb0lm12
STcdtr5wKgPjMODMd6XENLbVyBMuXgODdf18CprsXlxhuqWAks0sADmmJX3+26l4
2b9Po2w8Wxt8KCPxrM0i3UfHcRxAI7G0PMGBYWgpXswwO+Po6wqCLBiGbgCXmBHN
umnFaBrh5R+oj3DeK1wh8hF2TeiC3mblaFYHPSgyEEDyQB0ySZr0W9l2tBJETq2m
cMD4XY16aIcxxvNTR85aQLXNiNRvH1AMphdNH7nq5k57ge/F2e+XfKZ2yFTSqw==
-----END CERTIFICATE-----
)KEY";

// Copy contents from  XXXXXXXX-private.pem.key here ▼
static const char privkey[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAsMzbd1KR+Mh5zJHuRFK3/ufWENCa2tqrFEOz4tmSbBVTTjTQ
xGQ6sh8pNMEdHMddO5C5F/Ad694taFkp1wqCBEwYEOzQ6PcViPNcPmUFfuapXmKB
qrS/p/YXP8ip2s4ctcTNsjm40TuiIsxCLMhxOZgerSDZYkCsPj7mN2Ppm9RJYTob
Wsiu5H2ZmirbSQOi27ThUe7YtBnpAPWRbAIfANt+m8FqW1/RHxrSotjCKK//vt77
C/96Rzlu1Yq42pMOnOOKuS9NL1DT7SeVFVjJ618/Q6/jk2eC8i3ARAVXE6N8h4cP
f8UmSISRBHUbDIe1tVUtVARgJnmcPqIYhfOHhQIDAQABAoIBAFa7+UK9cD0jZJVW
VhSQnBFifOL846tQMTOczygP4sRBZf/s6yodnan6nYVy46xVpchuBE/ZDWTEN3SE
oYEMd6JSDlBnTUmsxZTNBsjZWGvcDuTt4Hz1dTyZ/ufcsm9URENsDBlONfv3jGAT
4rcDkoBVv17hyaNo5NcYlmpACr/WASbWpnaAXXz6MBxRuwFVDA88mCCKYdRRLllh
8kj7onuTMbw+laOY5CqvfQj3XHp3+oN7QTbE7acCJTXiUmSiXJQfONtM5+MwxWI7
6BNU1t6zg59WKf/hJDDI+OZ60ov5ILqY0UHUC/dURk29DPA0WFgvWlVXcfU8fO+x
CxAFgbUCgYEA4NIDGlrjLKzAlK3LD3159w/jg64J9pU28PivIjMi2eA9paFmVba7
j37yZA4xyaGdt4vDWy7F487ad5xdIckoCxipMeKtzZGF1T61jwFnISEyjlr0V2En
JXD0dTu2QOi+yIzZSgu0626nFrsnKdSBM2D8kt0Z1DfhqdYOmgwA5QcCgYEAyVHy
EBRIHY3Snt9xyeAo+OTi5WoZReqIlwukETnsf/fT4M0wurreVg+B3DYy4g8bGLlX
IU8ka5fQ8jTwFguTV3wDJMiKqWkPfbS7wNvPPn64NMSh9jEYg0Ng2lpAonODZ5Dk
wtAK/gPdcuGVQ6joEHp9ETHYCh+C2mJp1CCvOBMCgYAsPgfwSsyEAScQ2zanwLic
vxq10i0RwoGCYF4Oq+OC3tci3iVGXuSAM6o9uHFhzZU9BpsWOZkl4JIrkbDeMjjY
Hi1FrOcpGictNN8D2nHSGjdZvlpxS6QpgRYKcArIsUTCML2eDbm3zxnApmnpmHEo
jECIIkyv76NQCdjrxcrzRwKBgBhj+TPBgUszV4UwBRU0N0KQWHz68bzqwUmre2Eq
52BJoj3mHjVBVpaOomkPl/KTafEA43GBqSPv7LyrdTr2hA9hUvAt677Cn8HXF7gx
6VXk/GRIPmcZY6LjkuRhcts7q3vsrgp8Mhi8VyQH+JGN8S+t52Eh7M6tKqlSqwes
Pg5JAoGAJFWnORq0KK7bmdoh22PLNOKFwtkiggePfYAxgGuggb2Lq/hyeH1YlGmF
p9dqL39Boyf7JMDWO4ftGrw1pMxtCeepvKfW0qqVxPLsy+xvtf52qE/iFCobdzt2
c6fyaRxbvZVwbQUqtybWYiDa+llIxNqAmGCbCCM4dxWcH7CR3d0=
-----END RSA PRIVATE KEY-----
)KEY";


/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

//#include "SPIFFS.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson (use v6.xx)
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include "DHT.h"
#include "MICS6814.h"  //https://github.com/markoAntonio1692/CJMCU_MICS-6814
#include "Adafruit_CCS811.h"

//--Pines para modulo CJMCU-MICS6814
#define PIN_CO  32
#define PIN_NO2 34
#define PIN_NH3 35
MICS6814 gas(PIN_CO, PIN_NO2, PIN_NH3);
//-----------------------------------
Adafruit_CCS811 ccs; //I2C ESP32

#define btn_config_wifi 0  //pin para boton de configuracion de wifi
#define LED 2

const char* ssid = ""; //
const char* password = ""; // 
//---MQTT SERVER----------------------
const char* mqtt_server = "a2cwbdq08ub58x-ats.iot.us-east-1.amazonaws.com"; // Relace with your MQTT END point
const int   mqtt_port = 8883;
String MQTT_PUB_TOPIC;
String MQTT_SUB_TOPIC;
//------------------------------------

// -----for DHT22----------------------
//      VCC: 5V or 3V
#define DHTPIN 4  //pin de lectura de sensor dht
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);
//---------------------------------------

long FrecData_Seg =5; //frecuencia de envio de datos por default

uint32_t chipID;
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

float temperature = 0;
float humidity = 0;
  
void sensor_dht22(){
     // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println(f);
//  Serial.print(F("°F  Heat index: "));
//  Serial.print(hic);
//  Serial.print(F("°C "));
//  Serial.print(hif);
//  Serial.println(F("°F"));
 temperature =t;
 humidity=h;
  }

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
FrecData_Seg = doc["FrecData_Seg"]; // recibir datos de por mqtt, frecuencia de envio en Segundos

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
    WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
    pinMode(btn_config_wifi,INPUT_PULLUP);
    pinMode(LED,OUTPUT);
    digitalWrite(LED,1);
    pinMode(2, OUTPUT);
    Serial.begin(115200);

    delay(5000);

    WiFiManager wm;
    digitalWrite(LED,0);
    // initialize digital pin LED_BUILTIN as an output.
    delay(1000);
  //setup_wifi();
 if(digitalRead(btn_config_wifi)==0){ // ingresar a ip 192.168.4.1
      Serial.println("MODO CONFIG WIFI");
      wm.setConfigPortalTimeout ( 360 );
      digitalWrite(LED,1);
      wm.resetSettings();
    }
    bool res;
    // res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    digitalWrite(LED,1);
    res = wm.autoConnect("ESP32","12345678"); // password protected ap
    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("CONECTADO A RED WIFI :)");
         Serial.println("");
         Serial.println("WiFi connected");
        Serial.println("IP address: ");
       Serial.println(WiFi.localIP());
       for(int x=0;x<=10;x++){
        digitalWrite(LED,!digitalRead(LED));
        delay(200);
       }
    }
    
    digitalWrite(LED,0);
    
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

chipID = ESP.getEfuseMac(); //extraer ID de ESP32

MQTT_PUB_TOPIC = String(chipID) + "/out"; //topico mqtt
MQTT_SUB_TOPIC = String(chipID) + "/in";

Serial.println("");
Serial.println("");
Serial.print(" ID: "); Serial.println(chipID);
Serial.print(" TOPIC PUB: "); Serial.println(MQTT_PUB_TOPIC);
Serial.print(" TOPIC SUB: "); Serial.print(MQTT_SUB_TOPIC);
Serial.println("");
Serial.println("");

  Serial.println("MICS-6814 Sensor Sample");
  Serial.print("Calibrating Sensor");
  //gas.calibrate(); //CALIBRACION DE SENSOR MICS6814 0-20min Aprox, tiene que calentar...
  Serial.println("OK!"); 
  
   dht.begin(); //inicializar temperatura y humedad
   if(!ccs.begin()){ //inicializar Co2
   Serial.println("Failed to start sensor! Please check your wiring.");
   }
  // Wait for the sensor to be ready
  //while(!ccs.available());
  //delay(2000);

}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > FrecData_Seg*1000L) {
     lastMsg = now;
     delay(100);
     sensor_dht22();
     Serial.print("NH3: "); Serial.print(gas.measure(NH3));Serial.println("ppm");
     float co2;
     if(ccs.available()){
       if(!ccs.readData()){
        Serial.print("CO2: ");
        co2=ccs.geteCO2();
        Serial.print(co2);
        Serial.println(" ppm ");
        //Serial.print("ppm, TVOC: ");
        //Serial.println(ccs.getTVOC());
        }else{ Serial.println("ERROR!");}
     }
             //Tramas JSON    
     StaticJsonDocument<128> doc;
     doc["ID"] = chipID;
     doc["Temp_C"] = temperature;
     doc["Hum_%"] = humidity;
     doc["CO2_ppm"] = co2;
     doc["NH3_ppm"] = gas.measure(NH3);

    String output;
    serializeJson(doc, output);
    Serial.print("Topic pub: "); Serial.println( MQTT_PUB_TOPIC);
    Serial.println(output);    
    client.publish(MQTT_PUB_TOPIC.c_str(), output.c_str()); //publicar data por mqtt
  }

}
