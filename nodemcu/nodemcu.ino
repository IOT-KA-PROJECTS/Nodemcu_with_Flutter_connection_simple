#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);
const char *ssid = "GrootM";
const char *pwd = "grootgroot";

void handleCommand() {
  String cmdParam = server.arg("cmd");  // Extract the command parameter
  executeCommand(cmdParam);             // Execute the corresponding action
  server.send(200);                     // Send a response
}

void executeCommand(String cmd) {
  Serial.println(cmd);  // Handle invalid commands
}

void setup() {

  Serial.begin(9600);
  delay(10);
  Serial.print("Wait Connection With : ");
  Serial.println(ssid);
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("please wait . . . .");
  }
  Serial.println("");
  Serial.print("WiFi connected With : ");
  Serial.println(ssid);
  Serial.println('\n');
  Serial.print("IP Address");
  Serial.println(WiFi.localIP());
  server.on("/command", HTTP_GET, handleCommand);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

