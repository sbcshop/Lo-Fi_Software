/*
 * This code demonstrate use of LoRa Module with ESP32 to receive data from other LoRa device
 * 
 * Visit GitHub for more Demo Example Codes:
 * https://github.com/sbcshop/Lo-Fi_Software/tree/main/examples
 * 
 * Display interfacing with ESP32
  ---------------------------------------------------------------------
  | ESP32 | Display | Function                                        |
  ---------------------------------------------------------------------
  | IO12  | LCD_CLK | Clock pin of SPI interface for Display          |
  | IO11  | LCD_DIN | MOSI (Master OUT Slave IN) pin of SPI interface |
  | IO10  | LCD_CS  | Chip Select pin of SPI interface                |
  | IO13  | LCD_DC  | Data/Command (MISO) pin of SPI interface        |
  | IO14  | LCD_RST | Display Reset pin                               |
  | IO5   | BL      | Backlight of display                            |
  ---------------------------------------------------------------------

 * ESP32 used for Mode selection of LoRa Module
  ------------------------------------------------------
  | ESP32     | LoRa Module | Function                 |
  ------------------------------------------------------
  |IO18/U1RXD | LO_TX       | UART Communication Pin   |
  |IO17/U1TXD | LO_RX       | UART Communication Pin   |
  | IO47      | M0          | Mode selection pin       |
  | IO48      | M1          | Mode selection pin       |
  ------------------------------------------------------
  
 */
#define mySerial Serial2

// mode selection pins
const int M0 = 47;
const int M1 = 48;

void setup() 
{
  Serial.begin(115200);                     // Initialize ESP32 serial communication on COM Port
  mySerial.begin(9600, SERIAL_8N1, 18, 17); // Initialize ESP32 Serial communication with LoRa module

  pinMode(M0, OUTPUT); // Define pin as OUTPUT
  pinMode(M1, OUTPUT); // Define pin as OUTPUT
  
  Serial.println("Code to Receive data from other LoRa Device");
  normalMode();
  delay(500);  
}

void loop() 
{  
  // Print data on Serial console received from other LoRa device
  if (mySerial.available())
    {
     Serial.write(mySerial.read()); 
    }

  // Send data over LoRa entered from Serial console
  if (Serial.available())
    {
     char c = Serial.read();
     mySerial.write(c); 
    }
}

void normalMode() {
  // M1 - 0, M0 - 0
  digitalWrite(M0, LOW);
  digitalWrite(M1, LOW);
  Serial.write("LoRa Module Normal Mode Selected");
}
