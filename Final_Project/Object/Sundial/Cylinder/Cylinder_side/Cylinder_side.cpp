#include "Cylinder_side.h"
#include <cstdlib>
#include <GL/glut.h>

#define PI 3.141592654f

Cylinder_side::Cylinder_side() {
	// #787366
	/*this->r = 0.46875;
	this->g = 0.44922;
	this->b = 0.39844;
	this->radius = 0.5;
	this->height = 0.5;*/

	// #B3ADA0
	/*this->r = 0.69922;
	this->g = 0.67578;
	this->b = 0.62500;
	this->radius = 0.5;
	this->height = 0.5;*/

	// #A3A3A2
	this->r = 0.63672;
	this->g = 0.63672;
	this->b = 0.63281;
	this->radius = 0.5;
	this->height = 0.5;
}

Cylinder_side::Cylinder_side(float r, float g, float b, float radius, float height) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->radius = radius;
	this->height = height;
}

void Cylinder_side::render() {
	GLfloat angle;
	glColor3f(r, g, b);

	glBegin(GL_QUAD_STRIP);
	for (GLint i = 0; i < 100; i++) {
		angle = 2.0 * (PI * GLfloat(i)) / 100.0;
		glVertex3f((radius * cos(angle)), height, (radius * sin(angle)));
		glVertex3f((radius * cos(angle)), 0.0, (radius * sin(angle)));
	}
	glEnd();
}