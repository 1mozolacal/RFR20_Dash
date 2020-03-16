
#include <Arduino.h>

//#include <SoftwareSerial.h>
#include "lcdController.h"

#define PINOUT 0
#define BOUNCE 1
#define DEBUGGING 2

#define write_BASE 128
// The cursor position for 16 column and 20 column displays uses the same address
// The 16 column display just doesn't show the last 4 columns
#define ROW_SIZE 20

//---------------------page------------------------
Page : Page()
{
	name = 'nothing';
	id = 0;
}

//------------------------LCD Screen bellow-----------------------------

lcdScreen::lcdScreen(int pin, int row, int col)
{
	configs[PINOUT] = pin;
	configs[BOUNCE] = 10;
	configs[DEBUGGING] = false;
}

//------------------Basic functions-----------------------------
//most things bellow here are modification of the parallaxLCD library

void lcdScreen::setup()
{
	//setup Serial connection
	pinMode(configs[PINOUT], OUTPUT);
	delay(configs[BOUNCE]);
	Serial1.begin(9600);
	delay(1000);

	//empty
	Serial1.write(12);
	delay(configs[BOUNCE] * 10);

	//back light on
	Serial1.write(17);
	delay(configs[BOUNCE]);

	//turn on
	Serial1.write(24);
	delay(configs[BOUNCE]);
}

void lcdScreen::testPrint()
{
	Serial1.write(65);
	delay(configs[BOUNCE]);
}
void lcdScreen::empty()
{
	Serial1.write(12);
	delay(configs[BOUNCE] * 10);
}
void lcdScreen::on()
{
	Serial1.write(24);
	delay(configs[BOUNCE]);
}

void lcdScreen::off()
{
	Serial1.write(21);
	delay(configs[BOUNCE]);
}
void lcdScreen::scrollLeft()
{
	Serial1.write(8);
	delay(configs[BOUNCE]);
}

void lcdScreen::scrollRight()
{
	Serial1.write(9);
	delay(configs[BOUNCE]);
}
void lcdScreen::cursorUnderline()
{
	Serial1.write(24);
	delay(configs[BOUNCE]);
}

void lcdScreen::cursorBlock()
{
	Serial1.write(23);
	delay(configs[BOUNCE]);
}

void lcdScreen::cursorOff()
{
	Serial1.write(22);
	delay(configs[BOUNCE]);
}
//Duration: 208 - 214 (1/64th note - 1 whole note[2 secs])
//Scale   : 215 - 219 (3rd - 7th scale)
//Note    : 220 - 232 (A, A#, B, etc..., F#, F, G#)
void lcdScreen::playTone(int duration, int scale, int note)
{

	duration = constrain(duration, 208, 214);
	scale = constrain(scale, 215, 219);
	note = constrain(note, 220, 232);

	Serial1.write(scale);
	Serial1.write(note);
	Serial1.write(duration);
	delay(configs[BOUNCE]);
}
void lcdScreen::pos(int row, int col)
{
	Serial1.write(write_BASE + (col * ROW_SIZE) + row);
}

// shortcuts

void lcdScreen::at(int row, int col, char v)
{
	pos(row, col);
	Serial1.print(v);
}
void lcdScreen::at(int row, int col, const char v[])
{
	pos(row, col);
	Serial1.print(v);
}
void lcdScreen::at(int row, int col, String v)
{
	pos(row, col);
	Serial1.print(v);
}
void lcdScreen::at(int row, int col, uint8_t v)
{
	pos(row, col);
	Serial1.print(v);
}
void lcdScreen::at(int row, int col, int v)
{
	pos(row, col);
	Serial1.print(v);
}
void lcdScreen::at(int row, int col, unsigned int v)
{
	pos(row, col);
	Serial1.print(v);
}
void lcdScreen::at(int row, int col, long v)
{
	pos(row, col);
	Serial1.print(v);
}
void lcdScreen::at(int row, int col, unsigned long v)
{
	pos(row, col);
	Serial1.print(v);
}
void lcdScreen::at(int row, int col, long v, int t)
{
	pos(row, col);
	Serial1.print(v);
}