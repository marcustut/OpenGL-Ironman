#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#include "Shape.h"
#include "Gadget.h"
#include "Background.h"
#include "Body.h"
#include "Utils.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")
#pragma comment (lib, "winmm.lib")

#define WINDOW_TITLE "Iron-Man"

GLuint texture = 0;
BITMAP BMP;
HBITMAP hBMP = NULL;
GLdouble upFinger = 0, upFinger2 = 0, upFinger3 = 0, rotateFinger = 0, arm = 0, arm2 = 0, arm2b = 0, handRotate = 0;
GLdouble view = 0;
GLdouble size = 0, size2 = 0, size3 = 0, translateR = 0, translateZ = 0, rotation = 0;
GLdouble radius = 0;
GLdouble color = 0, color2 = 0, color3 = 0;

// Arm coordinates
Coordinate armCoord = { 0, 0, 0 };

// For whole robot
GLdouble wholeAngle1 = -90, wholeAngle2 = 0, wholeX = 0, wholeY = 0;

// For 1st leg (jumping + walking)
LegRotation leftLegRotation = { 0, 0, 0 };

// For 2nd leg (jumping + walking)
LegRotation rightLegRotation = { 0, 0, 0 };

// For jumping use
GLdouble smallLegR3 = 0, footR1 = 0;
GLdouble jmpTranslation1 = 0, jmpTranslation2 = 0;
GLdouble footBoardTY = 0, footBoardTX = 0;
char status = 'U';
GLdouble bodyRotate = 0, bodyRotate2 = 0, headRotate = 0, headRotate2 = 0;

boolean rightLegForward = true, startWalking = true, lift = false, cycle = false;
GLdouble coreColor = 0, coreColor2 = 0;
GLdouble wingRotation = 5;
boolean wing2 = true;
GLdouble flyx = 0, flyy = 0, flyz = 0;
GLdouble robotRotate = 0, robotRotate2 = 0;
GLdouble wingSize = 0;

// Color state
ColorR colorR = {
	1, 0.8, 0.7, 0.6, 0.5, 0.4, 0.2
};
ColorO colorO = {
	0, 0, 0, 0, 0, 0, 0
};

// For rendering the background
Background background("res/textures/bg_space_seamless.bmp");

// For drawing the body
Body body(colorR, colorO);

// For drawing the gadget
Gadget gadget("res/textures/rasengan2.bmp");

// Texture movement
Coordinate texCoord = { 80, 80, -79.9 };

// BGM State
bool isPlaying = true;

GLfloat pos[3] = { 30,30,0 };
GLfloat diff[3] = { 1,1,1 };

boolean colorChange = true;
boolean wingRotation2 = true, t = false, r = false, j = false, w = false;
boolean f1 = false, f2 = false, f3 = false, f4 = false;
boolean forward = false, backward = false;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == 'W') {
			backward = false;
			leftLegRotation.wholeLeg = 0;
			rightLegRotation.wholeLeg = 0;
			leftLegRotation.smallLeg = 0;
			rightLegRotation.smallLeg = 0;

			if (forward == true)
				forward = false;
			else
				forward = true;
		}
		else if (wParam == 'S') {
			forward = false;
			leftLegRotation.wholeLeg = 0;
			rightLegRotation.wholeLeg = 0;
			leftLegRotation.smallLeg = 0;
			rightLegRotation.smallLeg = 0;

			if (backward == true)
				backward = false;
			else
				backward = true;
		}
		else if (wParam == VK_SPACE) {
			if (j == true)
				j = false;
			else
				j = true;
		}
		else if (wParam == VK_TAB) {
			upFinger = 0, upFinger2 = 0, upFinger3 = 0, rotateFinger = 0, arm = 0, arm2 = 0, arm2b = 0, handRotate = 0;
			view = 0;
			size = 0, size2 = 0, size3 = 0, translateR = 0, translateZ = 0, rotation = 0;
			radius = 0;
			color = 0, color2 = 0, color3 = 0;
			armCoord = { 0, 0, 0 };
			wholeAngle1 = -90, wholeAngle2 = 0, wholeX = 0, wholeY = 0;
			leftLegRotation = { 0, 0, 0 };
			rightLegRotation.bigLeg = 0, rightLegRotation.smallLeg = 0, rightLegRotation.wholeLeg = 0;
			smallLegR3 = 0, footR1 = 0;
			jmpTranslation1 = 0, jmpTranslation2 = 0;
			footBoardTY = 0, footBoardTX = 0;
			status = 'U';
			bodyRotate = 0, bodyRotate2 = 0, headRotate = 0, headRotate2 = 0;
			rightLegForward = true, startWalking = true, lift = false, cycle = false;
			coreColor = 0, coreColor2 = 0;
			wingRotation = 5;
			wing2 = true;
			flyx = 0, flyy = 0, flyz = 0;
			robotRotate = 0, robotRotate2 = 0;
			wingSize = 0;
			wingRotation2 = true;
			t = false, r = false, j = false, w = false;
			f1 = false, f2 = false, f3 = false, f4 = false;
			forward = false, backward = false;
		}
		else if (wParam == 'R') {
			if (r == true)
				r = false;
			else
				r = true;
		}
		else if (wParam == 'T') {
			if (t == true)
				t = false;
			else
				t = true;
		}
		else if (wParam == 'P') {
			if (isPlaying) {
				PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
				isPlaying = false;
			}
			else {
				PlaySound(TEXT("res/music/IronMan3Theme.wav"), NULL, SND_FILENAME | SND_ASYNC);
				isPlaying = true;
			}
		}
		else if (wParam == VK_UP) {
			if (f1 == true)
				f1 = false;
			else
				f1 = true;

			f2 = false;
			f3 = false;
			f4 = false;
		}
		else if (wParam == VK_DOWN) {
			if (f2 == true)
				f2 = false;
			else
				f2 = true;

			f1 = false;
			f3 = false;
			f4 = false;
		}
		else if (wParam == VK_LEFT) {
			if (f3 == true)
				f3 = false;
			else
				f3 = true;

			f2 = false;
			f1 = false;
			f4 = false;
		}
		else if (wParam == VK_RIGHT) {
			if (f4 == true)
				f4 = false;
			else
				f4 = true;

			f2 = false;
			f3 = false;
			f1 = false;
		}
		else if (wParam == 'M') {
			view += 3;
		}
		else if (wParam == 'N') {
			view -= 3;
		}
		else if (wParam == '1') {
			if (headRotate < 30)
				headRotate++;
		}
		else if (wParam == '2') {
			if (headRotate > 0)
				headRotate--;
		}
		else if (wParam == '3') {
			if (headRotate2 < 30)
				headRotate2 += 1;
		}
		else if (wParam == '4') {
			if (headRotate2 > -30)
				headRotate2 -= 1;
		}
		else if (wParam == '6') {
			if (bodyRotate < 15)
				bodyRotate += 1;
		}
		else if (wParam == '7') {
			if (bodyRotate > -15)
				bodyRotate -= 1;
		}
		else if (wParam == '8') {
			if (upFinger < 90)
				upFinger += 5;
		}
		else if (wParam == '9') {
			if (upFinger > 0)
				upFinger -= 5;
		}
		else if (wParam == 'X') {
			upFinger3 += 1;
		}
		else if (wParam == 'Z') {
			upFinger3 -= 1;
		}
		else if (wParam == 'A') {
			if (arm > -90)
				arm -= 1;
		}
		else if (wParam == 'D') {
			if (arm < 0)
				arm += 1;
		}
		else if (wParam == 'V') {
			if (rotateFinger < 90)
				rotateFinger += 1;
		}
		else if (wParam == 'B') {
			if (rotateFinger > -90)
				rotateFinger -= 1;
		}
		else if (wParam == 'K') {
			if (upFinger2 > 0)
				upFinger2 -= 1;
		}
		else if (wParam == 'L') {
			if (upFinger2 < 90)
				upFinger2 += 1;
		}
		else if (wParam == 'U') {
			if (arm2 > -90) {
				arm2 -= 1;
				arm2b -= 1;
			}
		}
		else if (wParam == 'I') {
			if (arm2 < 0) {
				arm2 += 1;
				arm2b += 1;
			}
		}
		else if (wParam == 'Q') {
			if (handRotate < 90)
				handRotate += 1;
		}
		else if (wParam == 'E') {
			if (handRotate > -90)
				handRotate -= 1;
		}
		else if (wParam == VK_F1) {
			if (leftLegRotation.wholeLeg < 45) {
				leftLegRotation.wholeLeg += 2;
			}
		}
		else if (wParam == VK_F2) {
			if (leftLegRotation.wholeLeg > -45) {
				leftLegRotation.wholeLeg -= 2;
			}
		}
		else if (wParam == VK_F3) {
			if (rightLegRotation.wholeLeg < 45) {
				rightLegRotation.wholeLeg += 2;
			}
		}
		else if (wParam == VK_F4) {
			if (rightLegRotation.wholeLeg > -45) {
				rightLegRotation.wholeLeg -= 2;
			}
		}
		else if (wParam == VK_F5) {
			if (leftLegRotation.smallLeg < 0) {
				leftLegRotation.smallLeg += 2;
			}
		}
		else if (wParam == VK_F6) {
			if (leftLegRotation.smallLeg > -45) {
				leftLegRotation.smallLeg -= 2;
			}
		}
		else if (wParam == VK_F7) {
			if (rightLegRotation.smallLeg < 0) {
				rightLegRotation.smallLeg += 2;
			}
		}
		else if (wParam == VK_F8) {
			if (rightLegRotation.smallLeg > -45) {
				rightLegRotation.smallLeg -= 2;
			}
		}
		else if (wParam == VK_HOME) {
			w = true;
		}
		else if (wParam == VK_END) {
			w = false;
		}
		else if (wParam == VK_BACK) {
			if (colorChange == true) {
				colorChange = false;
			}
			else {
				colorChange = true;
			}

			if (colorChange == true) {
				colorR = { 1, 0.8, 0.7, 0.6, 0.5, 0.4, 0.2 };
				colorO = { 0, 0, 0, 0, 0, 0, 0 };
				body = Body(colorR, colorO);
			}
			else {
				colorR = { 1, 0.8, 0.7, 0.6, 0.5, 0.4, 0.2 };
				colorO = { 0.5, 0.4, 0.35, 0.3, 0.25, 0.2, 0.1 };
				body = Body(colorR, colorO);
			}
		}
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void light() {
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glEnable(GL_LIGHT0);
}

void ulti() {
	if (arm2 > -15) {
		arm2 -= 1;
		arm2b -= 1;
	}
	else {
		if (upFinger2 < 30 && arm2 == -15) {
			upFinger2 += 1;
			upFinger += 0.25;
		}

		if (size < 27.5)
			size += 0.5;

		if (size > 15 && arm2 > -90)
			translateR += 0.005;

		if (translateR > 0.13 && arm2 > -100)
			size += 0.25;

		if ((upFinger2 > 25) && arm2 > -100 && translateZ < 0.55)
			translateZ += 0.01;

		if (handRotate > 45)
			translateZ += 0.05;



		if (upFinger2 == 30 || handRotate > 0 || rotateFinger > 0) {
			if (arm2 > -90) {
				arm2 -= 1;
				arm2b -= 1;
			}
		}

		if (arm2 < -75) {
			if (handRotate < 90)
				handRotate += 3;
			if (rotateFinger < 90)
				rotateFinger += 3;
			if (upFinger2 > 0)
				upFinger2 -= 1;
		}
		rotation += 100;

		if (translateZ > 1.5) {
			size = 0;
			handRotate = 0;
			rotateFinger = 0;
			upFinger2 = 0;
			arm2 = 0;
			arm2b = 0;
			translateZ = 0;
			translateR = 0;
			upFinger = 0;
			rotation = 0;
			r = false;
		}
	}
}

void ulti2() {
	if (arm2 > -60) {
		arm2 -= 1;
		arm2b -= 1;
	}
	if (arm > -60 && size2 < 1)
		arm -= 1;
	if (rotateFinger > -90 && size2 < 1)
		rotateFinger -= 3;

	if (upFinger2 < 20 && rotateFinger == -90 && size2 < 1) {
		upFinger2 += 0.5;
		upFinger3 -= 1;
	}
	if (upFinger2 > 10 && upFinger2 < 15 && size2 < 1)
		upFinger += 2.5;

	if (upFinger == 22.5 && size2 < 1)
		size2 += 0.04;

	if (size2 > 0 && coreColor2 == 0) {
		coreColor += 0.025;
	}
	if (size2 >= 1 && rotateFinger < -15) {
		rotateFinger += 3;
		arm += 2.5;
		armCoord.y -= 0.1;
		armCoord.z += 1;
		armCoord.x -= 1.4;

		if (rotateFinger == -15) {
			size3 = 0.5;
		}
	}

	if (rotateFinger >= -15 && size2 >= 1 && rotateFinger < 90) {

		if (size3 < 1) {
			size3 += 0.05;
		}
		armCoord.z += 0.5;
		upFinger3 += 3;
		rotateFinger += 9;
		arm2 -= 2.5;
		arm2b -= 2.5;
		handRotate += 8;
		upFinger2 -= 1.5;

		if (upFinger > 0)
			upFinger -= 2.5;
	}

	if (armCoord.z > 25)
		armCoord.z += 1;

	if (armCoord.z == 50) {
		arm2 = 0;
		arm2b = 0;
		arm = 0;
		size2 = 0;
		rotateFinger = 0;
		upFinger2 = 0;
		upFinger3 = 0;
		handRotate = 0;
		size3 = 0;
		armCoord.z = 0;
		armCoord.x = 0;
		armCoord.y = 0;
		upFinger = 0;
		coreColor = 0;
		t = false;
	}

	rotation += 100;
}

void jump() {
	if (leftLegRotation.bigLeg <= 23 && lift == false) {
		if (cycle == true) {
			lift = true;
		}
		else if (cycle == false) {
			if (leftLegRotation.bigLeg >= 23)
				lift = true;
		}
		leftLegRotation.bigLeg += 1;
		rightLegRotation.bigLeg += 1;
		smallLegR3 -= 1;
		footR1 += 1;
		wholeY -= 0.1;
		wholeX += 0.07;
		jmpTranslation1 += 0.1;
		jmpTranslation2 += 0.07;
		bodyRotate2 += 0.5;
	}
	else if (lift == true) {
		if (cycle == true) {
			if (leftLegRotation.bigLeg > 0) {
				leftLegRotation.bigLeg -= 1;
				rightLegRotation.bigLeg -= 1;
				smallLegR3 += 1;
				footR1 -= 1;
				wholeY += 0.1;
				wholeX -= 0.07;
				jmpTranslation1 -= 0.1;
				jmpTranslation2 -= 0.07;
			}
			else {
				cycle = false;
				lift = false;
			}
		}
		else {
			if (leftLegRotation.bigLeg > 0) {
				leftLegRotation.bigLeg -= 1;
				rightLegRotation.bigLeg -= 1;
				smallLegR3 += 1;
				footR1 -= 1;
				wholeY += 0.1;
				wholeX -= 0.07;
				jmpTranslation1 -= 0.1;
				jmpTranslation2 -= 0.07;
				bodyRotate2 -= 0.5;
				if (leftLegRotation.bigLeg < 20) {
					footBoardTX += 0.03;
					footBoardTY += 0.15;
					footR1 -= 1.5;
				}
			}
			else if (wholeY <= 15 && status == 'U') {
				wholeY += 0.5;
				if (footR1 >= -20) {
					footBoardTY += 0.15;
					footR1 -= 1.5;
				}
			}
			else if (status == 'D' || wholeY >= 15) {
				status = 'D';
				wholeY -= 0.5;
				if (wholeY < 6) {
					if (footBoardTX >= 0)
						footBoardTX -= 0.06;
					footBoardTY -= 0.25;
					footR1 += 2.5;
				}

				if (wholeY == 0) {
					status = 'U';
					lift = false;
					cycle = true;
					j = false;
				}
			}
		}
	}
}

void flyUp() {
	if (headRotate < 0)
		headRotate++;

	if (wingSize >= 1) {

		if (robotRotate2 > 0) {
			robotRotate2--;
		}
		else if (robotRotate2 < 0) {
			robotRotate2++;
		}

		if (robotRotate == -285 || robotRotate == 285) {
			wingRotation2 = true;
		}
		else if (robotRotate == 180 || robotRotate == 75 || robotRotate == -180 || robotRotate == -75) {
			wingRotation2 = false;
		}

		if (wingRotation2 == false) {
			if (robotRotate > 0)
				robotRotate--;
			else if (robotRotate < 0)
				robotRotate++;
		}
		else {
			if (robotRotate < 0 && robotRotate > -360) {
				robotRotate--;
			}
			else if (robotRotate > 0 && robotRotate < 360)
				robotRotate++;
		}

		if (robotRotate2 == 0 && (robotRotate == 0 || robotRotate == 360 || robotRotate == -360))
			flyy += 1;
	}
}

void flyDown() {
	if (headRotate < 0)
		headRotate++;

	if (wingSize >= 1) {

		if (robotRotate2 < 180)
			robotRotate2++;
		else if (robotRotate2 > 180)
			robotRotate2--;

		if (robotRotate == -75 || robotRotate == -285) {
			wingRotation2 = true;
		}
		else if (robotRotate == 285 || robotRotate == 75 || robotRotate == 0 || robotRotate == 360 || robotRotate == -360) {
			wingRotation2 = false;
		}

		if (wingRotation2 == false) {
			if (robotRotate < 180)
				robotRotate++;
			else if (robotRotate > 180)
				robotRotate--;
		}
		else {
			if (robotRotate < -180)
				robotRotate++;
			else if (robotRotate > -180)
				robotRotate--;
		}

		if (robotRotate2 == 180 && (robotRotate == 180 || robotRotate == -180))
			flyy -= 1;
	}
}

void flyRight() {
	if (wingSize >= 1) {

		if (headRotate > -25)
			headRotate--;

		if (robotRotate == 180 || robotRotate == 0 || robotRotate == -360) {
			wingRotation2 = true;
		}
		else if (robotRotate == -180 || robotRotate == 360) {
			wingRotation2 = false;
		}

		if (wingRotation2 == true) {
			if (robotRotate < 75)
				robotRotate++;
			else if (robotRotate > 75)
				robotRotate--;
		}
		else {
			if (robotRotate < -285)
				robotRotate++;
			else if (robotRotate > -285)
				robotRotate--;
		}

		if (robotRotate2 < 75)
			robotRotate2++;
		else if (robotRotate2 > 75)
			robotRotate2--;

		if ((robotRotate == -285 || robotRotate == 75) && robotRotate2 == 75)
			flyx += 1;
	}
}

void flyLeft() {
	if (wingSize >= 1) {

		if (headRotate > -25)
			headRotate--;

		if (robotRotate == 180 || robotRotate == 360) {
			wingRotation2 = true;
		}
		else if (robotRotate == -180 || robotRotate == 0 || robotRotate == -360) {
			wingRotation2 = false;
		}

		if (wingRotation2 == true) {
			if (robotRotate < 285)
				robotRotate++;
			else if (robotRotate > 285)
				robotRotate--;
		}
		else {
			if (robotRotate < -75)
				robotRotate++;
			else if (robotRotate > -75)
				robotRotate--;
		}

		if (robotRotate2 < 75)
			robotRotate2++;
		else if (robotRotate2 > 75)
			robotRotate2--;

		if ((robotRotate == -75 || robotRotate == 285) && robotRotate2 == 75)
			flyx -= 1;
	}
}

void moveFront() {
	if (rightLegForward == true) {
		if (leftLegRotation.wholeLeg <= 30) {
			wholeX += 0.5;
			leftLegRotation.wholeLeg += 2.5;
			rightLegRotation.wholeLeg -= 2.5;
			arm2 -= 2.5;
			arm2b += 2.5;
		}

		if (leftLegRotation.wholeLeg >= -30) {
			leftLegRotation.smallLeg -= 2.5;
		}

		if (leftLegRotation.wholeLeg >= 15 && leftLegRotation.smallLeg <= 0 && startWalking == true) {
			leftLegRotation.smallLeg += 4.5;
		}

		if (startWalking == false && leftLegRotation.wholeLeg >= 0 && leftLegRotation.smallLeg <= 0) {
			leftLegRotation.smallLeg += 4.5;
		}

		if (leftLegRotation.wholeLeg >= 30 && leftLegRotation.smallLeg > 0) {
			rightLegForward = false;
			startWalking = false;
		}
	}
	else {
		if (leftLegRotation.wholeLeg >= -30) {
			wholeX += 0.5;
			leftLegRotation.wholeLeg -= 2.5;
			rightLegRotation.wholeLeg += 2.5;
			arm2 += 2.5;
			arm2b -= 2.5;
		}

		if (rightLegRotation.wholeLeg >= -30) {
			rightLegRotation.smallLeg -= 2.5;
		}

		if (startWalking == false && rightLegRotation.wholeLeg >= 0 && rightLegRotation.smallLeg <= 0) {
			rightLegRotation.smallLeg += 4.5;
		}

		if (rightLegRotation.wholeLeg >= 15 && rightLegRotation.smallLeg <= 0 && startWalking == true) {
			rightLegRotation.smallLeg += 4.5;
		}

		if (leftLegRotation.wholeLeg <= -30 && rightLegRotation.smallLeg > 0) {
			rightLegForward = true;
		}
	}
}

void moveBack() {
	if (rightLegForward == true) {
		if (leftLegRotation.wholeLeg <= 30) {
			wholeX -= 0.5;
			leftLegRotation.wholeLeg += 2.5;
			rightLegRotation.wholeLeg -= 2.5;
			arm2 -= 2.5;
			arm2b += 2.5;
		}

		if (leftLegRotation.wholeLeg >= -30) {
			leftLegRotation.smallLeg -= 2.5;
		}

		if (leftLegRotation.wholeLeg >= 15 && leftLegRotation.smallLeg <= 0 && startWalking == true) {
			leftLegRotation.smallLeg += 4.5;
		}

		if (startWalking == false && leftLegRotation.wholeLeg >= 0 && leftLegRotation.smallLeg <= 0) {
			leftLegRotation.smallLeg += 4.5;
		}

		if (leftLegRotation.wholeLeg >= 30 && leftLegRotation.smallLeg > 0) {
			rightLegForward = false;
			startWalking = false;
		}
	}
	else {
		if (leftLegRotation.wholeLeg >= -30) {
			wholeX -= 0.5;
			leftLegRotation.wholeLeg -= 2.5;
			rightLegRotation.wholeLeg += 2.5;
			arm2 += 2.5;
			arm2b -= 2.5;
		}

		if (rightLegRotation.wholeLeg >= -30) {
			rightLegRotation.smallLeg -= 2.5;
		}

		if (startWalking == false && rightLegRotation.wholeLeg >= 0 && rightLegRotation.smallLeg <= 0) {
			rightLegRotation.smallLeg += 4.5;
		}

		if (rightLegRotation.wholeLeg >= 15 && rightLegRotation.smallLeg <= 0 && startWalking == true) {
			rightLegRotation.smallLeg += 4.5;
		}

		if (leftLegRotation.wholeLeg <= -30 && rightLegRotation.smallLeg > 0) {
			rightLegForward = true;
		}
	}
}

void display()
{
	if (wingRotation == 20)
		wing2 = false;
	if (wingRotation == 5)
		wing2 = true;

	if (wing2 == true)
		wingRotation += 3;
	if (wing2 == false)
		wingRotation -= 3;

	if (t == true)
		ulti2();
	else if (r == true)
		ulti();
	else if (j == true)
		jump();

	if (f1 == true)
		flyUp();
	else if (f2 == true)
		flyDown();
	else if (f3 == true)
		flyLeft();
	else if (f4 == true)
		flyRight();

	if (w == true) {
		if (wingSize < 1) {
			handRotate += 4.5;
			wingSize += 0.05;
		}
	}
	else {
		if (wingSize > 0) {
			handRotate -= 4.5;
			wingSize -= 0.05;
		}
	}

	if (forward == true)
		moveFront();
	else if (backward == true)
		moveBack();

	// Animating background
	if (texCoord.x == 180 && texCoord.y == 180) {
		texCoord.x = 80;
		texCoord.y = 80;
	}
	else {
		texCoord.x++;
		texCoord.y++;
	}

	glClearColor(0.8, 0.8, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);

	GLfloat a[] = { 1,0,0,0.5 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, a);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	light();

	glDisable(GL_LIGHTING);

	// Draw the background
	background.Draw(texCoord.x, texCoord.y, texCoord.z);

	glPushMatrix();
	glRotated(view, 0, 1, 0);

	glPushMatrix();
	glTranslated(flyx, flyy, flyz);

	glPushMatrix();
	glRotated(robotRotate, 0, 1, 0);
	glRotated(robotRotate2, 1, 0, 0);
	glPushMatrix();
	glTranslated(0, wholeY, 0);
	glTranslated(0, 0, wholeX);

	// Rotate whole robot
	glPushMatrix();
	glTranslated(-5, -30, 9);
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	glPushMatrix();
	body.LeftLeg(leftLegRotation, jmpTranslation1, jmpTranslation2, smallLegR3, footBoardTY, footBoardTX, footR1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 0, 0);
	body.RightLeg(rightLegRotation, jmpTranslation1, jmpTranslation2, smallLegR3, footBoardTY, footBoardTX, footR1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(bodyRotate, 0, 1, 0);
	glRotated(bodyRotate2, 1, 0, 0);
	body.Stomach("res/textures/rasengan2.bmp");

	glPushMatrix();

	glRotated(headRotate2, 0, 1, 0);

	glPushMatrix();
	glTranslated(0, 25, 0);
	glRotated(headRotate, 1, 0, 0);
	glTranslated(0, -25, 0);
	body.Head(radius, "res/textures/mouth.bmp");
	glPopMatrix();

	glPopMatrix();

	gadget.Thruster(wingRotation, wingSize);

	glDisable(GL_LIGHTING);
	body.BothArms(arm, arm2, arm2b, rotateFinger, handRotate, upFinger, upFinger2, upFinger3, size, size2, size3, translateR, translateZ, rotation, armCoord.x, armCoord.y, armCoord.z);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 720, 720,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	glMatrixMode(GL_PROJECTION);
	glOrtho(-80, 80, -80, 80, -80, 80);

	// Play BGM
	PlaySound(TEXT("res/music/IronMan3Theme.wav"), NULL, SND_FILENAME | SND_ASYNC);

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------