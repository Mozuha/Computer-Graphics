#include "Icosahedron.h"
#include "../../Material/Material_types.h"
#include <GL/glut.h>

Icosahedron::Icosahedron() {
	// #7D4B28
	/*this->r = 0.48828;
	this->g = 0.29297;
	this->b = 0.15625;*/

	this->material = Material();
	material.define(ICOSAHEDRON);

	this->light = Light(0.0, 5.0, 0.0, LANTERN_LIGHT);
}

Icosahedron::Icosahedron(
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

void Icosahedron::render() {
	//glColor3f(r, g, b);
	material.apply();

	glPushMatrix();
	glutWireIcosahedron();

	glEnable(GL_LIGHT2);
	GLfloat light_position2[] = { 0.0, -0.7, 0.0 };
	GLfloat light_diffuse2[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_specular2[] = { 0.99610, 0.85547, 0.30859, 1.0 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);

	glTranslatef(0.0, -0.7, 0.0);
	glScalef(0.15, 0.15, 0.15);
	light.render();
	glPopMatrix();
}