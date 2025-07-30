#include <Keypad.h>
#include <LiquidCrystal.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Define the keypad layout
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize the LCD

const char* ssid = "your_SSID"; // Your WiFi SSID
const char* password = "your_PASSWORD"; // Your WiFi Password
const char* serverUrl = "http://your-node-red-url/api/data"; // Node-RED API endpoint

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("Connecting...");
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    lcd.print(".");
  }
  lcd.clear();
  lcd.print("Connected!");
  delay(2000);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    lcd.clear();
    lcd.print("Key: ");
    lcd.print(key);
    sendDataToNodeRed(key);
  }
}

void sendDataToNodeRed(char key) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    String jsonData = "{\"key\":\"" + String(key) + "\"}";
    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}