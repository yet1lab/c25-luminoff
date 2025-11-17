//======================================================
//                   TIME FUNCIONS
//======================================================
/*
#include <HTTPClient.h>
#include <ArduinoJson.h>

String getTime() {
  bool httpOK;
  int attempt = 1;
  HTTPClient http;
  String output = "";
  DeserializationError error;
  StaticJsonDocument<1024> doc;

  while (output.length() < 16){
    oledPrint(
      Msg{5,18, "Get Time..."},
      Msg{5,30, "Attempt: " + String(attempt++)}
    );         
    String DAY = "mon";
    http.begin("http://yet1lab.com/api-exemple/" + DAY + "/" + String(CLASS) + ".txt");
    
    http.setTimeout(2000);
    httpOK = http.GET() == HTTP_CODE_OK;
    String payload = http.getString();

    if (httpOK) error = deserializeJson(doc, payload);
    if (!error) output = doc["datetime"].as<String>();

    http.end();
    delay(1000);
  }
  return output.substring(11, 16) + "_" + doc["day_of_week"].as<int>();
}
*/