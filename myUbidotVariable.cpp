#include "ESP8266WiFi.h"
#include "myUbidotVariable.h"

WiFiClient _client;
String _variableId;
String _token;

MyUbidotVariable::MyUbidotVariable(WiFiClient client, String variableId, String token) {

	_client = client;
	_variableId = variableId;
	_token = token;
}

void MyUbidotVariable::sendValue(String body) {

    if (_client.connect("things.ubidots.com", 80))  {
        Serial.println("Connected to Ubidots...");
        delay(100);

        _client.println("POST /api/v1.6/variables/" + _variableId + "/values HTTP/1.1");
        _client.println("Content-Type: application/json");
        _client.print("Content-Length: "); _client.println(body.length());
        _client.println("X-Auth-Token: " + _token);
        _client.println("Host: things.ubidots.com\n");
        _client.println(body);

        Serial.println("POST /api/v1.6/variables/" + _variableId + "/values HTTP/1.1");
        Serial.println("Content-Type: application/json");
        Serial.print("Content-Length: "); Serial.println(body.length());
        Serial.println("X-Auth-Token: " + _token);
        Serial.println("Host: things.ubidots.com\n");
        Serial.println(body);

        // response
        // while (_client.available()) {
        //     char c = _client.read();
        //     Serial.print(c);
        // }

        if (_client.connected()) {
            Serial.println("Disconnecting from Ubidots...");
            _client.stop();
        }
    }
}

