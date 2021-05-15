#ifndef PROJECT_STICK_H
#define PROJECT_STICK_H

class Stick {
private:
	float r, g, b;

public:
	Stick();
	Stick(float r, float g, float b);
	void render();
};

#endif //PROJECT_STICK_H