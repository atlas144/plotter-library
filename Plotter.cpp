#include "plotter.h"

void Plotter::penDown() {
  servo->write(80);
  delay(20);
}

void Plotter::penUp() {
  servo->write(95);
  delay(20);
}

void Plotter::moveUp() {
  motorY->moveForward();
}

void Plotter::moveUpRight() {
  motorX->moveForward();
  motorY->moveForward();
}

void Plotter::moveRight() {
  motorX->moveForward();
}

void Plotter::moveDownRight() {
  motorX->moveForward();
  motorY->moveBackwards();
}

void Plotter::moveDown() {
  motorY->moveBackwards();
}

void Plotter::moveDownLeft() {
  motorX->moveBackwards();
  motorY->moveBackwards();
}

void Plotter::moveLeft() {
  motorX->moveBackwards();
}

void Plotter::moveUpLeft() {
  motorX->moveBackwards();
  motorY->moveForward();
}

void Plotter::savePosition() {
  uint8_t buffer[2];
  uint16_t positionX = charSize * currentChar;
  uint16_t positionY = charSize * currentLine;

  buffer[0] = positionX & 0xFF;
  buffer[1] = (positionX >> 8) & 0xFF;
  
  EEPROM.update(positionXaddress, buffer[0]);
  EEPROM.update(positionXaddress + 1, buffer[1]);

  buffer[0] = positionY & 0xFF;
  buffer[1] = (positionY >> 8) & 0xFF;
  
  EEPROM.update(positionYaddress, buffer[0]);
  EEPROM.update(positionYaddress + 1, buffer[1]);
}

void Plotter::loadPosition() {
  uint16_t positionX = EEPROM.read(positionXaddress + 1) * 256 + EEPROM.read(positionXaddress);
  uint16_t positionY = EEPROM.read(positionYaddress + 1) * 256 + EEPROM.read(positionYaddress);

  currentLine = positionY / charSize;
  currentChar = positionX / charSize;
}

void Plotter::writeA() {
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveUp();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize/ 5 * 2; i++) {
    moveUpLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeB() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveLeft();
  }  
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeC() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 7; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeD() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeE() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeF() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }

  currentChar++;
}

void Plotter::writeG() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveUpRight();
  }

  currentChar++;
}

void Plotter::writeH() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveUp();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeI() {
  penUp();
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveLeft();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveLeft();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeJ() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 10 * 7; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeK() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveUp();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpLeft();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeL() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeM() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeN() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeO() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 7; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeP() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeQ() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveDownRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeR() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveUpLeft();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeS() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 10 * 3; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpLeft();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10 * 7; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10 * 9; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeT() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveLeft();
  }
  penDown();
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeU() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeV() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 3; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeW() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 5; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeX() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeY() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveUp();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveUpRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeZ() {
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeSpace() {
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeDot() {
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 20; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUpLeft();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUpRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDownRight();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveDownLeft();
  }
  for (uint16_t i = 0; i < charSize / 20; i++) {
    moveLeft();
  }
  penUp();
  for (uint16_t i = 0; i < charSize; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveRight();
  }

  currentChar++;
}

void Plotter::writeDash() {
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveUp();
  }

  currentChar++;
}

void Plotter::writePlus() {
  penUp();
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveDown();
  }
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveRight();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveRight();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize / 5 * 2; i++) {
    moveDown();
  }
  penDown();
  for (uint16_t i = 0; i < charSize / 5 * 4; i++) {
    moveUp();
  }
  penUp();
  for (uint16_t i = 0; i < charSize / 10; i++) {
    moveUp();
  }
  for (uint16_t i = 0; i < charSize / 2; i++) {
    moveRight();
  }

  currentChar++;
}

Plotter::Plotter(StepperMotor* motorX, StepperMotor* motorY, Servo* servo, uint16_t charSize) : motorX(motorX), motorY(motorY), servo(servo), charSize(charSize), currentLine(0), currentChar(0) {
  maxLine = 120 / charSize;
  maxChar = 420 / charSize;
}

void Plotter::setCharSize(uint16_t newSize) {
  charSize = newSize;
}

void Plotter::pageStart() {
  penUp();
  for (uint16_t i = 0; i < charSize * currentChar; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize * 1.5 * currentLine; i++) {
    moveUp();
  }

  currentLine = 0;
  currentChar = 0;
}

void Plotter::newLine() {
  penUp();
  for (uint16_t i = 0; i < charSize  * currentChar; i++) {
    moveLeft();
  }
  for (uint16_t i = 0; i < charSize * 1.5; i++) {
    moveDown();
  }

  currentLine++;
  currentChar = 0;
}

void Plotter::testOrientation() {
  penUp();
  delay(1000);
  penDown();
  delay(1000);
  penUp();
  delay(1000);
  for (uint8_t i = 0; i < 100; i++) {
    moveUp();
  }
  delay(500);
  for (uint8_t i = 0; i < 100; i++) {
    moveRight();
  }
  delay(500);
  for (uint8_t i = 0; i < 100; i++) {
    moveDown();
  }
  delay(500);
  for (uint8_t i = 0; i < 100; i++) {
    moveLeft();
  }
  delay(500);
  for (uint8_t i = 0; i < 50; i++) {
    moveUp();
  }
  delay(500);
  for (uint8_t i = 0; i < 50; i++) {
    moveUpRight();
  }
  delay(500);
  for (uint8_t i = 0; i < 50; i++) {
    moveDownRight();
  }
  delay(500);
  for (uint8_t i = 0; i < 50; i++) {
    moveDownLeft();
  }
  delay(500);
  for (uint8_t i = 0; i < 50; i++) {
    moveUpLeft();
  }
  delay(500);
  for (uint8_t i = 0; i < 50; i++) {
    moveDown();
  }
}

void Plotter::write(String* text) {
  for (uint8_t i = 0; i < text->length(); i++) {
    if (currentChar >= maxChar) {
      newLine();
    }

    if (currentLine < maxLine) {
      switch (text->charAt(i)) {
        case 'A':
        case 'a': {
          writeA();
          break;
        }
        case 'B':
        case 'b': {
          writeB();
          break;
        }
        case 'C':
        case 'c': {
          writeC();
          break;
        }
        case 'D':
        case 'd': {
          writeD();
          break;
        }
        case 'E':
        case 'e': {
          writeE();
          break;
        }
        case 'F':
        case 'f': {
          writeF();
          break;
        }
        case 'G':
        case 'g': {
          writeG();
          break;
        }
        case 'H':
        case 'h': {
          writeH();
          break;
        }
        case 'I':
        case 'i': {
          writeI();
          break;
        }
        case 'J':
        case 'j': {
          writeJ();
          break;
        }
        case 'K':
        case 'k': {
          writeK();
          break;
        }
        case 'L':
        case 'l': {
          writeL();
          break;
        }
        case 'M':
        case 'm': {
          writeM();
          break;
        }
        case 'N':
        case 'n': {
          writeN();
          break;
        }
        case 'O':
        case 'o': {
          writeO();
          break;
        }
        case 'P':
        case 'p': {
          writeP();
          break;
        }
        case 'Q':
        case 'q': {
          writeQ();
          break;
        }
        case 'R':
        case 'r': {
          writeR();
          break;
        }
        case 'S':
        case 's': {
          writeS();
          break;
        }
        case 'T':
        case 't': {
          writeT();
          break;
        }
        case 'U':
        case 'u': {
          writeU();
          break;
        }
        case 'V':
        case 'v': {
          writeV();
          break;
        }
        case 'W':
        case 'w': {
          writeW();
          break;
        }
        case 'X':
        case 'x': {
          writeX();
          break;
        }
        case 'Y':
        case 'y': {
          writeY();
          break;
        }
        case 'Z':
        case 'z': {
          writeZ();
          break;
        }
        case ' ': {
          writeSpace();
          break;
        }
        case '.': {
          writeSpace();
          break;
        }
        case '-': {
          writeSpace();
          break;
        }
        case '/': {
          writeSpace();
          break;
        }
        case '+': {
          writeSpace();
          break;
        }
        default: {
          break;
        }
      }

      savePosition();
    }
  }
}
