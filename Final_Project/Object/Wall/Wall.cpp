#include "Wall.h"
#include "../../Material/Material_types.h"
#include <GL/glut.h>

Wall::Wall() {
	// #2E7E16
	/*this->r = 0.17969;
	this->g = 0.49219;
	this->b = 0.08594;*/

	this->material = Material();
	material.define(GROUND);
}

Wall::Wall(int mat_type) {
	this->material = Material();
	material.define(mat_type);
	//if (mat_type == GROUND) material.define(GROUND);
	//else if (mat_type == WALL) material.define(WALL);
}

Wall::Wall(
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

void Wall::render() {
	//glColor3f(0.40234, 0.65234, 0.04688);  // #67A70C
	//glColor3f(r, g, b);

	material.apply();

	glPushMatrix();
	glScalef(30.0, 0.5, 40.0);
	glutSolidCube(1.0);
	glPopMatrix();
}