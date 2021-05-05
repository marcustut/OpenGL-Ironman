#include "Hand.h"

// Init static member
Shape Hand::shape;

// Constructor
Hand::Hand(ColorR& colorR, ColorO& colorO): colorR(colorR), colorO(colorO) {}

// Destructor
Hand::~Hand() {}

// Different parts of a hand
void Hand::upperFinger(GLdouble height) {
	glPushMatrix();

	glRotated(90, 1, 0, 0);

	shape.cylinder(0.00001, 0.5, height, 30, 30);

	glPushMatrix();

	glTranslated(0, 0, height);
	shape.disk(0, 0.5, 30, 30);

	glPopMatrix();
	glPopMatrix();
}

void Hand::lowerFinger(GLdouble height) {
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	shape.cylinder(0.5, 0.5, height, 30, 30);
	shape.disk(0, 0.5, 30, 30);

	glPushMatrix();
	glTranslated(0, 0, height);
	shape.disk(0, 0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();
}

void Hand::finger(GLdouble height, GLdouble upFinger) {
	glColor3d(colorR.colorR5, colorO.colorO5, 0);

	glPushMatrix();
	glTranslated(0, -2, 0);
	glRotated(upFinger, 1, 0, 0);
	glTranslated(0, 2, 0);

	glPushMatrix();
	glRotated(upFinger, 1, 0, 0);

	glPushMatrix();
	glTranslated(0, height, 0);
	glRotated(upFinger, 1, 0, 0);
	glTranslated(0, height, 0);

	// upper-part of finger
	upperFinger(height);
	glPopMatrix();

	glTranslatef(0, height, 0);
	// middle-part of finger
	lowerFinger(height);
	glPopMatrix();

	// lower-part of finger
	lowerFinger(height);
	glPopMatrix();
}

void Hand::DrawHand(GLdouble thumb, GLdouble thumbA, GLdouble ring, GLdouble index, GLdouble little, GLdouble rotate, GLdouble upFinger) {
	glPushMatrix();

	// show core inside the hand
	glRotated(180, 1, 0, 0);

	glColor3d(colorR.colorR6, colorO.colorO6, 0);
	shape.disk(0, 2.55, 10, 10);
	glPushMatrix();
	glTranslated(0, 0, 2.5);
	shape.disk(0, 2.55, 10, 10);
	glPopMatrix();

	shape.cylinder(2.55, 2.55, 2.5, 10, 10);

	float radius = 0;

	glPushMatrix();
	if (rotate == 1)
		glRotated(180, 0, 0, 1);
	for (double i = 0; i < 360; i++) {
		radius = i * 3.142 / 180;

		if (i < 180)
			glColor3d((i / 250 + colorR.colorR7), colorO.colorO7 * 1.5, 0);
		else
			glColor3d((colorR.colorR2 + 0.12) - (0.004 * (i - 180)), colorO.colorO7 * 1.5, 0);

		glBegin(GL_LINES);
		glVertex3d(cos(radius) * 2.5, sin(radius) * 2.5, 0);
		glVertex3d(cos(radius) * 4.375, sin(radius) * 4.375, 1.25);

		glVertex3d(cos(radius) * 4.375, sin(radius) * 4.375, 1.25);
		glVertex3d(cos(radius) * 2.5, sin(radius) * 2.5, 2.5);
		glEnd();
	}
	glPopMatrix();


	glPopMatrix();

	//move the core deep inside the hand
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	BITMAP BMP;
	GLuint texture(0);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "res/textures/rasengan2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);


	glPushMatrix();
	glColor3d(245, 245, 255);
	glTranslated(0, 0, -1.5);
	shape.sphere(1.5);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	glPushMatrix();

	//middle finger
	glTranslated(0, 0, -1.5);
	glRotated(180, 0, 1, 0);
	glTranslated(0, 4, 0);
	finger(2, upFinger);

	//ring finger
	glPushMatrix();
	glTranslated(ring, 0, 0);
	finger(1.75, upFinger);
	glPopMatrix();

	//index finger
	glPushMatrix();
	glTranslated(index, 0, 0);
	finger(1.75, upFinger);
	glPopMatrix();

	//little finger
	glPushMatrix();
	glTranslated(little, 0, 0);
	finger(1.5, upFinger);
	glPopMatrix();

	//thumb
	glPushMatrix();
	glTranslated(thumb, -3.5, 0);
	glRotated(thumbA, 0, 0, 1);

	//customise (without low finger)
	glPushMatrix();
	glRotated(upFinger, 1, 0, 0);
	glPushMatrix();
	glTranslated(0, 1.5, 0);
	glRotated(upFinger, 1, 0, 0);
	glTranslated(0, 2, 0);

	// up Finger
	upperFinger(2);
	glPopMatrix();

	glTranslated(0, 1.5, 0);

	// mid finger
	lowerFinger(2);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

