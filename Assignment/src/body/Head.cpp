#include "Head.h"

// Initialize static members of the class
Shape Head::shape;

// Constructor
Head::Head(ColorR& colorR, ColorO& colorO)
	: colorR(colorR), colorO(colorO) {}

// Destructor
Head::~Head() {}

// Draw the eye
void Head::eye(LPCSTR texturePath) {
	glPushMatrix();
	glTranslated(0, 37, 0);
	glRotated(90, 1, 0, 0);

	GLdouble radius = 0;
	GLdouble angle = 90;
	GLdouble angle2 = 90;
	GLdouble k = 0;
	for (int i = 45; i < 90; i++) {
		for (int j = 0; j < 5; j++) {
			glColor3d(colorR.colorR7, colorO.colorO7, 0);
			k = (GLdouble)i + j;
			glPointSize(2.5);

			glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

			BITMAP BMP;
			GLuint texture(0);

			HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), texturePath, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

			GetObject(hBMP, sizeof(BMP), &BMP);

			glEnable(GL_TEXTURE_2D);
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

			glPushMatrix();
			glRotated(20, 0, 1, 0);

			// eye
			glColor3d(200, 200, 255);
			radius = (angle - j) * 3.142 / 180;
			glBegin(GL_POINTS);
			glVertex3d(cos(radius) * 5, sin(radius) * 5, 2.5 - j * 0.1);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glRotated(20, 0, -1, 0);
			radius = (angle2 + j) * 3.142 / 180;
			glBegin(GL_POINTS);
			glVertex3d(cos(radius) * 5, sin(radius) * 5, 2.5 - j * 0.1);
			glEnd();
			glPopMatrix();

			glDisable(GL_TEXTURE_2D);
			DeleteObject(hBMP);
			glDeleteTextures(1, &texture);
		}
		angle--;
		angle2++;
	}

	glPopMatrix();
}

// Draw the head of the robot
void Head::DrawHead(GLdouble radius, LPCSTR mouthTexturePath) {
	glPushMatrix();
	glTranslated(0, 35, 0);
	glColor3d(colorR.colorR2, colorO.colorO2, 0);
	glScaled(1, 1.35, 1);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	BITMAP BMP;
	GLuint texture(0);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), mouthTexturePath, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	shape.sphere(5);

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	glPopMatrix();

	glColor3d(colorR.colorR2, colorO.colorO2, 0);
	glPushMatrix();
	glTranslated(0, 35, -2.5);

	glPushMatrix();
	glColor3d(colorR.colorR, colorO.colorO, 0);
	glTranslated(0, 0, 5);

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 36.5, 0);
	glRotated(-90, 0, 1, 0);

	for (float k = 0; k < 10; k++) {
		glTranslated(0, k * 0.01, 0);
		for (float i = 0; i < 105; i++) {
			glColor3d(colorR.colorR6 + k * 0.02, 0.1 + colorO.colorO6, 0);
			radius = i * 3.142 / 180;

			glBegin(GL_LINES);
			glVertex3d(cos(radius) * 5, sin(radius) * 5, 0);
			glVertex3d(cos(radius) * 2.5, sin(radius) * 2.5, -2.5);
			glEnd();

			glBegin(GL_LINES);
			glVertex3d(cos(radius) * 2.5, sin(radius) * 2.5, 2.5);
			glVertex3d(cos(radius) * 5, sin(radius) * 5, 0);

			glEnd();
		}
	}

	glPopMatrix();

	eye("res/textures/rasengan2.bmp");
}
