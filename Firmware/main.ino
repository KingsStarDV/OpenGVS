#include <WiFi.h>
#include <WebServer.h>

WebServer myserver(80);


const char* ssid = "ESP32";
const char* password = "kings00000";

void setup(){
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.println("AP initiated");
  Serial.println(WiFi.softAPIP());

  myserver.on("/", handleRoot);
  myserver.on("/rightOn", handleRightOn);
  myserver.on("/rightOff", handleRightOff);
  myserver.on("/leftOn", handleLeftOn);
  myserver.on("/leftOff", handleLeftOff);
  myserver.begin();
  Serial.println("Server initiated");

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void handleRightOn(){
  digitalWrite(8, HIGH);
  myserver.send(200, "text/plain", "OK");
}

void handleRightOff(){
  digitalWrite(8, LOW);
  myserver.send(200, "text/plain", "OK");
}

void handleLeftOn(){
  digitalWrite(7, HIGH);
  myserver.send(200, "text/plain", "OK");
}

void handleLeftOff(){
  digitalWrite(7, LOW);
  myserver.send(200, "text/plain", "OK");
}


void handleRoot(){
  myserver.send(200, "text/html", R"HTMLCODE(
    <!DOCTYPE html>
    <html>
    <body>
    <button onmousedown="rightPressed()" onmouseup="rightLifted()"> RIGHT </button>
    <button onmousedown="leftPressed()" onmouseup="leftLifted()"> LEFT </button>

    <script>
function rightPressed() {
  fetch("/rightOn");
}
function rightLifted() {
  fetch("/rightOff");
}
function leftPressed() {
  fetch("/leftOn");
}
function leftLifted() {
  fetch("/leftOff");
}
</script>
    </body>
    </html>
  )HTMLCODE");
}


void loop(){
  myserver.handleClient();
}