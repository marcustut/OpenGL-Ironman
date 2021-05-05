#pragma once

#include "../Shape.h"
#include "../Utils.h"

class Leg {
private:
	static Shape shape;

	ColorR colorR;
	ColorO colorO;

	void footboard();
	void smallLeg();
public:
	Leg(ColorR& colorR, ColorO& colorO);
	~Leg();

	void DrawLeftLeg(LegRotation leftLegRotation, GLdouble jmpTranslation1, GLdouble jmpTranslation2, GLdouble smallLegR3, GLdouble footBoardTY, GLdouble footBoardTX, GLdouble footR1);
	void DrawRightLeg(LegRotation rightLegRotation, GLdouble jmpTranslation1, GLdouble jmpTranslation2, GLdouble smallLegR3, GLdouble footBoardTY, GLdouble footBoardTX, GLdouble footR1);
};
