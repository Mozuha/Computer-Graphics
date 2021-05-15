#include "Sundial.h"
#include "../../Material/Material_types.h"
#include <GL/glut.h>

Sundial::Sundial() {
	this->cylinder = Cylinder();

	this->stick = Stick();

	this->material = Material();
	material.define(SUNDIAL);
}

Sundial::Sundial(
	float mar, float mag, float mab, float maa,
	float mdr, float mdg, float mdb, float mda,
	float msr, float msg, float msb, float msa,
	float mer, float meg, float meb, float mea,
	float shine, float radius, float height) {

	this->cylinder = Cylinder(mdr, mdg, mdb, radius, height);

	this->stick = Stick(mdr, mdg, mdb);

	this->material = Material(
		mar, mag, mab, maa,
		mdr, mdg, mdb, mda,
		msr, msg, msb, msa,
		mer, meg, meb, mea,
		shine);
}

void Sundial::render() {
	material.apply();

	glPushMatrix();
	cylinder.render();
	glTranslatef(0.0, 0.25, 0.5);
	glRotatef(-40.0, 1.0, 0.0, 0.0);
	stick.render();
	glPopMatrix();
}