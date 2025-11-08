//======================================================
//                   TIME FUNCIONS
//======================================================
String getTime() {
  bool httpOK;
  HTTPClient http;
  String output = "";
  DeserializationError error;
  StaticJsonDocument<1024> doc;

  for (int attempt = 0; attempt < 8; attempt++) {
    oledPrint(
      Msg{5,18, "Get Time"},
      Msg{5,30, "Attempt: " + String(attempt + 1)}
    );
    http.begin("http://worldtimeapi.org/api/timezone/America/Recife");
    
    http.setTimeout(2000);
    httpOK = http.GET() == HTTP_CODE_OK;
    String payload = http.getString();

    if (httpOK) error = deserializeJson(doc, payload);
    if (!error) output = doc["datetime"].as<String>();
    if (output.length() >= 10) return output.substring(11, 16);

    http.end();
    delay(1000);
  }
  return output;
}
