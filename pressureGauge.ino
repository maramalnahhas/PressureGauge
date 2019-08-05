#include "Adafruit_MPRLS.h" //display im using (128*6)
#include <Adafruit_SSD1306.h>
#include <Wire.h>

  Adafruit_SSD1306 display(4);
  
#define RESET_PIN  -1  // set to any GPIO pin # to hard-reset on begin()
#define EOC_PIN    -1  // set to any GPIO pin to read end-of-conversion by pin
Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

    void setup() {

      //Display setup
      display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
      display.clearDisplay();
      display.display();
      display.setCursor(1,2);
      display.setTextSize(2);
      display.setTextColor(WHITE, BLACK);
      display.println("Pressure:");
     
        
        //Serial.begin(115200);
        //Serial.println("Simple Test");
        //if (! mpr.begin()) {
        //Serial.println("Failed to communicate with MPRLS sensor, your wiring sucks");
        //while (1) {
        //delay(10);}
        //}
        //Serial.println("Found MPRLS sensor");
        //}
                
    void loop() {
       float pressure_hPa = mpr.readPressure();

       //Monitor readings
       //Serial.print("Pressure (mbar): "); Serial.println(pressure_hPa);
       //Serial.print("Pressure (PSI): "); Serial.println(pressure_hPa / 68.947572932);

       //Display readings
       display.setCursor(2,24);
       display.setTextSize(2);
       display.setTextColor(WHITE, BLACK);
       display.print(pressure_hPa);
       display.setCursor(80,30);
       display.setTextSize(1);
       display.setTextColor(WHITE, BLACK);
       display.print(" mbar");
       display.display();
       delay(1000);
    }
