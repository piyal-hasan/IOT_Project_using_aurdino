
#include "Firebase_Arduino_WiFi101.h"
#define FIREBASE_HOST "phsensor2019.firebaseio.com"
#define FIREBASE_AUTH "8zJ6BrYNFm4BEClURQbq5ht0o2pfScwBFgVnDPbP"
#define WIFI_SSID "itmansion1"
#define WIFI_PASSWORD "itmnasion1"

//Define Firebase data object
FirebaseData firebaseData;

void setup()
{

  Serial.begin(115200);
  delay(100);
  Serial.println();

  Serial.print("Connecting to Wi-Fi");
  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED)
  {
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println();
  //Provide the autntication data
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD);
  Firebase.reconnectWiFi(true);
  String path = "/UNO_WiFi_REV2_Test";
  String jsonStr;
  Firebase.pushInt(firebaseData, path + "/Push/Int",12);
}

void loop()
{
}
