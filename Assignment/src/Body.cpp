#include "Body.h"

// Initialize static members of the class
Shape Body::shape;

// Constructor
Body::Body(ColorR& colorR, ColorO& colorO)
	: colorR(colorR), colorO(colorO), arm(colorR, colorO), stomach(colorR, colorO), head(colorR, colorO), leg(colorR, colorO) {}

// Destructor
Body::~Body() {}

// Draw both whole arms of the robot
void Body::BothArms(GLdouble arm, GLdouble arm2, GLdouble arm2b, GLdouble rotateFinger, GLdouble handRotate, GLdouble upFinger, GLdouble upFinger2, GLdouble upFinger3, GLdouble size, GLdouble size2, GLdouble size3, GLdouble translateR, GLdouble translateZ, GLdouble rotation, GLdouble x, GLdouble y, GLdouble z) {
	Body::arm.DrawBothArms(arm, arm2, arm2b, rotateFinger, handRotate, upFinger, upFinger2, upFinger3, size, size2, size3, translateR, translateZ, rotation, x ,y, z);
}

// Draw the stomach of the robot
void Body::Stomach(LPCSTR coreTexturePath) {
	Body::stomach.DrawStomach(coreTexturePath);
}

// Draw the head of the robot
void Body::Head(GLdouble radius, LPCSTR mouthTexturePath) {
	Body::head.DrawHead(radius, mouthTexturePath);
}

// Draw the left leg of the robot
void Body::LeftLeg(LegRotation leftLegRotation, GLdouble jmpTranslation1, GLdouble jmpTranslation2, GLdouble smallLegR3, GLdouble footBoardTY, GLdouble footBoardTX, GLdouble footR1) {
	Body::leg.DrawLeftLeg(leftLegRotation, jmpTranslation1, jmpTranslation2, smallLegR3, footBoardTY, footBoardTX, footR1);
}

// Draw the right leg of the robot
void Body::RightLeg(LegRotation rightLegRotation, GLdouble jmpTranslation1, GLdouble jmpTranslation2, GLdouble smallLegR3, GLdouble footBoardTY, GLdouble footBoardTX, GLdouble footR1) {
	Body::leg.DrawRightLeg(rightLegRotation, jmpTranslation1, jmpTranslation2, smallLegR3, footBoardTY, footBoardTX, footR1);
}
