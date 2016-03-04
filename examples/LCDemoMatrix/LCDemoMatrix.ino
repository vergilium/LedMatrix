//We always have to include the library
#include "LedMatrix.h"

/*
 Now we need a LedMatrix to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedMatrix lc(12,11,10);

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.wakeup();
  /* Set the brightness to a medium values */
  lc.setIntensity(8);
  /* and clear the display */
  lc.clear();
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  uint8_t a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  uint8_t r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
  uint8_t d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  uint8_t u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  uint8_t i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  uint8_t n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  uint8_t o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  lc.setRow(0, a[0]);
  lc.setRow(1, a[1]);
  lc.setRow(2, a[2]);
  lc.setRow(3, a[3]);
  lc.setRow(4, a[4]);
  delay(5*delaytime);
  lc.setRow(0, r[0]);
  lc.setRow(1, r[1]);
  lc.setRow(2, r[2]);
  lc.setRow(3, r[3]);
  lc.setRow(4, r[4]);
  delay(5*delaytime);
  lc.setRow(0, d[0]);
  lc.setRow(1, d[1]);
  lc.setRow(2, d[2]);
  lc.setRow(3, d[3]);
  lc.setRow(4, d[4]);
  delay(5*delaytime);
  lc.setRow(0, u[0]);
  lc.setRow(1, u[1]);
  lc.setRow(2, u[2]);
  lc.setRow(3, u[3]);
  lc.setRow(4, u[4]);
  delay(5*delaytime);
  lc.setRow(0, i[0]);
  lc.setRow(1, i[1]);
  lc.setRow(2, i[2]);
  lc.setRow(3, i[3]);
  lc.setRow(4, i[4]);
  delay(5*delaytime);
  lc.setRow(0, n[0]);
  lc.setRow(1, n[1]);
  lc.setRow(2, n[2]);
  lc.setRow(3, n[3]);
  lc.setRow(4, n[4]);
  delay(5*delaytime);
  lc.setRow(0, o[0]);
  lc.setRow(1, o[1]);
  lc.setRow(2, o[2]);
  lc.setRow(3, o[3]);
  lc.setRow(4, o[4]);
  delay(5*delaytime);
  lc.setRow(0, 0);
  lc.setRow(1, 0);
  lc.setRow(2, 0);
  lc.setRow(3, 0);
  lc.setRow(4, 0);
  delay(5*delaytime);
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows() {
  for(int row=0; row<8; row++) {
    delay(delaytime);
    lc.setRow(row, B10100000);
    delay(delaytime);
    lc.setRow(row, 0);
    for(int i=0;i<row;i++) {
      delay(delaytime);
      lc.setRow(row, B10100000);
      delay(delaytime);
      lc.setRow(row, 0);
    }
  }
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns() {
  for(int col=0;col<8;col++) {
    delay(delaytime);
    lc.setCol(col,B10100000);
    delay(delaytime);
    lc.setCol(col,0);
    for(int i=0;i<col;i++) {
      delay(delaytime);
      lc.setCol(col,B10100000);
      delay(delaytime);
      lc.setCol(col,0);
    }
  }
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single() {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime);
      lc.setLed(row,col,true);
      delay(delaytime);
      for(int i=0;i<col;i++) {
        lc.setLed(row,col,false);
        delay(delaytime);
        lc.setLed(row,col,true);
        delay(delaytime);
      }
    }
  }
}

void loop() { 
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}
