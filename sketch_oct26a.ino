#include <IFTTTMaker.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>


char ssid[] = ""; //wifi name
char password[] = ""; //wifi pwd


#define KEY "" //IFTTT webhook key
#define EVENT_NAME "front_door_opened"


WiFiClientSecure client;
IFTTTMaker ifttt(KEY, client);

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);


  //triggerEvent takes an Event Name and then you can optional pass in up to 3 extra Strings
  if (ifttt.triggerEvent(EVENT_NAME)) {
    Serial.println("Successfully sent");
  } else
  {
    Serial.println("Failed!");
  }


}

void loop() {
  // put your main code here, to run repeatedly:

}
