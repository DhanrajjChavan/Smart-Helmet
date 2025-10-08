//  0x00, 0x4b, 0x12, 0x3e, 0xa7, 0xcc

#include <esp_now.h>
#include <WiFi.h>

// Structure for the data to be sent
typedef struct struct_message {
  bool left;
  bool right;
  bool brake;
} struct_message;

struct_message outgoingData;

// MAC address of the Helmet ESP32 (receiver)
uint8_t receiverMac[] = {0x00, 0x4b, 0x12, 0x3e, 0xa7, 0xcc}; // Replace with your helmet ESP MAC

void OnSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

void setup() {
  Serial.begin(115200);

  // Set device in station mode
  WiFi.mode(WIFI_STA);
  Serial.println(WiFi.macAddress());

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnSent);

  // Register peer
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverMac, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  // Setup GPIOs
  pinMode(12, INPUT); // Left indicator
  pinMode(14, INPUT); // Right indicator
  pinMode(27, INPUT); // Brake
}

void loop() {
  // Read inputs
  outgoingData.left = digitalRead(12);
  outgoingData.right = digitalRead(14);
  outgoingData.brake = digitalRead(27);

  // Send data
  esp_now_send(receiverMac, (uint8_t *)&outgoingData, sizeof(outgoingData));
  delay(200); // 200ms interval
}
