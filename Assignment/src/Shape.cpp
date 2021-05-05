#include "Shape.h"

Shape::Shape() {
	// Create a new GLU Quadric and apply configuration
	object = gluNewQuadric();
	gluQuadricDrawStyle(object, GLU_SMOOTH);
	gluQuadricTexture(object, true);
}

Shape::~Shape() {
	// Delete the quadric object when not in use
	gluDeleteQuadric(object);
}

// Draw a sphere
void Shape::sphere(GLdouble size) {
	gluSphere(object, size, 100, 100);
}

// Draw a cylinder
void Shape::cylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks) {
	gluCylinder(object, baseRadius, topRadius, height, slices, stacks);
}

// Draw a disk
void Shape::disk(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint stacks) {
	gluDisk(object, innerRadius, outerRadius, slices, stacks);
}

// Draw a cube
void Shape::cube(GLdouble x1, GLdouble x2, LPCSTR texturePath) {
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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.25, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, 3, 0);
	glTexCoord2d(1, 1);
	glVertex3d(x2, 3, 0);
	glTexCoord2d(1, 0);
	glVertex3d(x1, 0.25, 0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.25, 4);
	glTexCoord2d(0, 1);
	glVertex3d(0, 3, 4);
	glTexCoord2d(1, 1);
	glVertex3d(x2, 3, 4);
	glTexCoord2d(1, 0);
	glVertex3d(x1, 0.25, 4);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 3, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, 3, 4);
	glTexCoord2d(1, 1);
	glVertex3d(x2, 3, 4);
	glTexCoord2d(1, 0);
	glVertex3d(x2, 3, 0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.25, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, 0.25, 4);
	glTexCoord2d(1, 1);
	glVertex3d(x1, 0.25, 4);
	glTexCoord2d(1, 0);
	glVertex3d(x1, 0.25, 0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.25, 4);
	glTexCoord2d(0, 1);
	glVertex3d(0, 3, 4);
	glTexCoord2d(1, 1);
	glVertex3d(0, 3, 0);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0.25, 0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x1, 0.25, 0);
	glTexCoord2d(1, 0);
	glVertex3d(x2, 3, 0);
	glTexCoord2d(1, 1);
	glVertex3d(x2, 3, 4);
	glTexCoord2d(0, 1);
	glVertex3d(x1, 0.25, 4);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);
}

// Draw a triangle
void Shape::triangle(LPCSTR texturePath) {
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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0, 1);
	glVertex3d(0, 2.75, 0);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1.5, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 4);
	glTexCoord2d(0, 1);
	glVertex3d(0, 2.75, 4);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1.5, 4);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0, 4);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1.5, 4);
	glTexCoord2d(0, 1);
	glVertex3d(1, 1.5, 0);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);

	glBegin(GL_QUADS);
	glVertex3d(0, 2.75, 0);
	glVertex3d(1, 1.5, 0);
	glVertex3d(1, 1.5, 4);
	glVertex3d(0, 2.75, 4);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3d(0, 0, 4);
	glVertex3d(0, 2.75, 4);
	glVertex3d(0, 2.75, 0);
	glVertex3d(0, 0, 0);
	glEnd();
}

// Draw a bar
void Shape::bar(GLdouble x1, GLdouble x2) {
	glPushMatrix();

	triangle("res/textures/steel.bmp");

	glPushMatrix();
	glTranslated(0.2, 0, 0);
	glTranslated(0, 2.5, 0);
	glTranslated(0, -2.5, 0);
	cube(x1, x2, "res/textures/steel.bmp");
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	glTranslated(0, 0, 2);
	glRotated(180, 0, 1, 0);
	glTranslated(0, 0, -2);

	triangle("res/textures/steel.bmp");

	glPushMatrix();
	glTranslated(0.2, 2.5, 0);
	glTranslated(0, -2.5, 0);
	cube(x1, x2, "res/textures/steel.bmp");
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	glPushMatrix();
	glTranslated(0, 0, -4);
	triangle("res/textures/steel.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 0, -4);
	glTranslated(0, 2.5, 0);
	glTranslated(0, -2.5, 0);
	cube(x1, x2, "res/textures/steel.bmp");
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	glTranslated(0, 0, 2);
	glRotated(180, 0, 1, 0);
	glTranslated(0, 0, -2);

	glPushMatrix();
	glTranslated(0, 0, 4);
	triangle("res/textures/steel.bmp");
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 2.5, 4);
	glTranslated(0, -2.5, 0);
	cube(x1, x2, "res/textures/steel.bmp");
	glPopMatrix();

	glPopMatrix();
}
