# Lo-Fi_Software
<img src="https://cdn.shopify.com/s/files/1/1217/2104/files/lofibanners1copy.jpg?v=1700211816">

Lo-Fi combines ESP32S3 with LoRa to establish long-range wireless communication in challenging situations in addition to WiFi and BLE capabilities. With LoRa's great range and simple connectivity, you can talk with devices up to 5 km distant with ease. Device is available in three supported frequencies - 433MHz, 868MHz, and 915MHz bands for LoRa applications.

This GitHub page offers a step-by-step tutorial for using Lo-Fi. 

### Features : 
- Device powered by powerful ESP32 S3 WROOM-1 which is having Xtensa® dual-core 32-bit LX7 microprocessor, up to 240 MHz 
- Inbuilt Wi-Fi & Bluetooth LE for wireless connectivity
- Type C interface for Programming/Power 
- 1.14" TFT display with resolution 135 x 240 pixels for visual interactions
- GPIO breakouts for interfacing additional peripherals 
- Breadboard compatible for easy DIY breadboarding projects
- 2 separate user programmable buttons along with Reset and Boot buttons
- 3.7V Lithium Battery connector for portable use case with onboard charging option
- Use new generation LoRa spread spectrum to ensure stable communication
- LoRa supports data rate up to 62.5kbps  and a longer data transmission range of up to 5 km


### Pinouts
<img src="https://github.com/sbcshop/Lo-Fi_Software/blob/main/images/LoFi%20pinout.jpg">

 - (1) LoRa Module
 - (2) SMA Antenna Connector
 - (3) Boot Button
 - (4) ESP32-S3-WROOM-1
 - (5) 1.14” Display
 - (6) Reset Button
 - (7) Type C interface
 - (8) Battery Connector
 - (9) & (14) Programmable Buttons
 - (10) & (13) LoRa ESP32 UART pins
 - (11) & (12) Multifunctional GPIOs Breakout

### Interfacing Details
- Display interfacing with ESP32
    | ESP32 | Display | Function |
    |---|---|---|
    | IO12 | LCD_CLK | Clock pin of SPI interface for Display|
    | IO11 | LCD_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
    | IO10 | LCD_CS | Chip Select pin of SPI interface|
    | IO13 | LCD_DC| Data/Command (MISO) pin of SPI interface|
    | IO14 | LCD_RST | Display Reset pin |
    | IO5  | BL | Backlight of display|

- ESP32 and LoRa Module interfacing
    | ESP32| LoRa Module | Function |
    |---|---|---|
    |IO18/U1RXD | LO_TX | UART Communication Pin |
    |IO17/U1TXD | LO_RX | UART Communication Pin |
    |IO47 | M0   | Mode selection pin |
    |IO48 | M1   | Mode selection pin |

  **Note:** There is option to use LoRa Tx and Rx pin either standalone or with ESP32. Default jumper is provided so LoRa is connected with ESP32. If you want to use LoRa standalone with any USB to TTL converter, then remove jumpers from **L_RX-E_TX** and **L_TX-E_RX** header pins.

- ESP32 and Buttons interfacing
    | ESP32 | Button | Function |
    |---|---|---|
    |IO7 | BT1 |Programmable button |
    |IO6 | BT2 | Programmable button |
    |IO0 | BOOT | Boot button |
  
- GPIOs Breakout
- 
### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 S3 board support into IDE, for this first you need to add below link into preference:
     
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif"/>
      
   - Now will install ESP32 based boards as shown in below image,

      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif"/>
     
   - Once done, keeping default settings select the ESP32S3 Dev Module with suitable com port (may be different in your case) as shown below, 

      <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/select_esp32_with_comport.gif">
     
     
### 2. Installing Libraries
   - Download [library zip file]() provided here in github.
   - Extract and copy files inside Document > Arduino > Libraries folder. Make sure to restart Arduino IDE whenever you update or add any libraries.

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/library_files_path.png" />
     
### 3. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes](https://github.com/sbcshop/Lo-Fi_Software/tree/main/examples) in github which you can download and try. 
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on ESP32 of Lo-Fi.
     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/upload_process.gif">
   - Checkout other examples below and build your own custom program codes using those references.

### Example Codes
Checkout below demo examples code for reference getting started,
   - [Example 1]() : Display Demo code
   - [Example 2]() : Send and Receive Data using onboard LoRa module
   - [Example 3]() : 

   Now you are ready to try out your own codes, **_Happy Coding!_**


## Resources
  * [Schematic](https://github.com/sbcshop/Lo-Fi_Hardware/blob/main/Design%20Data/schematic%20Lo-Fi.pdf)
  * [Hardware Files](https://github.com/sbcshop/Lo-Fi_Hardware)
  * [Step File](https://github.com/sbcshop/Lo-Fi_Hardware/blob/main/Mechanical%20Data/Step%20Lo-Fi.step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 WROOM 1 Datasheet](https://github.com/sbcshop/Lo-Fi_Software/blob/main/documents/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)


## Related Products
  * [USB to LoRa Dongle](https://shop.sb-components.co.uk/products/lo-fi?variant=41026475753555) 
   
     ![USB to LoRa Dongle](https://shop.sb-components.co.uk/cdn/shop/products/05_2.png?v=1678712489&width=300)   

  * [GatePi](https://shop.sb-components.co.uk/products/gatepi?variant=39756684066899) 
   
     ![GatePi](https://shop.sb-components.co.uk/cdn/shop/products/GatePi-4channelRelayBoardwithLoRaModulebasedonRP2040.jpg?v=1647335212&width=300) 

  * [RangePi](https://shop.sb-components.co.uk/products/range-pi?variant=39744084705363) 
   
     ![RangePi](https://shop.sb-components.co.uk/cdn/shop/products/1_54b19023-5d19-4f55-acea-af894f2d00c6.png?v=1646815358&width=300)

  * [Pico LoRa Expansion](https://shop.sb-components.co.uk/products/pico-lora-expansion-868mhz?_pos=5&_sid=8faf72598&_ss=r) 
   
     ![Pico LoRa Expansion](https://shop.sb-components.co.uk/cdn/shop/products/pico-expansioonpng_1_2525bf59-655f-421d-ac62-71e706c96060.png?v=1647321524&width=300)

 
## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
