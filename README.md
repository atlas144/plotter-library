# Plotter library

## Description

A simple library that turns an Arduino and a couple of motors into a 2D plotter. The microcontroller uses two stepper motors to set the horizontal position of the end effector and uses a servo to move it closer and further away from the surface.

## API reference

### Plotter

- main class representing the plotter

#### Private attributes

##### *StepperMotor\** motorX

- stepper motor controlling movement along X axis

##### *StepperMotor\** motorY

- stepper motor controlling movement along Y axis

##### *Servo\** servo

- servo for lifting of the end effector

##### *const uint8_t* positionXaddress

- EEPROM address for storing X position of the end effector
- *default value*: 0

##### *const uint8_t* positionYaddress

- EEPROM address for storing Y position of the end effector
- *default value*: 2

##### *uint16_t* charSize

- size of the character in stepper motor moves (same for both axes)

##### *uint8_t* currentLine

- actual line where the end effector works (starts from 0)

##### *uint8_t* currentChar

- actual character (position in line) where the end effector works (starts from 0)

##### *uint8_t* maxLine

- number of lines on the page

##### *uint8_t* maxChar

- number of chars in the line

#### Private methods

##### *void* savePosition

- saves current EE position (in *stepper motor moves* from start of the page) to the EEPROM

##### *void* loadPosition

- loads saved EE position from the EEPROM (loaded values are divided by the size of the char)

##### *void* penDown

- moves EE to the surface

##### *void* penUp

- lifts EE from the surface

##### *void* moveUp

- moves EE for one *stepper motor move* upwards (along the Y axis)

##### *void* moveUpRight

- moves EE for one *stepper motor move* upwards to the right

##### *void* moveRight

- moves EE for one *stepper motor move* to the right (along the X axis)

##### *void* moveDownRight

- moves EE for one *stepper motor move* downwards to the right

##### *void* moveDown

- moves EE for one *stepper motor move* downwards (along the Y axis)

##### *void* moveDownLeft

- moves EE for one *stepper motor move* downwards to the left

##### *void* moveLeft

- moves EE for one *stepper motor move* to the left (along the X axis)

##### *void* moveUpLeft

- moves EE for one *stepper motor move* upwards to the left

##### *void* writeA

- writes letter A

##### *void* writeB

- writes letter B

##### *void* writeC

- writes letter C

##### *void* writeD

- writes letter D

##### *void* writeE

- writes letter E

##### *void* writeF

- writes letter F

##### *void* writeG

- writes letter G

##### *void* writeH

- writes letter H

##### *void* writeI

- writes letter I

##### *void* writeJ

- writes letter J

##### *void* writeK

- writes letter K

##### *void* writeL

- writes letter L

##### *void* writeM

- writes letter M

##### *void* writeN

- writes letter N

##### *void* writeO

- writes letter O

##### *void* writeP

- writes letter P

##### *void* writeQ

- writes letter Q

##### *void* writeR

- writes letter R

##### *void* writeS

- writes letter S

##### *void* writeT

- writes letter T

##### *void* writeU

- writes letter U

##### *void* writeV

- writes letter V

##### *void* writeW

- writes letter W

##### *void* writeX

- writes letter X

##### *void* writeY

- writes letter Y

##### *void* writeZ

- writes letter Z

##### *void* writeSpace

- writes space sign

##### *void* writeDot

- writes dot sign

##### *void* writeDash

- writes dash sign

##### *void* writePlus

- writes plus sign

#### Public methods

##### **Constructor**

- initializes attributes sets maximal number of lines and chars (depends on char size)
- *arguments*:
  - *StepperMotor\** motorX - see private attributes
  - *StepperMotor\** motorY - see private attributes
  - *Servo\** servo - see private attributes
  - *uint16_t* charSize - see private attributes

##### *void* setCharSize

- changes the size of the char
- *arguments*:
  - *uint16_t* newSize - new value of the `charSize`

##### *void* pageStart

- moves EE to the start of the page (line 0, char 0)

##### *void* newLine

- moves EE to the start of the next line

##### *void* testOrientation

- draws test picture

##### *void* write

- Writes given string. If the number of characters exceeds the line length, EE is moved to the next line. If the entire page is used, the remaining characters are discarded.
- *arguments*:
  - *String\** text - string to be written

## Testing

The library was tested with Arduino Nano, two 28BYJ-48 stepper motors and SG90 servo.

## Dependencies

- EEPROM
- Servo
- Stepper Motor

## Contributing

Contributions are welcome!

## License

The library is licensed under the [MIT license](https://github.com/atlas144/plotter-library/blob/main/LICENSE).
