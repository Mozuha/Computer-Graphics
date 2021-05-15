#include "Firebag_paper.h"
#include "../../../../Material/Material_types.h"
#include <GL/glut.h>

Firebag_paper::Firebag_paper() {
	// #FBFAF5
	/*this->r = 0.98047;
	this->g = 0.97656;
	this->b = 0.95703;*/

	this->material = Material();
	material.define(FIREBAG_PAPER);
}

Firebag_paper::Firebag_paper(
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

void Firebag_paper::render() {
	//glColor3f(r, g, b);
	material.apply();

	//// top square
	//glBegin(GL_POLYGON);
	//glVertex3f(-0.38, -0.42, 0.23);
	//glVertex3f(-0.38, -0.42, -0.23);
	//glVertex3f(0.38, -0.42, -0.23);
	//glVertex3f(0.38, -0.42, 0.23);
	//glEnd();

	// sides
	glBegin(GL_QUAD_STRIP);
	glVertex3f(-0.38, -0.42, 0.38);
	glVertex3f(-0.33, -1.18, 0.35);
	glVertex3f(0.33, -1.18, 0.35);
	glVertex3f(0.38, -0.42, 0.38);

	glVertex3f(-0.38, -0.42, -0.38);
	glVertex3f(-0.33, -1.18, -0.35);
	glVertex3f(-0.33, -1.18, 0.35);
	glVertex3f(-0.38, -0.42, 0.38);

	glVertex3f(0.38, -0.42, -0.38);
	glVertex3f(0.33, -1.18, -0.35);
	glVertex3f(-0.33, -1.18, -0.35);
	glVertex3f(-0.38, -0.42, -0.38);

	glVertex3f(0.38, -0.42, 0.38);
	glVertex3f(0.33, -1.18, 0.35);
	glVertex3f(0.33, -1.18, -0.35);
	glVertex3f(0.38, -0.42, -0.38);
	glEnd();

	// bottom square
	glBegin(GL_POLYGON);
	glVertex3f(-0.33, -1.18, 0.35);
	glVertex3f(-0.33, -1.18, -0.35);
	glVertex3f(0.33, -1.18, -0.35);
	glVertex3f(0.33, -1.18, 0.35);
	glEnd();
}