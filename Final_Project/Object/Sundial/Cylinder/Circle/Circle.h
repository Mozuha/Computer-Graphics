#ifndef PROJECT_CIRCLE_H
#define PROJECT_CIRCLE_H

class Circle {
private:
	float r, g, b, radius, height;

public:
	Circle();
	Circle(float r, float g, float b, float radius, float height);
	void render();
};

#endif //PROJECT_CIRCLE_H