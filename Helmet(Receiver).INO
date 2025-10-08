#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
  bool left;
  bool right;
  bool brake;
} struct_message;

struct_message incomingData;

void OnDataRecv(const esp_now_recv_info_t *recv_info, const uint8_t *incomingDataBytes, int len) {
  if (len == sizeof(incomingData)) {
    memcpy(&incomingData, incomingDataBytes, sizeof(incomingData));
    Serial.print("Left: ");
    Serial.print(incomingData.left);
    Serial.print(" | Right: ");
    Serial.print(incomingData.right);
    Serial.print(" | Brake: ");
    Serial.println(incomingData.brake);

    digitalWrite(25, incomingData.left);
    digitalWrite(26, incomingData.right);
    digitalWrite(33, incomingData.brake);

    if(incomingData.left==1)
    {
      digitalWrite()
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(33, OUTPUT);

  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(33, LOW);
}

void loop() {
  // nothing here
}
