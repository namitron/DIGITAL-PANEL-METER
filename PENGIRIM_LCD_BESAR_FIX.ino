#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SoftwareSerial espSerial(5, 6);
String str;
String str2;
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

int c = 0;
int a = 0;
int b = 0;
int d = 0;
int e =0;


void(*reset_ulang) (void) = 0;//Perintah reset


        
void setup(){
Serial.begin(9600); 
espSerial.begin(9600);
delay(2000);

  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }
 uint32_t currentFrequency;
 Serial.println("Hello!");
 ina219.begin();
 Serial.println("Measuring voltage and current with INA219 ...");

display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,4);
  display.print("mA: ");
  display.setCursor(0,0);
  display.display(); // actually display all of the 

}



 
void loop()
{
  
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
int mA = current_mA ;
Serial.println(mA); 
  d = mA - d;
  //Serial.print("Asli  = "); 
  //Serial.println(mA); 
 //str2 = String(mA)+String(",")+String("*");
 //espSerial.println(str2);

     if (mA>5){
            a = mA;
        if (a>b /*&& d<2 && d>0*/){
            b = a;
            c = map(b, 0, 81, 0, 100);
            Serial.println("Asli:   ");
            Serial.println(mA);
            Serial.println("kebaca:   ");
            Serial.println(c);
            str2 = String(c)+String(",")+String("*");
            espSerial.println(str2);
           // Serial.println("asli:   ");
            //Serial.println(mA);
           /* display.setTextSize(3);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,4);
            display.print("mA: ");
            display.setTextSize(3);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(60,4);
            display.print(c);
            display.setCursor(0,0);
            display.display();
            display.clearDisplay();*/
            }
            //delay(5000);
            //reset_ulang();
     }  
                                                               
    /* if (a>b && d<2 && d>0)
         {
              b = a;
              c = map(b, 0, 38, 0, 100);
              Serial.println("kebaca:   ");
              Serial.println(c);
         } */     
        
     
     
 /*   
      if(micros() >= voltageLastSample + 1000 )                                                                      
              {
                voltageSampleRead = (analogRead(mA)-512)+ voltageOffset1;                             
                voltageSampleSum = voltageSampleSum + sq(voltageSampleRead) ;                                             
                voltageSampleCount = voltageSampleCount + 1;                                                             
                voltageLastSample = micros() ;  
              }
              
      if(voltageSampleCount == 1)                                                                               
          {  
            display.setTextSize(3);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0,4);
            display.print("mA: ");
            display.setTextSize(3);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(60,4);
            display.print(c);
            //Serial.println(mA);
            display.setCursor(0,0);
            display.display();
            display.clearDisplay();
             
            voltageSampleSum =0;                                                                                   
            voltageSampleCount =0;             
          }
          */
}
