

#ifndef lcdController
#define lcdController

#include <Arduino.h>

//data struct

struct pageData
{
    String name;
    int type;
    void *data;
    pageData *nextNode;
};

class lcdScreen
{
public:
    lcdScreen(int pin, int row, int col);
    void testPrint();

    void setup();
    void empty();
    void on();
    void off();
    void scrollLeft();
    void scrollRight();
    void cursorOff();
    void cursorBlock();
    void cursorUnderline();
    void playTone(int duration, int scale, int note);
    void pos(int row, int col);
    // shortcuts for printing at particular positions
    void at(int row, int col, char);
    void at(int row, int col, const char[]);
    void at(int row, int col, String);
    void at(int row, int col, uint8_t);
    void at(int row, int col, int);
    void at(int row, int col, unsigned int);
    void at(int row, int col, long);
    void at(int row, int col, unsigned long);
    void at(int row, int col, long, int);

private:
    int configs[3];
};

class Page
{
public:
    Page();

private:
    String name;
    int id;
}

/*
class ParallaxLCD //: public SoftwareSerial
{
public:
    ParallaxLCD(int pin, int numRows, int numCols);
    void setup(boolean startEmpty = true);

    void on();
    void off();
    void lf();
    void cr();
    void empty();

    void scrollLeft();
    void scrollRight();

    void backLightOn();  //Backlight only available with model numbers 27977, 27979
    void backLightOff(); //Backlight only available with model numbers 27977, 27979

    void pos(int row, int col);

    void cursorUnderline();
    void cursorBlock();
    void cursorOnChrBlink();
    void cursorOff();

    // Make music
    void playTone(int duration, int scale, int note);

    // Custom characters
    void setCustomCharacter(int charIndex, unsigned char bytes[]);
    void printCustomCharacter(int charIndex);

    // shortcuts for printing at particular positions
    void at(int row, int col, char);
    void at(int row, int col, const char[]);
    void at(int row, int col, String);
    void at(int row, int col, uint8_t);
    void at(int row, int col, int);
    void at(int row, int col, unsigned int);
    void at(int row, int col, long);
    void at(int row, int col, unsigned long);
    void at(int row, int col, long, int);

private:
    int _bv[9];
};
*/

#endif
