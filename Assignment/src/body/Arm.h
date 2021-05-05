#pragma once

#include <math.h>

#include "../Shape.h"
#include "../Utils.h"
#include "Hand.h"

class Arm {
private:
	static Shape shape;

	Hand hand;

	ColorR colorR;
	ColorO colorO;

	GLdouble shoulderRadius;

	void lowerArmArmor();
	void lowerArm();
	void upperArm();
	void shoulder(GLdouble x);
	void leftWholeArm(GLdouble arm, GLdouble arm2b, GLdouble rotateFinger, GLdouble handRotate, GLdouble upFinger, GLdouble upFinger2, GLdouble upFinger3);
	void rightWholeArm(GLdouble arm, GLdouble arm2, GLdouble rotateFinger, GLdouble handRotate, GLdouble upFinger, GLdouble upFinger2, GLdouble upFinger3);
public:
	Arm(ColorR& colorR, ColorO& colorO);
	~Arm();

	void DrawBothArms(GLdouble arm, GLdouble arm2, GLdouble arm2b, GLdouble rotateFinger, GLdouble handRotate, GLdouble upFinger, GLdouble upFinger2, GLdouble upFinger3, GLdouble size, GLdouble size2, GLdouble size3, GLdouble translateR, GLdouble translateZ, GLdouble rotation, GLdouble x, GLdouble y, GLdouble z);
};
