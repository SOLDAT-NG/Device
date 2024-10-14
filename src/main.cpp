#include <Arduino.h>

#define GPIO_LED 2
#define GPIO_TX2 17 
#define GPIO_RX2 16

String handshake = "AT";
String identifier = "AT+ID";

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RX2, TX2); // 8 data bits, No parity, 1 stop bit

  Serial.println("Serial2 initialized at 9600 baud.");
  delay(1000);
}

void loop() {

  Serial2.println(identifier);
  Serial.println("Message sent");


  if (Serial2.available()) {
    String data = Serial2.readStringUntil('\n'); // Read until newline
    Serial.print("Received: ");
    Serial.println(data);
  }

  delay(5000);
}