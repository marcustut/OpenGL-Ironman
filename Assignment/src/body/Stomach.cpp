#include "Stomach.h"

// Initialize static members of the class
Shape Stomach::shape;

// Constructor
Stomach::Stomach(ColorR& colorR, ColorO& colorO)
	: colorR(colorR), colorO(colorO) {}

// Destructor
Stomach::~Stomach() {}

// Draw the abs
void Stomach::abs() {
	// fifth layer
	glPushMatrix();
	glColor3d(colorR.colorR2, colorO.colorO2, 0);
	glTranslated(0, 9, 0);

	shape.bar(10, 10);

	glPopMatrix();

	// fourth layer
	glPushMatrix();
	glColor3d(colorR.colorR2, colorO.colorO2, 0);
	glTranslated(0, 6, 0);

	shape.bar(8, 10);

	glPopMatrix();

	// third layer
	glPushMatrix();
	glColor3d(colorR.colorR4, colorO.colorO4, 0);
	glTranslated(0, 3, 0);

	shape.bar(8, 10);

	glPopMatrix();

	// second layer (lowest)
	glPushMatrix();
	glColor3d(colorR.colorR4, colorO.colorO4, 0);

	shape.bar(8, 10);

	glPopMatrix();

	// first layer (lowest)
	glPushMatrix();
	glColor3d(colorR.colorR6, colorO.colorO6, 0);
	glTranslated(0, -3, 0);

	shape.bar(10, 10);

	glPopMatrix();
}

// Draw the stomach of the robot
void Stomach::DrawStomach(LPCSTR coreTexturePath) {
	abs();

	glPushMatrix();
	glColor3d(colorR.colorR6, colorO.colorO6, 0);

	shape.bar(10, 10);

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 27, 0);
	glRotated(180, 0, 0, 1);
	abs();
	glPopMatrix();

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	BITMAP BMP;
	GLuint texture(0);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), coreTexturePath, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glPushMatrix();
	glColor3d(245, 245, 255);
	glTranslated(0, 20, 3);
	shape.sphere(2.5);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	//glDisable(GL_TEXTURE_2D);
	//DeleteObject(hBMP);
	//glDeleteTextures(1, &texture);

	glPushMatrix();
	glScaled(1, 1, 0.9999);
	glTranslated(0, 15, 0);
	abs();
	glPopMatrix();
}
