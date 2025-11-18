/*
====================== READ THE BUTTON STATUS ======================
This code below we don't need the resistance pullup for button, we can use freely by adding the INPUT_PULLUP function
where the active resistance in ESP32 can help you to do that.
*/
#define BUTTON 36
void setup() {
  pinMode (BUTTON, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.println ("=== KIEM TRA NUT NHAN ===");
}

void loop() {
  int ButState = digitalRead (BUTTON);
  Serial.print("Trang thai nut nhan: "); Serial.println (ButState);
  delay(70);
}
