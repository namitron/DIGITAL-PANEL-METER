#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
MCUFRIEND_kbv tft;
#include <Filters.h> 
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <FreeDefaultFonts.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/TomThumb.h>
#include <Fonts/Picopixel.h>
#include <Fonts/FreeSerifItalic9pt7b.h>





#define BLACK   0x0000
#define RED     0xF800
#define GREEN   0x07E0 
#define WHITE   0xFFFF
#define GREY    0x8410
#define NAVY    0x000F
#define CYAN    0x07FF
#define BLUE    0x001F
#define DARKGREEN   0x03E0
#define DARKGREY    0x7BEF








//sensor TEGANGAN
/* 0- General */

        int decimalPrecision = 2;                   // decimal places for all values shown in LED Display & Serial Monitor

        /* 1- AC Voltage Measurement */
        
        int Vin = A8;             // Which pin to measure voltage Value (Pin A0 is reserved for button function)
        float voltageSampleRead  = 0;               /* to read the value of a sample in analog including voltageOffset1 */
        float voltageLastSample  = 0;               /* to count time for each sample. Technically 1 milli second 1 sample is taken */
        float voltageSampleSum   = 0;               /* accumulation of sample readings */
        float voltageSampleCount = 0;               /* to count number of sample. */
        float voltageMean ;                         /* to calculate the average value from all samples, in analog values*/ 
        float RMSVoltageMean ;                      /* square roof of voltageMean without offset value, in analog value*/
        float adjustRMSVoltageMean;
        int FinalRMSVoltage;
        
        int Vout = A9;             // Which pin to measure voltage Value (Pin A0 is reserved for button function)
        float voltageSampleRead2  = 0;               /* to read the value of a sample in analog including voltageOffset1 */
        float voltageLastSample2  = 0;               /* to count time for each sample. Technically 1 milli second 1 sample is taken */
        float voltageSampleSum2   = 0;               /* accumulation of sample readings */
        float voltageSampleCount2 = 0;               /* to count number of sample. */
        float voltageMean2 ;                         /* to calculate the average value from all samples, in analog values*/ 
        float RMSVoltageMean2 ;                      /* square roof of voltageMean without offset value, in analog value*/
        float adjustRMSVoltageMean2;
        int FinalRMSVoltage2;

             // Which pin to measure voltage Value (Pin A0 is reserved for button function)
        float voltageSampleRead3  = 0;               /* to read the value of a sample in analog including voltageOffset1 */
        float voltageLastSample3  = 0;               /* to count time for each sample. Technically 1 milli second 1 sample is taken */
        float voltageSampleSum3   = 0;               /* accumulation of sample readings */
        float voltageSampleCount3 = 0;               /* to count number of sample. */
        float voltageMean3 ;                         /* to calculate the average value from all samples, in analog values*/ 
        float RMSVoltageMean3 ;                      /* square roof of voltageMean without offset value, in analog value*/
        float adjustRMSVoltageMean3;
        int FinalRMSVoltage3;
        
        /* 1.1- AC Voltage Offset */

        
        
        float voltageOffset1 =0.00 ;          // to Offset deviation and accuracy. Offset any fake current when no current operates. 
                                                    // Offset will automatically callibrate when SELECT Button on the LCD Display Shield is pressed.
                                                    // If you do not have LCD Display Shield, look into serial monitor to add or minus the value manually and key in here.
                                                    // 26 means add 26 to all analog value measured.
        float voltageOffset2 = 0.00;          // too offset value due to calculation error from squared and square root
        
        float voltageOffset3 =0.00 ;          // to Offset deviation and accuracy. Offset any fake current when no current operates. 
                                                    // Offset will automatically callibrate when SELECT Button on the LCD Display Shield is pressed.
                                                    // If you do not have LCD Display Shield, look into serial monitor to add or minus the value manually and key in here.
                                                    // 26 means add 26 to all analog value measured.
        float voltageOffset4 = 0.00;          // too offset value due to calculation error from squared and square root
                
        float voltageOffset5 =0.00 ;          // to Offset deviation and accuracy. Offset any fake current when no current operates. 
                                                    // Offset will automatically callibrate when SELECT Button on the LCD Display Shield is pressed.
                                                    // If you do not have LCD Display Shield, look into serial monitor to add or minus the value manually and key in here.
                                                    // 26 means add 26 to all analog value measured.
        float voltageOffset6 = 0.00;          // too offset value due to calculation error from squared and square root
        
String readString; //main captured String
String Arus; //data String
String Tegangan;
String Energi;
String Biaya;

int ind1; // , locations
int ind2;
int ind3;
int ind4;



 int c =0;
int a = 0;
int b = 0;
int d = 0;
int mA = 0;
float baca[10];
float oke = 0;


void setup() {
  
   Serial.begin(9600); 
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    }

    
   uint16_t ID = tft.readID();
    if (ID == 0xD3D3) ID = 0x9481; 

    tft.begin(ID);
/*
    tft.setRotation(3);
    tft.fillScreen(WHITE);
    tft.setFont(NULL); 
    tft.setCursor(380, 100);
    tft.setTextColor(RED);
    tft.setTextSize(4);
    tft.print("TM");
    
    tft.setFont(&FreeSerifItalic9pt7b); 
    tft.setCursor(70, 170);
    tft.setTextColor(GREEN);
    tft.setTextSize(4);
    tft.print("MADEENA");
    tft.setFont(NULL); 
    tft.setCursor(250, 180);
    tft.setTextColor(BLACK);
    tft.setTextSize(1);
    tft.print("Imanging System Forever");
    
    delay(5000);*/
    
    tft.setRotation(3);
    tft.fillScreen(WHITE); 
    tft.drawRect(3, 3, 470 ,313 , RED);
    tft.drawRect(4, 4, 469 ,312 , RED);
    tft.drawRect(5, 5, 467 , 310, BLACK);

    tft.drawRect(10, 10, 456, 50, RED);
    tft.drawRect(11, 11, 454, 48, RED);
    tft.drawRect(12, 12, 452, 46, BLACK);
    tft.setFont(NULL);
    tft.setCursor(60, 20);
    tft.setTextColor(BLACK);
    tft.setTextSize(3);
    tft.print("DIGITAL PANEL METER");


    tft.setCursor(25,80);
    tft.setTextColor(RED);
    tft.setTextSize(1);
    tft.setFont(&FreeSans12pt7b);
    tft.print("LV  :");

    tft.setCursor(175,84);
    tft.setTextColor(BLACK);
    tft.setTextSize(1);
    tft.setFont(&FreeSans12pt7b);
    tft.print("kV  :");

    tft.setCursor(340,84);
    tft.setTextColor(BLACK);
    tft.setTextSize(1);
    tft.setFont(&FreeSans12pt7b);
    tft.print("mA  :");
}


void loop() {
  
    
 if (Serial.available())  {
         
          char c = Serial.read();  //perintah membaca data dari arduino oleh esp8266
            if (c == '*') {
              //do stuff
              Serial.println();
              Serial.println(readString); //prints string to serial port out
             
              ind1 = readString.indexOf(',');  //finds location of first ,
              Arus = readString.substring(0, ind1);   //captures first data String


              Serial.println();
              Serial.println();


              float Arus_read = Arus.toFloat() ;
              int mA = Arus_read;//dari tipe data string ke tipe float 
              float a = millis();
              Serial.println();
              Serial.print("Arus = ");
              Serial.println(mA);

            //Arus
              tft.fillRect(340, 100, 100, 75, BLACK);         
              tft.setCursor(350,145);
              tft.setTextColor(GREEN);
              tft.setTextSize(2);
              tft.setFont(&FreeSans9pt7b);
              tft.print(mA);
              
              readString=""; //clears variable for new input
              Arus="";
             } 
          else {     
                readString += c; //makes the string readString
                }
  
          }

                  


         
                      
                  
        // Inisialisasi V & A 
          if(micros() >= voltageLastSample + 1000 )                                                                      /* every 0.2 milli second taking 1 reading */
              {
                             //Arus

                                //tegangan input
                voltageSampleRead = (analogRead(Vin)- 512)+ voltageOffset1;                             /* read the sample value including offset value 512*/
                voltageSampleSum = voltageSampleSum + sq(voltageSampleRead) ;                                             /* accumulate total analog values for each sample readings*/
                voltageSampleCount = voltageSampleCount + 1;                                                              /* to move on to the next following count */
                voltageLastSample = micros() ; 
                
                                //tegangan output
                voltageSampleRead2 = (analogRead(Vout)- 512)+ voltageOffset3;                             /* read the sample value including offset value 512*/
                voltageSampleSum2 = voltageSampleSum2 + sq(voltageSampleRead2) ;                                             /* accumulate total analog values for each sample readings*/
                voltageSampleCount2 = voltageSampleCount2 + 1;                                                              /* to move on to the next following count */
                voltageLastSample2 = micros() ;

                 
                


              } 
         


          if(voltageSampleCount == 1000)                                                                                /* after 4000 count or 800 milli seconds (0.8 second), do the calculation and display value*/
              {
                

                      
                 //LV
                   //RMS
                    voltageMean = voltageSampleSum/voltageSampleCount;                                                        /* calculate average value of all sample readings taken*/
                    RMSVoltageMean = (sqrt(voltageMean)*1.5);                                                                 // The value X 1.5 means the ratio towards the module amplification.      
                    adjustRMSVoltageMean = RMSVoltageMean + voltageOffset2;                                                   /* square root of the average value including offset value */                                                                                                                                                       /* square root of the average value*/                                                                                                             
                    FinalRMSVoltage = (RMSVoltageMean) + voltageOffset2; 

                   //Fungsi transfer
                    //int k = ((0.8182*FinalRMSVoltage)-117);                                       //((0,8182*FinalRMSVoltage)-117);
                    //int k = ((0.5438*FinalRMSVoltage)-23.884);  
                    //((124/221)*(FinalRMSVoltage-164))// 
                      int lv = ((0.556561086)*(FinalRMSVoltage-164))+77,decimalPrecision;/* this is the final RMS voltage*/
                          int LV = (lv/1.15)+72;
                          if(LV <= 2.5)                                                                                /* to eliminate any possible ghost value*/
                              {
                                LV = 0;
                              }
                    
                      
                 //KV
                   //RMS
                    voltageMean2 = voltageSampleSum2/voltageSampleCount2;                                                        /* calculate average value of all sample readings taken*/
                    RMSVoltageMean2 = (sqrt(voltageMean2))*1.5;                                                                 // The value X 1.5 means the ratio towards the module amplification.      
                    adjustRMSVoltageMean2 = RMSVoltageMean2 + voltageOffset4;                                                   /* square root of the average value including offset value */                                                                                                                                                       /* square root of the average value*/                                                                                                             
                    FinalRMSVoltage2 = (RMSVoltageMean2) + voltageOffset4; 

                   //Fungsi transfer
                    int k2 = ((0.3428*FinalRMSVoltage2)-67.378);                                       //((0,8182*FinalRMSVoltage)-117);
                                                                                                                //((124/221)*(FinalRMSVoltage-164))// 
                    //Rata-Rata Akhir   
                    float nilai2 = k2/1000;
                    int kV  = (k2-nilai2);
                    
                    if(kV <= 2.5)                                                                                 /* to eliminate any possible ghost value*/
                      {
                        kV = 0;
                      }
           
                    Serial.print("LV : ");    
                    Serial.println(LV);
            
                    Serial.print("kV  : ");    
                    Serial.println(kV);
                    Serial.println(" ");


                //LV
                    tft.fillRect(20, 100, 140, 75, BLACK);
                    tft.setCursor(30, 145);
                    tft.setTextColor(GREEN);
                    tft.setTextSize(2);
                    tft.setFont(&FreeSans9pt7b);
                    tft.print(LV-58);
               //kV
                    tft.fillRect(180, 100, 140, 75, BLACK);
                    tft.setCursor(190,145);
                    tft.setTextColor(GREEN);
                    tft.setTextSize(2);
                    tft.setFont(&FreeSans9pt7b);
                    tft.print(kV-2);
                //MA
                   // tft.fillRect(340, 100, 100, 75, BLACK);  


                    

              
                               
                    voltageSampleSum =0;                                                                                      /* to reset accumulate sample values for the next cycle */
                    voltageSampleCount =0;
                    voltageSampleSum2 =0;                                                                                      /* to reset accumulate sample values for the next cycle */
                    voltageSampleCount2 =0;  
                    }


                   
                   


}
