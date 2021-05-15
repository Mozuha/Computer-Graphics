#ifndef PROJECT_CYLINDER_SIDE_H
#define PROJECT_CYLINDER_SIDE_H

class Cylinder_side {
private:
	float r, g, b, radius, height;

public:
	Cylinder_side();
	Cylinder_side(float r, float g, float b, float radius, float height);
	void render();
};

#endif //PROJECT_CYLINDER_SIDE_H