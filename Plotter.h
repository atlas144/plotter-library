#ifndef PLOTTER_H
#define PLOTTER_H

#include <Arduino.h>
#include <EEPROM.h>
#include <Servo.h>
#include <StepperMotor.h>

class Plotter {
  private:
    StepperMotor* motorX;
    StepperMotor* motorY;
    Servo* servo;

    const uint8_t positionXaddress = 0;
    const uint8_t positionYaddress = 2;

    uint16_t charSize;
    uint8_t currentLine;
    uint8_t currentChar;
    uint8_t maxLine;
    uint8_t maxChar;

    void savePosition();
    void loadPosition();

    void penDown();
    void penUp();

    void moveUp();
    void moveUpRight();
    void moveRight();
    void moveDownRight();
    void moveDown();
    void moveDownLeft();
    void moveLeft();
    void moveUpLeft();

    void writeA();
    void writeB();
    void writeC();
    void writeD();
    void writeE();
    void writeF();
    void writeG();
    void writeH();
    void writeI();
    void writeJ();
    void writeK();
    void writeL();
    void writeM();
    void writeN();
    void writeO();
    void writeP();
    void writeQ();
    void writeR();
    void writeS();
    void writeT();
    void writeU();
    void writeV();
    void writeW();
    void writeX();
    void writeY();
    void writeZ();
    void writeSpace();
    void writeDot();
    void writeDash();
    void writeSlash();
    void writePlus();

  public:
    Plotter(StepperMotor* motorX, StepperMotor* motorY, Servo* servo, uint16_t charSize, bool loadPositionOnStart = false);
    void setCharSize(uint16_t newSize);
    void pageStart();
    void newLine();
    void testPlotter();
    void write(String* text);
};

#endif
