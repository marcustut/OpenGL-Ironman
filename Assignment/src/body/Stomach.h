#pragma once

#include "../Shape.h"
#include "../Utils.h"

class Stomach {
private:
	static Shape shape;

	ColorR colorR;
	ColorO colorO;

	void abs();
public:
	Stomach(ColorR& colorR, ColorO& colorO);
	~Stomach();

	void DrawStomach(LPCSTR coreTexturePath);
};
