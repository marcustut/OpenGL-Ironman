#include "Leg.h"

// Initialize static members of the class
Shape Leg::shape;

// Constructor
Leg::Leg(ColorR& colorR, ColorO& colorO)
	: colorR(colorR), colorO(colorO) {}

// Destructor
Leg::~Leg() {}

// Draw a footboard
void Leg::footboard() {
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(colorR.colorR3, colorO.colorO3, 0);
	glVertex3d(0, 0.25, 0);
	glVertex3d(0.75, 0.25, 0);
	glVertex3d(0.75, 0, 0);
	glVertex3d(0, 0, 0);

	glVertex3d(0.75, 0, 0);
	glVertex3d(0.75, 0.25, 0);
	glVertex3d(1, 0.25, 0.25);
	glVertex3d(1, 0, 0.25);

	glVertex3d(0, 0.25, 0);
	glVertex3d(0, 0.5, 0.25);
	glVertex3d(0.75, 0.5, 0.25);
	glVertex3d(0.75, 0.25, 0);

	glVertex3d(0, 0.5, 0.25);
	glVertex3d(0, 0.5, 0.5);
	glVertex3d(0.75, 0.5, 0.5);
	glVertex3d(0.75, 0.5, 0.25);

	glVertex3d(0.75, 0.5, 0.25);
	glVertex3d(0.75, 0.5, 0.5);
	glVertex3d(1, 0.25, 0.5);
	glVertex3d(1, 0.25, 0.25);

	glVertex3d(1, 0, 0.25);
	glVertex3d(1, 0, 0.5);
	glVertex3d(1, 0.25, 0.5);
	glVertex3d(1, 0.25, 0.25);

	glVertex3d(0, 0.5, 0.5);
	glVertex3d(0, 0.25, 0.75);
	glVertex3d(0.75, 0.25, 0.75);
	glVertex3d(0.75, 0.5, 0.5);

	glVertex3d(0, 0, 0.75);
	glVertex3d(0, 0.25, 0.75);
	glVertex3d(0.75, 0.25, 0.75);
	glVertex3d(0.75, 0, 0.75);

	glVertex3d(0, 0, 0.75);
	glVertex3d(0, 0.25, 0.75);
	glVertex3d(0.75, 0.25, 0.75);
	glVertex3d(0.75, 0, 0.75);

	glVertex3d(0.75, 0, 0.75);
	glVertex3d(0.75, 0.25, 0.75);
	glVertex3d(1, 0.25, 0.5);
	glVertex3d(1, 0, 0.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3d(colorR.colorR3, colorO.colorO3, 0);
	glVertex3d(0.75, 0.5, 0.25);
	glVertex3d(0.75, 0.25, 0);
	glVertex3d(1, 0.25, 0.25);

	glVertex3d(0.75, 0.5, 0.5);
	glVertex3d(0.75, 0.25, 0.75);
	glVertex3d(1, 0.25, 0.5);

	glVertex3d(0, 0.5, 0.25);
	glVertex3d(0, 0.5, 0.5);
	glVertex3d(-0.25, 1, 0.375);

	glVertex3d(0, 0.25, 0.25);
	glVertex3d(0, 0.25, 0.5);
	glVertex3d(-0.25, 1, 0.375);

	glVertex3d(-0.25, 1, 0.375);
	glVertex3d(0, 0.5, 0.25);
	glVertex3d(0, 0.25, 0.25);

	glVertex3d(-0.25, 1, 0.375);
	glVertex3d(0, 0.5, 0.5);
	glVertex3d(0, 0.25, 0.5);

	glVertex3d(0.75, 0.5, 0.25);
	glVertex3d(0.75, 0.5, 0.5);
	glVertex3d(0.875, 0.75, 0.375);

	glVertex3d(0.75, 0.5, 0.25);
	glVertex3d(1, 0.25, 0.25);
	glVertex3d(0.875, 0.75, 0.375);

	glVertex3d(1, 0.25, 0.25);
	glVertex3d(1, 0.25, 0.5);
	glVertex3d(0.875, 0.75, 0.375);

	glVertex3d(1, 0.25, 0.5);
	glVertex3d(0.75, 0.5, 0.5);
	glVertex3d(0.875, 0.75, 0.375);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.25, 0);
	glVertex3d(0, 0.5, 0.25);
	glVertex3d(0, 0.5, 0.5);
	glVertex3d(0, 0.25, 0.75);
	glVertex3d(0, 0, 0.75);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(0, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 0.75);
	glVertex3d(0.75, 0, 0.75);
	glVertex3d(1, 0, 0.5);
	glVertex3d(1, 0, 0.25);
	glVertex3d(0.75, 0, 0);
	glVertex3d(0, 0, 0);
	glEnd();

	glPopMatrix();
}

// Draw a small leg
void Leg::smallLeg() {
	glBegin(GL_POLYGON);
	glColor3d(0.5, 0.5, 0.5);
	glVertex3d(0, 1, 0);
	glVertex3d(1, 1, 0);
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(0, 0, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 1, 0);
	glVertex3d(2, 1, 1);
	glVertex3d(2, 0, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(2, 0, 1);
	glVertex3d(2, 1, 1);
	glVertex3d(1, 1, 2);
	glVertex3d(1, 0, 2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(1, 0, 2);
	glVertex3d(1, 1, 2);
	glVertex3d(0, 1, 2);
	glVertex3d(0, 0, 2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 2);
	glVertex3d(0, 1, 2);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, 0, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-1, 0, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(0, 1, 0);
	glVertex3d(0, 0, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(0, 1, 0);
	glVertex3d(1, 1, 0);
	glVertex3d(2, 1, 1);
	glVertex3d(1, 1, 2);
	glVertex3d(0, 1, 2);
	glVertex3d(-1, 1, 1);
	glEnd();
}

// Draw the left leg of the robot
void Leg::DrawLeftLeg(LegRotation leftLegRotation, GLdouble jmpTranslation1, GLdouble jmpTranslation2, GLdouble smallLegR3, GLdouble footBoardTY, GLdouble footBoardTX, GLdouble footR1) {
	glTranslated(0, 35, 9);
	glRotated(leftLegRotation.wholeLeg, 1, 0, 0);
	glTranslated(0, -35, -9);

	glPushMatrix();

	glTranslated(0, jmpTranslation1, 0);
	glTranslated(0, 0, jmpTranslation2);

	glTranslated(0, 20, 6);
	glRotated(leftLegRotation.smallLeg, 1, 0, 0);
	glTranslated(0, -20, -6);

	glTranslated(0, 0, 12);
	glRotated(smallLegR3, 1, 0, 0);
	glTranslated(0, 0, -12);

	glPushMatrix();
	// Foot Board
	glPushMatrix();

	glTranslated(0, footBoardTY, 0);
	glTranslated(0, 0, footBoardTX);

	glTranslated(0, 0, 12);
	glRotated(footR1, 1, 0, 0);
	glTranslated(0, 0, -12);

	glTranslated(-3, -2, 12);
	glRotated(90, 0, 1, 0);
	glScaled(10, 7, 8);
	footboard();
	glPopMatrix();

	// Small Leg
	glPushMatrix();
	glTranslated(-1, 1.2, 6);
	glScaled(2, 20, 3);
	smallLeg();
	glPopMatrix();

	glPushMatrix();
	glScaled(0.75, 1, 1);
	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glTranslated(-2.5, 19, 7);
	glRotated(-25, 1, 0, 0);
	glScaled(5, 10, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.2, 0);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glTranslated(-2.5, 19, 7);
	glRotated(-25, 1, 0, 0);
	glScaled(5, 10, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR, colorO.colorO, 0);
	glTranslated(-2.5, 19, 7);
	glRotated(-25, 1, 0, 0);
	glScaled(5, 10, 5);
	glBegin(GL_TRIANGLES);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3, 21, 10.5);
	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glRotated(90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.2, 0);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glRotated(90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR, colorO.colorO, 0);
	glRotated(90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_TRIANGLES);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3, 21, 6.5);
	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glRotated(-90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.2, 0);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glRotated(-90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR, colorO.colorO, 0);
	glRotated(-90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_TRIANGLES);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	// Big leg
	glPushMatrix();
	glTranslated(0, 35, 9);
	glRotated(leftLegRotation.bigLeg, 1, 0, 0);
	glTranslated(0, -35, -9);
	glPushMatrix();
	glTranslated(0, 35, 9);
	glRotated(90, 1, 0, 0);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	BITMAP BMP;
	GLuint texture(0);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "res/textures/darkScale2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glColor3d(colorR.colorR3, colorO.colorO3, 0);

	shape.cylinder(2, 2, 15, 15, 15);

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 20, 9);
	shape.sphere(2);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	glPopMatrix();
}

// Draw the right leg of the robot
void Leg::DrawRightLeg(LegRotation rightLegRotation, GLdouble jmpTranslation1, GLdouble jmpTranslation2, GLdouble smallLegR3, GLdouble footBoardTY, GLdouble footBoardTX, GLdouble footR1) {
	glTranslated(0, 35, 9);
	glRotated(rightLegRotation.wholeLeg, 1, 0, 0);
	glTranslated(0, -35, -9);

	glPushMatrix();

	glTranslated(0, jmpTranslation1, 0);
	glTranslated(0, 0, jmpTranslation2);

	glTranslated(0, 20, 6);
	glRotated(rightLegRotation.smallLeg, 1, 0, 0);
	glTranslated(0, -20, -6);

	glTranslated(0, 0, 12);
	glRotated(smallLegR3, 1, 0, 0);
	glTranslated(0, 0, -12);

	// Foot Board
	glPushMatrix();

	glTranslated(0, footBoardTY, 0);
	glTranslated(0, 0, footBoardTX);

	glTranslated(0, 0, 12);
	glRotated(footR1, 1, 0, 0);
	glTranslated(0, 0, -12);

	glTranslated(-3, -2, 12);
	glRotated(90, 0, 1, 0);
	glScaled(10, 7, 8);
	footboard();
	glPopMatrix();

	// Small Leg
	glPushMatrix();
	glTranslated(-1, 1.2, 6);
	glScaled(2, 20, 3);
	smallLeg();
	glPopMatrix();

	glPushMatrix();
	glScaled(0.75, 1, 1);
	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glTranslated(-2.5, 19, 7);
	glRotated(-25, 1, 0, 0);
	glScaled(5, 10, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.2, 0);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glTranslated(-2.5, 19, 7);
	glRotated(-25, 1, 0, 0);
	glScaled(5, 10, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR, colorO.colorO, 0);
	glTranslated(-2.5, 19, 7);
	glRotated(-25, 1, 0, 0);
	glScaled(5, 10, 5);
	glBegin(GL_TRIANGLES);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3, 21, 10.5);
	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glRotated(90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.2, 0);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glRotated(90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR, colorO.colorO, 0);
	glRotated(90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_TRIANGLES);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3, 21, 6.5);
	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glRotated(-90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.2, 0);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR5, colorO.colorO5, 0);
	glRotated(-90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_POLYGON);
	glVertex3d(0.5, 1, 0);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(1, 0, 0);
	glVertex3d(1, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3d(colorR.colorR, colorO.colorO, 0);
	glRotated(-90, 0, 1, 0);
	glRotated(-15, 1, 0, 0);
	glScaled(4, 8, 5);
	glBegin(GL_TRIANGLES);
	glVertex3d(0.5, 0.8, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(1, 0, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	// Big leg
	glPushMatrix();
	glTranslated(0, 35, 9);
	glRotated(rightLegRotation.bigLeg, 1, 0, 0);
	glTranslated(0, -35, -9);
	glPushMatrix();
	glTranslated(0, 35, 9);
	glRotated(90, 1, 0, 0);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	BITMAP BMP;
	GLuint texture(0);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "res/textures/darkScale2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glColor3d(colorR.colorR3, colorO.colorO3, 0);

	shape.cylinder(2, 2, 15, 15, 15);

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 20, 9);
	shape.sphere(2);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	glPopMatrix();
}
