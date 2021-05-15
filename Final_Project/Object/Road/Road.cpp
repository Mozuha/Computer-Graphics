#include "Road.h"
#include "../../Material/Material_types.h"
#include <GL/glut.h>

Road::Road() {
	// #716F68
	/*this->r = 0.44141;
	this->g = 0.43359;
	this->b = 0.40625;*/

	this->material = Material();
	material.define(ROAD);
}

Road::Road(
	float mar, float mag, float mab, float maa,
	float mdr, float mdg, float mdb, float mda,
	float msr, float msg, float msb, float msa,
	float mer, float meg, float meb, float mea,
	float shine) {

	this->material = Material(
		mar, mag, mab, maa,
		mdr, mdg, mdb, mda,
		msr, msg, msb, msa,
		mer, meg, meb, mea,
		shine);
}

void Road::render() {
	//glColor3f(0.34766, 0.34375, 0.33984);  // #595857
	//glColor3f(r, g, b);
	material.apply();

	glPushMatrix();
	glScalef(3.7, 0.1, 30.5);
	glutSolidCube(1.0);
	glPopMatrix();
}