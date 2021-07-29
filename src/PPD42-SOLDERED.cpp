/**
 **************************************************
 *
 * @file        PPD42-SOLDERED.cpp
 * @brief       Implements a PPD42 Sensor Board by Soldered
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/


#include "PPD42-SOLDERED.h"

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Pin to which the sensor is connected.
 */
PPD42::PPD42(int _pin)
{
    pin = _pin;
    startTime = millis();
}

/**
 * @brief                   Sensor initialization method.
 */
void PPD42::begin()
{
    pinMode(pin, INPUT);
}

/**
 * @brief                   Method to read the sensor value.
 *
 * @return float            Air particle concentration in particles per
 */
long PPD42::getConcentration()
{
    startTime = millis();

    for (int i = 0; i < 50; ++i)
    {
        duration = pulseIn(pin, LOW);
        lowpulseoccupancy += duration;
        endtime = millis();

        if ((endtime - startTime) > sampletime_ms)
        {
            ratio = (lowpulseoccupancy - endtime + startTime) / (sampletime_ms * 10.0); // Integer percentage 0=>100
            long concentration =
                1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62; // using spec sheet curve
            // Serial.print("lowpulseoccupancy:");
            // Serial.print(lowpulseoccupancy);
            // Serial.print("\n");
            // Serial.print("ratio:");
            // Serial.print(ratio);
            // Serial.print("\n");
            // Serial.print("PPDNS42:");
            // Serial.println(concentration);
            // Serial.print("\n");

            lowpulseoccupancy = 0;
            return lastConcentration = concentration;
        }

        delay(1000);
    }

    return -1;
}

long PPD42::getLastConcentration()
{
    return lastConcentration;
}