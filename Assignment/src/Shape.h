#pragma once

#include "wtypes.h" // For some reason, this is require to properly use `GLint` type
#include "gl/GLU.h"

class Shape {
private:
	GLUquadricObj* object;
public:
	// Constructor and Destructor
	Shape();
	~Shape();

	// Methods
	void sphere(GLdouble size);
	void cylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks);
	void disk(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint stacks);
	void cube(GLdouble x1, GLdouble x2, LPCSTR texturePath);
	void triangle(LPCSTR texturePath);
	void bar(GLdouble x1, GLdouble x2);
};
