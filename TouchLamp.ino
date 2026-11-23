#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_12_13 = CapacitiveSensor(12,13);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
bool lightOn = false;
bool isTouched = false;
int touchThreshold = 200;
void setup()                    
{
   cs_12_13.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode(7, OUTPUT);
   
}

void loop()                    
{
    
    long total =  cs_12_13.capacitiveSensor(30);

    Serial.print(total);
    Serial.print("\n");

    if (total > touchThreshold && not isTouched) {
        if (lightOn) {
            digitalWrite(7, 0);
            lightOn = false;
        }
        else {
            digitalWrite(7, 1);
            lightOn = true;
        }

        isTouched = true;
    } 

    if (total < touchThreshold && isTouched) {
        isTouched = false;
    }




    
    
    

    delay(10);                             // arbitrary delay to limit data to serial port 

}
