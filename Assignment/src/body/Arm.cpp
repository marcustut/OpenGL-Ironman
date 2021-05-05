#include "Arm.h"

// Init static member
Shape Arm::shape;

// Constructor
Arm::Arm(ColorR& colorR, ColorO& colorO)
	: shoulderRadius(0), colorR(colorR), colorO(colorO), hand(colorR, colorO) {
}

// Destructor
Arm::~Arm() {}

void Arm::lowerArmArmor() {
	glPushMatrix();
	glTranslated(-1.5, 0, 0);
	glRotated(45, 0, -2, 1);
	shape.disk(0, 2, 3, 3);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 1.25, 1);
	shape.disk(0, 2, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.5, 0, 0);
	glRotated(-45, 0, -2, 1);
	shape.disk(0, 2, 3, 3);
	glPopMatrix();
}

void Arm::lowerArm() {
	//first layer
	glColor3f(colorR.colorR7, colorO.colorO7 * 1.5, 0);
	glPushMatrix();
	glTranslated(0, -4, 0);
	glRotated(30, -1, 0, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -4, -1.5);
	glRotated(30, 1, 0, 0);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -4, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -4, -1.5);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	//second layer
	glColor3f(colorR.colorR7 + 0.1, colorO.colorO7 * 1.75, 0);
	glPushMatrix();
	glTranslated(0, -5.5, 0);
	glRotated(30, -1, 0, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -5.5, -1.5);
	glRotated(30, 1, 0, 0);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -5.5, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -5.5, -1.5);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	//third layer
	glColor3f(colorR.colorR6, colorO.colorO6, 0);
	glPushMatrix();
	glTranslated(0, -7, 0);
	glRotated(30, -1, 0, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -7, -1.5);
	glRotated(30, 1, 0, 0);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -7, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -7, -1.5);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	//forth layer
	glColor3f(colorR.colorR5, colorO.colorO5, 0);
	glPushMatrix();
	glTranslated(0, -8.5, 0);
	glRotated(30, -1, 0, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -8.5, -1.5);
	glRotated(30, 1, 0, 0);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -8.5, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -8.5, -1.5);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	//fifth layer
	glColor3f(colorR.colorR4, colorO.colorO4, 0);
	glPushMatrix();
	glTranslated(0, -10, 0);
	glRotated(30, -1, 0, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -10, -1.5);
	glRotated(30, 1, 0, 0);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -10, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -10, -1.5);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	//sixth layer
	glColor3f(colorR.colorR3, colorO.colorO3, 0);
	glPushMatrix();
	glTranslated(0, -11.5, 0);
	glRotated(30, -1, 0, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -11.5, -1.5);
	glRotated(30, 1, 0, 0);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -11.5, 0);
	lowerArmArmor();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -11.5, -1.5);
	glRotated(180, 0, 1, 0);
	lowerArmArmor();
	glPopMatrix();
}

void Arm::upperArm() {
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

	glPushMatrix();
	glTranslated(0, -12, -0.75);
	glRotated(90, 1, 0, 0);
	shape.cylinder(1.5, 2, 10, 30, 30);
	shape.disk(0, 1.5, 30, 30);
	glPushMatrix();
	glTranslated(0, 0, 10);
	shape.disk(0, 2, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);
}

void Arm::shoulder(GLdouble x) {
	GLdouble color = 0, color2 = 0, color3 = 0;

	glPushMatrix();

	glTranslated(x, 26, -4);

	for (float i = 0; i < 180; i++) {
		shoulderRadius = i / 180 * 3.142;
		glColor3d(color, colorO.colorO * color, 0);
		glBegin(GL_LINES);
		glVertex3d(cos(shoulderRadius) * 4, sin(shoulderRadius) * 4, 0);
		glVertex3d(cos(shoulderRadius) * 4, sin(shoulderRadius) * 4, 8);
		glEnd();

		if (i < 90)
			color += 0.01;
		else
			color -= 0.01;
	}
	glBegin(GL_POLYGON);
	for (float i = 0; i < 180; i++) {
		glColor3d(color2, colorO.colorO * color2, 0);
		shoulderRadius = i / 180 * 3.142;

		glVertex3d(cos(shoulderRadius) * 4, sin(shoulderRadius) * 4, 0);


		if (i < 90)
			color2 += 0.01;
		else
			color2 -= 0.01;
	}
	glEnd();

	glBegin(GL_POLYGON);

	for (float i = 0; i < 180; i++) {
		glColor3f(color3, colorO.colorO * color3, 0);
		shoulderRadius = i / 180 * 3.142;

		glVertex3f(cos(shoulderRadius) * 4, sin(shoulderRadius) * 4, 8);


		if (i < 90)
			color3 += 0.01;
		else
			color3 -= 0.01;
	}
	glEnd();

	glPopMatrix();
}

void Arm::leftWholeArm(GLdouble arm, GLdouble arm2b, GLdouble rotateFinger, GLdouble handRotate, GLdouble upFinger, GLdouble upFinger2, GLdouble upFinger3) {
	glPushMatrix();
	shoulder(-14.15);
	glTranslatef(-15, 0, 0);

	glPushMatrix();
	glTranslatef(1, 24, 0);
	glRotatef(arm2b, 1, 0, 0);
	glRotatef(arm, 0, 0, 1);
	glTranslatef(-1, -24, 0);
	glRotatef(180, 1, 0, 0);
	glRotatef(89, 0, -1, 0);

	glPushMatrix();
	glTranslatef(0, -12.5, 0);
	glTranslatef(0, 0, -0.75);
	glRotatef(-rotateFinger, 0, 1, 0);
	glTranslatef(0, 0, 0.75);
	glRotatef(-upFinger2, 1, 0, 0);
	glRotatef(-upFinger3, 0, 0, 1);
	glTranslatef(0, 12.5, 0);

	glPushMatrix();
	glTranslatef(0, -2.5, -0.75);
	glRotatef(handRotate, 1, 0, 0);
	glTranslatef(0, 2.5, 0.75);

	glTranslatef(0, 1.5, 0.5);
	hand.DrawHand(2.5, 60, -1.05, 1.05, -2.1, 1, upFinger);
	glPopMatrix();

	lowerArm();
	glPopMatrix();

	upperArm();
	glPopMatrix();

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	BITMAP BMP;
	GLuint texture(0);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "res/textures/bronze2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glPushMatrix();
	glColor3f(colorR.colorR4, colorO.colorO4, 0);
	glTranslatef(0.75, 24, 0);
	shape.sphere(3);
	glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);
}

void Arm::rightWholeArm(GLdouble arm, GLdouble arm2, GLdouble rotateFinger, GLdouble handRotate, GLdouble upFinger, GLdouble upFinger2, GLdouble upFinger3) {
	shoulder(14.15);

	glPushMatrix();
	glTranslatef(15, 0, 0);

	glPushMatrix();
	glTranslatef(-1, 24, 0);
	glRotatef(arm2, 1, 0, 0);
	glRotatef(-arm, 0, 0, 1);
	glTranslatef(1, -24, 0);
	glRotatef(180, 1, 0, 0);
	glRotatef(89, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0, -12.5, 0);
	glTranslatef(0, 0, -0.75);
	glRotatef(rotateFinger, 0, 1, 0);
	glTranslatef(0, 0, 0.75);
	glRotatef(-upFinger2, 1, 0, 0);
	glRotatef(upFinger3, 0, 0, 1);
	glTranslatef(0, 12.5, 0);

	glPushMatrix();
	glTranslatef(0, -2.5, -0.75);
	glRotatef(handRotate, 1, 0, 0);
	glTranslatef(0, 2.5, 0.75);

	glTranslatef(0, 1.5, 0.5);

	hand.DrawHand(-2.5, 60, -1.05, 1.05, 2.1, 0, upFinger);
	glPopMatrix();

	lowerArm();
	glPopMatrix();

	upperArm();
	glPopMatrix();

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	BITMAP BMP;
	GLuint texture(0);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "res/textures/bronze2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glPushMatrix();
	glColor3f(colorR.colorR4, colorO.colorO4, 0);
	glTranslatef(-0.85, 24, 0);
	shape.sphere(3);
	glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

}

void Arm::DrawBothArms(GLdouble arm, GLdouble arm2, GLdouble arm2b, GLdouble rotateFinger, GLdouble handRotate, GLdouble upFinger, GLdouble upFinger2, GLdouble upFinger3, GLdouble size, GLdouble size2, GLdouble size3, GLdouble translateR, GLdouble translateZ, GLdouble rotation, GLdouble x, GLdouble y, GLdouble z) {
	glPushMatrix();
	glTranslatef(0, -5, 0);
	rightWholeArm(arm, arm2, rotateFinger, handRotate, upFinger, upFinger2, upFinger3);
	leftWholeArm(arm, arm2b, rotateFinger, handRotate, upFinger, upFinger2, upFinger3);

	glColor3f(1, 1, 1);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	BITMAP BMP;
	GLuint texture(0);

	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "res/textures/rasengan.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glPushMatrix();
	glTranslatef(0, 0, 7.5);
	glScalef(size, size, size);
	glTranslatef(0, translateR, translateZ);
	glRotatef(rotation, 1, 1, 1);
	shape.sphere(0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x, y, z);
	glTranslatef(35, 32.5, 5);
	glScalef(size2, size2, size2);
	glRotatef(rotation, 1, 1, 1);
	shape.sphere(2.5);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "res/textures/rasengan2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glPushMatrix();
	glTranslatef(-x, y, z);
	glTranslatef(-35, 32.5, 5);
	glScalef(size2, size2, size2);
	glRotatef(rotation, 1, 1, 1);
	shape.sphere(2.5);
	glPopMatrix();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "res/textures/fire.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glPushMatrix();
	glTranslatef(0, 0, z);
	glTranslatef(0, 25, 5);
	glScalef(size3, size3, size3);
	glRotatef(rotation, 1, 1, 1);
	shape.sphere(5);
	glPopMatrix();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);
}