#include "Gadget.h"

Gadget::Gadget(LPCSTR texturePath): thruster("res/textures/rasengan2.bmp") {}

Gadget::~Gadget() {}

// Draw the robot's thruster
void Gadget::Thruster(GLdouble wingRotation, GLdouble wingSize) {
	thruster.Draw(wingRotation, wingSize);
}