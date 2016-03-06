//We always have to include the library
#include "MatrixCascade.h"

/*
 Now we need a LedMatrix to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 ***** Please set the number of devices you have *****
 But the maximum default of 8 MAX72XX wil also work.
 */
const uint8_t CascadeSize = 3;
MatrixCascade<CascadeSize> cascade(12, 11, 10);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 30;

/* 
 This time we have more than one device. 
 But all of them have to be initialized 
 individually.
 */
void setup() {
    
    Serial.begin(9600);

    Serial.print( "size: " );
    Serial.println( cascade.size() );

    //  Set the brightness to a medium values
    cascade.setIntensity(1);

    //cascade.clear();

    cascade[1].setRotation(2);
    cascade[2].setRotation(2);
}

/*
void loop() { 
    //read the number cascaded devices
    int devices=cascade.size();
    
    //we have to init all devices in a loop
    for(int row=0; row<8; row++) {
        for(int col=0; col<8; col++) {
            for(int address=0; address<devices; address++) {
                delay(delaytime);
                cascade[address].on(row, col);
                //delay(delaytime);
                //cascade[address].off(row, col);

                Serial.print( "loop :" );
                Serial.print( row );
                Serial.print( "\t" );
                Serial.println( col );
            }
        }
    }
}
*/

void loop() { 
    for(auto &matrix: cascade) {
        matrix.setRotation();
        for(auto row: matrix.rows()) {
            for(auto col: matrix.cols()) {
                delay(delaytime);
                matrix.on(row, col);
            }
        }
        //matrix.clear();
    }

    for(auto &matrix: cascade) {
        for(auto col: matrix.cols()) {
            for(auto row: matrix.rows()) {
                delay(delaytime);
                matrix.off(row, col);
            }
        }
    }

}

