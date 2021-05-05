#include "Background.h"

Background::Background(LPCSTR texturePath): texture(0) {
	// Load the specified bmp file
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), texturePath, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// Retrieves graphical information from the bmp file
	GetObject(hBMP, sizeof(BMP), &BMP);
}

Background::~Background() {
	DeleteObject(hBMP);
	glDeleteTextures(1, &texture);
}

void Background::Draw(GLdouble texCoordX, GLdouble texCoordY, GLdouble texCoordZ) {
	// Load the bmp grahpics information into OpenGL Texture
	glEnable(GL_TEXTURE_2D);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	// Draw the background with texture loaded
	glBegin(GL_QUADS);

	glTexCoord2d(1, 0);
	glVertex3d(-texCoordX, texCoordY, texCoordZ);
	glTexCoord2d(1, 1);
	glVertex3d(texCoordX, texCoordY, texCoordZ);
	glTexCoord2d(0, 1);
	glVertex3d(texCoordX, -texCoordY, texCoordZ);
	glTexCoord2d(0, 0);
	glVertex3d(-texCoordX, -texCoordY, texCoordZ);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}