#ifndef PROJECT_CYLINDER_H
#define PROJECT_CYLINDER_H

#include "Circle/Circle.h"
#include "Cylinder_side/Cylinder_side.h"

class Cylinder {
private:
	Circle circle_top, circle_bottom;
	Cylinder_side cylinder_side;

public:
	Cylinder();
	Cylinder(float r, float g, float b, float radius, float height);
	void render();
};

#endif //PROJECT_CYLINDER_H