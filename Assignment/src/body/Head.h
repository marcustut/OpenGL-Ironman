#pragma once

#include <math.h>

#include "../Shape.h"
#include "../Utils.h"

class Head {
private:
	static Shape shape;

	ColorR colorR;
	ColorO colorO;

	void eye(LPCSTR texturePath);
public:
	Head(ColorR& colorR, ColorO& colorO);
	~Head();

	void DrawHead(GLdouble radius, LPCSTR mouthTexturePath);
};
