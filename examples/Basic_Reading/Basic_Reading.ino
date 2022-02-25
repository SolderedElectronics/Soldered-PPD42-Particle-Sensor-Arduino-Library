/**
 **************************************************
 *
 * @file        Basic_Reading.ino
 * @brief       Basic example of reading data from the sensor.
 *
 *  Connect the sensor as shown here:
 *      https://create.arduino.cc/projecthub/infoelectorials/project-010-arduino-grove-dust-sensor-ppd42ns-project-ab5f5e
 *
 *  For more info visit https://solde.red/SKU
 *
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#include "PPD42-SOLDERED.h"

#define PPD42_PIN 8

PPD42 ppd(PPD42_PIN);

void setup()
{
    Serial.begin(115200); //Start serial communication with PC
    ppd.begin();    //Initialize sensor
}

void loop()
{
    
    Serial.print("Concentration: "); // Read the sensor value
    Serial.println(ppd.getConcentration()); // Can take up to 30s

    Serial.print("Last concentration: "); // Instant
    Serial.println(ppd.getLastConcentration());

    delay(5000);
}
