#include "MatrixCascade.h"
#include "randomMovement.h"


const uint8_t matrixCount = 3;

// pin 12 is connected to the DataIn 
// pin 11 is connected to the CLK 
// pin 10 is connected to LOAD 
MatrixCascade<matrixCount> cascade(12, 11, 10);
randomMovement<matrixCount> point1(cascade, A4), point2(cascade, A4), point3(cascade, A4);


void setup()
{
    int devices = cascade.size();

    //we have to init all devices in a loop
    for(int i=0; i < devices; i++) {
        // Set the brightness. (0..15)
        cascade[i].setIntensity(1);
    }
    cascade[0].setRotation(3);
    cascade[1].setRotation(1);
    cascade[2].setRotation(1);
}


void loop()
{
    point1.off();
    point1.move();
    point1.on();
    
    point2.off();
    point2.move();
    point2.on();
    
    point3.off();
    point3.move();
    point3.on();
    
    delay(50);
}
