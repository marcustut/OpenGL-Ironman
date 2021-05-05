#pragma once

#include <math.h>
#include "wtypes.h"

#include "../Shape.h"
#include "../Utils.h"

class Hand {
private:
	static Shape shape;

	ColorR colorR;
	ColorO colorO;

	void upperFinger(GLdouble height);
	void lowerFinger(GLdouble height);
	void finger(GLdouble height, GLdouble upFinger);
public:
	Hand(ColorR& colorR, ColorO& colorO);
	~Hand();

	void DrawHand(GLdouble thumb, GLdouble thumbA, GLdouble ring, GLdouble index, GLdouble little, GLdouble rotate, GLdouble upFinger);
};

