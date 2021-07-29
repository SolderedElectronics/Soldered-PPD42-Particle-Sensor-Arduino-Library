/**
 **************************************************
 *
 * @file        PPD42-SOLDERED.h
 * @brief       Header file for the PPD42 sensor.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#ifndef __PPD42_SOLDERED__
#define __PPD42_SOLDERED__

#include "Arduino.h"

class PPD42
{
  public:
    PPD42(int _pin);

    void begin();
    long getConcentration();
    long getLastConcentration();

  private:
    int pin;
    unsigned long duration;
    unsigned long startTime;
    unsigned long endtime;
    unsigned long sampletime_ms = 30000;
    unsigned long lowpulseoccupancy = 0;
    long lastConcentration;
    float ratio = 0;
};

#endif
