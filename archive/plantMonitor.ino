#include "wifi/ESP8266WiFi.h"
#include "wifi/WiFiClientSecure.h"
#include "etc/extraFunctions.cpp"
#include <avr/pgmspace.h>


#ifndef STASSID
#define STASSID ""//
#define STAPSK  ""//
#endif


const char wSsid[] = STASSID;
const char wPass[] = STAPSK;
const int httpsPort[] PROGMEM = {443};

const char fHost[] PROGMEM = "www.pobanion.com";//instead of pulling from progmem could use macro: f("string")
const char url[] = "/api/plant/addtodb";
const char fFingerprint[] PROGMEM = "06:16:47:D6:EB:0F:68:65:DF:2C:68:FD:90:DF:77:06:F5:9B:47:5C";

void setup(){
  Serial.begin(74880);
  Serial.println();
  //Serial.setDebugOutput(true);

  WiFi.begin(wSsid, wPass);

  char *host = new char[32];
  rfFlash(fHost, host);

 // WiFi.printDiag(Serial);
  Serial.print(F("Connecting"));
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print(F("Connected, IP address: "));
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print(F("connecting to "));
  Serial.println(host);
//---------------------TODO need to set up sessions for the tcp connection
/* use
BearSSL::WiFiClientSecure.setSession(&BearSSLSession)
before
BearSSL::WiFiClientSecure.connect()
for TLS session
*/
 // Serial.printf("Using fingerprint '%s'\n", fFingerprint);
  client.setFingerprint(fFingerprint);
  if (!client.connect(host, pgm_read_word(httpsPort))) {
    Serial.println(F("connection failed"));
    return;
  }

  Serial.print(F("requesting URL: "));
  Serial.println(url);

char data[] =  "{\"luminosity\": \"6\", \"temperature\": \"8\"}";
/*char wifiPackage[] = "String("POST ") + rfFlash(fUrl) + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "content-type: application/json\r\n" +
               "Content-Length: " + strlen(data) + "\r\n" +
               "Accept: application/html\r\n" +
               "user: pobo\r\n" +
               "pass: afsder\r\n" +
               "Connection: Close\r\n\r\n" "*/


  client.print(String("POST ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "content-type: application/json\r\n" +
               "Content-Length: " + strlen(data) +"\r\n" +
               "Accept: application/html\r\n" +
               "user: pobo\r\n" +
               "pass: afsder\r\n" +
               "Connection: Close\r\n\r\n" +
               data + "\r\n");

  Serial.println(F("request sent"));
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line == "\r") {
      Serial.println(F("headers received"));
      //Serial.println(line);
      break;
    }
  }
  String line = client.readStringUntil('\n');
Serial.println(client.readString());//Mess up whenever the page errors. Look like there is an with the page redirects.
/*  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println(client.readString());
  Serial.println("==========");
  Serial.println("closing connection");
  Serial.println(client);*/

}

void loop() {
  //readTemp(A0);
  delay(1000);
}
