#ifndef myUbidotVariable_h
#define myUbidotVariable_h

#include <stdlib.h>
#include <ESP8266WiFi.h>
// #include <ESP8266mDNS.h>
// #include <WiFiUdp.h>
// #include <PubSubClient.h>
// #include <ArduinoOTA.h>

class MyUbidotVariable 
{
    public:

        MyUbidotVariable(WiFiClient client, String variable, String token);

        void sendValue(String body);
        // void ubidotsDeleteValues(String variable, String token, int start, int end);
};

#endif
