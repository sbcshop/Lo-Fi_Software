/*
 * Demo code to Setup Mode of onboard LoRa module
 * 
 * Visit GitHub for more Demo Example Codes:
 * https://github.com/sbcshop/Lo-Fi_Software/tree/main/examples
 * 
 * ESP32 used for Mode selection of LoRa Module
    ------------------------------------------------
    | ESP32     | LoRa Module | Function           |
    ------------------------------------------------
    | IO47      | M0          | Mode selection pin |
    | IO48      | M1          | Mode selection pin |
    ------------------------------------------------
 * Four operating Modes possible =>
   -----------------------------
   | Mode(0-3)       | M1 | M0 |
   -----------------------------
   | 0 Normal        | 0  | 0  |
   | 1 WOR Mode      | 0  | 1  |
   | 2 Configuration | 1  | 0  |
   | 3 Deep sleep    | 1  | 1  |
   -----------------------------
 
 */

// mode selection pins 
const int M0 = 47;
const int M1 = 48;

void setup() 
{
  Serial.begin(115200);
  Serial.println("LoRa Module Mode Selection!");
  pinMode(M0,OUTPUT); // Define pin as output
  pinMode(M1,OUTPUT); // Define pin as output
  delay(100); 

  /*
   * Uncomment corresponding function to set Mode for standalone with USB to TTL or other controller,
   * Only one mode can be selected at a time
   * 1) normalMode
   * 2) worMode
   * 3) configurationMode
   * 4) deepSleepMode
   */
   normalMode();
   //worMode();
   //configurationMode();
   //deepSleepMode();
   delay(500);
}
void loop() 
{     
 delay(50);
}

void normalMode(){
  // M1 - 0, M0 - 0
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);
  Serial.write("LoRa Module Normal Mode Selected"); 
}

void worMode(){
  // M1 - 0, M0 - 1
  digitalWrite(M0,HIGH);
  digitalWrite(M1,LOW);
  Serial.write("LoRa Module WOR Mode Selected");
}

void configurationMode(){
  // This mode is used to configure various settings of LoRa module using software application
  // M1 - 1, M0 - 0
  digitalWrite(M0,LOW);
  digitalWrite(M1,HIGH);
  Serial.write("LoRa Module Configuratio Mode Selected");
}

void deepSleepMode(){
  // M1 - 1, M0 - 1
  digitalWrite(M0,HIGH);
  digitalWrite(M1,HIGH);
  Serial.write("LoRa Module Deep Sleep Mode Selected");
}
