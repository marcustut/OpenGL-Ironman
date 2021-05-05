#pragma once

#include "Shape.h"
#include "Utils.h"
#include "body/Arm.h"
#include "body/Stomach.h"
#include "body/Head.h"
#include "body/Leg.h"

class Body {
private:
	// Used to draw basic shape
	static Shape shape;

	ColorR colorR;
	ColorO colorO;

	// Helper classes for drawing body parts
	Arm arm;
	Stomach stomach;
	Head head;
	Leg leg;
public:
	Body(ColorR& colorR, ColorO& colorO);
	~Body();

	void BothArms(GLdouble arm, GLdouble arm2, GLdouble arm2b, GLdouble rotateFinger, GLdouble handRotate, GLdouble upFinger, GLdouble upFinger2, GLdouble upFinger3, GLdouble size, GLdouble size2, GLdouble size3, GLdouble translateR, GLdouble translateZ, GLdouble rotation, GLdouble x, GLdouble y, GLdouble z);
	void Stomach(LPCSTR coreTexturePath);
	void Head(GLdouble radius, LPCSTR mouthTexturePath);
	void LeftLeg(LegRotation leftLegRotation, GLdouble jmpTranslation1, GLdouble jmpTranslation2, GLdouble smallLegR3, GLdouble footBoardTY, GLdouble footBoardTX, GLdouble footR1);
	void RightLeg(LegRotation rightLegRotation, GLdouble jmpTranslation1, GLdouble jmpTranslation2, GLdouble smallLegR3, GLdouble footBoardTY, GLdouble footBoardTX, GLdouble footR1);
};
