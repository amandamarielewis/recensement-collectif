//Bibliothèques incluses dans le sketch

#include <U8g2lib.h>
#include <U8x8lib.h>

#include "U8glib.h"
#include <U8glib.h>

#include <Wire.h>
#include <GP2YDustSensor.h>
#include <SPI.h>
#include <SD.h>

//Initialiser notre type spécifique d'écran OLED
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST);  // Dev 0, Fast I2C / TWI
//U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


const uint8_t SHARP_LED_PIN = 10;   // Sharp poussière/particle capteur Led Pin
const uint8_t SHARP_VO_PIN = A0;    // Sharp poussière/particle pin de sortie analogique utilisé pour la lecture 

//Initializer le PM2.5 capteur de poussière
GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1010AU0F, SHARP_LED_PIN, SHARP_VO_PIN);

const int chipSelect = 4;

void setup(void) {
  // mettez votre code d'installation ici, à exécuter une fois
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  dustSensor.begin();


  // voir si la carte est présente et peut être initialisée :
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    //don't do anything more:
    //while (1);
  }
  Serial.println("card initialized.");

  //dustSensor.setBaseline(0.4); // set no dust voltage according to your own experiments
  //dustSensor.setCalibrationFactor(1.1); // calibrate against precision instrument

//  u8g2.begin();  
}

void loop(void) {
  // mettez votre code principal ici, pour l'exécuter de façon répétée :
  // Serial Print dust sensor data
   Serial.print("Dust density: ");
   Serial.print(dustSensor.getDustDensity());
  // Serial.print(" ug/m3; Running average: ");
  // Serial.print(dustSensor.getRunningAverage());
  // Serial.println(" ug/m3");

  // faire une string pour assembler les données à enregistrer :
  String dataString = "";
  
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println(dustSensor.getDustDensity());
    dataFile.close();
    Serial.print("writing to file: ");
    Serial.print(dustSensor.getDustDensity());
    Serial.println(" ug/m3");
  } else {
    Serial.println("error opening file");
  }
//Écran OLED impression poussière capteur données image boucle

  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );

  //delay before we run again
  delay(1000);
}

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.setPrintPos(0, 20); 
  u8g.print("Dust : ");
  u8g.print(dustSensor.getDustDensity());
  u8g.print(" ug/m3");
}
