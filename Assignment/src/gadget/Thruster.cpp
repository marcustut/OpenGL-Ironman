#include "Thruster.h"

// Constructor
Thruster::Thruster(LPCSTR texturePath) : texture(0) {
	// Load the specified bmp file
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), texturePath, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// Retrieves graphical information from the bmp file
	GetObject(hBMP, sizeof(BMP), &BMP);
}

// Destructor
Thruster::~Thruster() {
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);
}

// Draw the thruster when robot is flying
void Thruster::Draw(GLdouble wingRotation, GLdouble wingSize) {
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glPushMatrix();

	glEnable(GL_LIGHTING);
	glPushMatrix();
	glColor3d(245, 245, 255);
	glTranslated(0, 13.5, 0);

	glPushMatrix();

	glTranslated(0, 0, -5);
	glRotated(wingRotation, 0, 1, 0);
	glTranslated(0, 0, 5);
	glScaled(wingSize, wingSize, 1);

	// Left Hand Thruster
	glBegin(GL_POLYGON);
	glVertex3d(-21, -17, 0);
	glVertex3d(-16, -17, 0);
	glVertex3d(-18.5, -25, 0);
	glEnd();

	// Right Hand Thruster
	glBegin(GL_POLYGON);
	glVertex3d(21, -17, 0);
	glVertex3d(16, -17, 0);
	glVertex3d(18.5, -25, 0);
	glEnd();

	// Left Leg Thruster
	glBegin(GL_POLYGON);
	glVertex3d(-8, -45, 0);
	glVertex3d(-5, -45, 0);
	glVertex3d(-6.5, -53, 0);
	glEnd();

	// Right Leg Thruster
	glBegin(GL_POLYGON);
	glVertex3d(6, -45, 0);
	glVertex3d(3, -45, 0);
	glVertex3d(4.5, -53, 0);
	glEnd();

	glPopMatrix();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}