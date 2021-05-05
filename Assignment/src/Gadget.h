#pragma once

#include "gadget/Thruster.h"

class Gadget {
private:
	Thruster thruster;
public:
	Gadget(LPCSTR texturePath);
	~Gadget();

	void Thruster(GLdouble wingRotation, GLdouble wingSize);
};
