#pragma once

#include "wtypes.h"
#include "gl/GL.h"

class Thruster {
private:
	HBITMAP hBMP;
	BITMAP BMP;
	GLuint texture;
public:
	Thruster(LPCSTR texturePath);
	~Thruster();

	void Draw(GLdouble wingRotation, GLdouble wingSize);
};