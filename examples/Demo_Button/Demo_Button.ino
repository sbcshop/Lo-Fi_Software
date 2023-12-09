/*
 * Demo code to test onboard programmable buttons of Lo-Fi
 * 
 * Visit GitHub for more Demo Example Codes:
 * https://github.com/sbcshop/Lo-Fi_Software/tree/main/examples
 * ESP32 and Buttons interfacing
    |ESP32  | Button | Function |
    |IO7    | BT1    | Programmable button |
    |IO6    | BT2    | Programmable button |
    |IO0    | BOOT   | Boot button |
 */
const int bootButton = 0; 
const int BT1 = 7; 
const int BT2 = 6; 

void setup(void) {
  Serial.begin(115200);
  pinMode(bootButton, INPUT);
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  Serial.println("Button Demo Test!");

}

void loop() {
  int bootVal = digitalRead(bootButton);
  int bt1Val = digitalRead(BT1);
  int bt2Val = digitalRead(BT2);
  
  Serial.println("Button Value");
  Serial.printf("Boot:%d BT1:%d BT2:%d \n", bootVal, bt1Val,bt2Val);
  delay(200);
}
