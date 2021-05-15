#include "Light.h"
#include "../../Material/Material_types.h"
#include <GL/glut.h>

Light::Light() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;

	this->material = Material();
	material.define(SUN_LIGHT);
}

Light::Light(float x, float y, float z, int mat_type) {
	this->x = x;
	this->y = y;
	this->z = z;

	this->material = Material();
	material.define(mat_type);
}

Light::Light(
	float x, float y, float z,
	float mar, float mag, float mab, float maa,
	float mdr, float mdg, float mdb, float mda,
	float msr, float msg, float msb, float msa,
	float mer, float meg, float meb, float mea,
	float shine) {
	
	this->x = x;
	this->y = y;
	this->z = z;

	this->material = Material(
		mar, mag, mab, maa,
		mdr, mdg, mdb, mda,
		msr, msg, msb, msa,
		mer, meg, meb, mea,
		shine);
}

void Light::render() {
	material.apply_light();

	glPushMatrix();
	glTranslatef(x, y, z);
	glutSolidSphere(2.0, 10, 8);
	glPopMatrix();

	GLfloat reset_emission[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_EMISSION, reset_emission);
}