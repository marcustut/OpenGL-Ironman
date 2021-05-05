#pragma once

#include "wtypes.h"
#include "gl/GL.h"

#include "Utils.h"

class Background {
private:
	HBITMAP hBMP;
	BITMAP BMP;
	GLuint texture;
public:
	Background(LPCSTR texturePath);
	~Background();

	void Draw(GLdouble texCoordX, GLdouble texCoordY, GLdouble texCoordZ);
};
