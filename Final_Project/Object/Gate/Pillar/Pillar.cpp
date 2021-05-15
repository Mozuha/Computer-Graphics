#include "Pillar.h"
#include "../../../Material/Material_types.h"
#include <GL/glut.h>

Pillar::Pillar() {
	// #FB3C02
	/*this->r = 0.98047;
	this->g = 0.23438;
	this->b = 0.00781;*/

	this->material = Material();
	material.define(GATE_PILLAR);
}

Pillar::Pillar(int mat_type) {
	this->material = Material();
	material.define(mat_type);
	//if (mat_type == GATE_PILLAR) material.define(GATE_PILLAR);
	//else if (mat_type == LANTERN_PILLAR) material.define(LANTERN_PILLAR);
}

Pillar::Pillar(
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

void Pillar::render() {
	//glColor3f(0.89063, 0.36719, 0.19531);  // #E45E32
	//glColor3f(0.98047, 0.23438, 0.00781);  // #FB3C02
	//glColor3f(r, g, b);
	material.apply();

	glPushMatrix();
	glTranslatef(0, 5.0, 0);
	glScalef(1.0, 10.0, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();
}