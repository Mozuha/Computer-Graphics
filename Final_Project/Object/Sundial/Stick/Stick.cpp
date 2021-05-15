#include "Stick.h"
#include <GL/glut.h>

Stick::Stick() {
	// #787366
	/*this->r = 0.46875;
	this->g = 0.44922;
	this->b = 0.39844;*/

	// #B3ADA0
	/*this->r = 0.69922;
	this->g = 0.67578;
	this->b = 0.62500;*/

	// #A3A3A2
	this->r = 0.63672;
	this->g = 0.63672;
	this->b = 0.63281;
}

Stick::Stick(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

void Stick::render() {
	glColor3f(r, g, b);

	glPushMatrix();
	glTranslatef(0, 1.25, 0);
	glScalef(0.25, 2.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
}