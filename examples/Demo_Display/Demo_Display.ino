/*
 * Demo code to test onboard Display of Lo-Fi
 * 
 * Visit GitHub for more Demo Example Codes:
 * https://github.com/sbcshop/Lo-Fi_Software/tree/main/examples
 * 
 * Display interfacing with ESP32
    | ESP32 | Display | Function |
    | IO12  | LCD_CLK | Clock pin of SPI interface for Display  |
    | IO11  | LCD_DIN | MOSI (Master OUT Slave IN) pin of SPI interface |
    | IO10  | LCD_CS  | Chip Select pin of SPI interface  |
    | IO13  | LCD_DC  | Data/Command (MISO) pin of SPI interface  |
    | IO14  | LCD_RST | Display Reset pin |
    | IO5   | BL      | Backlight of display|
 */
#include <Adafruit_GFX.h>    // graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789 (display controller)
#include <SPI.h>

// Display SPI configuration
#define TFT_CS   10
#define TFT_RST  14 
#define TFT_DC   13

#define TFT_MOSI 11 
#define TFT_SCLK 12

#define BACK_LIGHT 5

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup()
{
  
  pinMode(BACK_LIGHT, OUTPUT); // BackLight pin set as OUTPUT
  digitalWrite(BACK_LIGHT,HIGH); // Turn on BackLight
  
  tft.init(135, 240);  // initialize display with resolution
  tft.setRotation(3); // Change display rotation as per requirement, value-> 0 (defualt), 1, 2, 3
  
  tft.fillScreen(ST77XX_BLACK); // clear screen
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(60, 50);
  tft.setTextSize(4);
  tft.print("Lo-Fi");

  delay(2000);
  tft.setTextSize(2); 
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 20);
  tft.setTextColor(ST77XX_YELLOW);
  tft.println("Thanks for Buying!");
 
  tft.setCursor(0, 60);
  tft.setTextWrap(true);
  tft.setTextColor(ST77XX_BLUE);
  tft.println("SB Components");
  tft.setTextSize(2);
  tft.setCursor(0, 90);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("shop.sb-components.co.uk");
  delay(2000);
  testdrawrects(ST77XX_WHITE);
  delay(500);
}

void loop()
{
  
  testdrawrects(ST77XX_RED);
  delay(500);
  testfillrects(2,ST77XX_RED);
  delay(500);
  testdrawcircles(5, ST77XX_RED);
  delay(500);
  testtriangles();
  delay(500);
}

void testdrawrects(uint16_t color) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color);
  }
}

void testfillrects(uint16_t color1, uint16_t color2) {
  tft.fillScreen(ST77XX_BLACK);
  for (int16_t x=tft.width()-1; x > 6; x-=6) {
    tft.fillRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color1);
    tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color2);
  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=radius; x < tft.width(); x+=radius*2) {
    for (int16_t y=radius; y < tft.height(); y+=radius*2) {
      tft.fillCircle(x, y, radius, color);
    }
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {
      tft.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles() {
  tft.fillScreen(ST77XX_BLACK);
  uint16_t color = 0xF800;
  int t;
  int w = tft.width()/2;
  int x = tft.height()-1;
  int y = 0;
  int z = tft.width();
  for(t = 0 ; t <= 15; t++) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}

void testroundrects() {
  tft.fillScreen(ST77XX_BLACK);
  uint16_t color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = tft.width()-2;
    int h = tft.height()-2;
    for(i = 0 ; i <= 16; i+=1) {
      tft.drawRoundRect(x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}
