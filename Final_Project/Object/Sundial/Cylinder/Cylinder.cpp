#include "Cylinder.h"
#include <GL/glut.h>

Cylinder::Cylinder() {
	//this->circle_top = Circle();  // #787366, r=0.5, h=0.5
	//this->circle_bottom = Circle(0.46875, 0.44922, 0.39844, 0.5, 0.25);  // #787366, r=0.5, h=0.25
	//this->cylinder_side = Cylinder_side();  // #787366, r=0.5, h=0.5

	//this->circle_top = Circle();  // #B3ADA0, r=0.5, h=0.5
	//this->circle_bottom = Circle(0.69922, 0.67578, 0.62500, 0.5, 0.25);  // #B3ADA0, r=0.5, h=0.25
	//this->cylinder_side = Cylinder_side();  // #B3ADA0, r=0.5, h=0.5

	this->circle_top = Circle();  // #A3A3A2, r=0.5, h=0.5
	this->circle_bottom = Circle(0.63672, 0.63672, 0.63281, 0.5, 0.25);  // #A3A3A2, r=0.5, h=0.25
	this->cylinder_side = Cylinder_side();  // #A3A3A2, r=0.5, h=0.5
}

Cylinder::Cylinder(float r, float g, float b, float radius, float height) {
	this->circle_top = Circle(r, g, b, radius, height);
	this->circle_bottom = Circle(r, g, b, r, 0.25);  // #787366, r=0.5, h=0.25
	this->cylinder_side = Cylinder_side(r, g, b, radius, height);
}

void Cylinder::render() {
	glPushMatrix();
	glScalef(5.0, 1.0, 5.0);
	//glTranslatef(0.0, 0.25, 0.0);
	circle_top.render();
	cylinder_side.render();
	circle_bottom.render();
	glPopMatrix();
}