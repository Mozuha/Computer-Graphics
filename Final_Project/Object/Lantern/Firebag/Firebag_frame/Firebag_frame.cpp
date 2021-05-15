#include "Firebag_frame.h"
#include "../../../../Material/Material_types.h"
#include <GL/glut.h>

Firebag_frame::Firebag_frame() {
	// #FF251E
	/*this->r = 0.99609;
	this->g = 0.14453;
	this->b = 0.11719;*/

	this->material = Material();
	material.define(LANTERN_PILLAR);
}

Firebag_frame::Firebag_frame(
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

void Firebag_frame::render() {
	//glColor3f(r, g, b);
	material.apply();
	glLineWidth(8.0);

	// top square
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.4, -0.4, 0.4);
	glVertex3f(-0.4, -0.4, -0.4);
	glVertex3f(0.4, -0.4, -0.4);
	glVertex3f(0.4, -0.4, 0.4);
	glEnd();

	// sides (corners)
	glBegin(GL_LINES);
	glVertex3f(-0.4, -0.4, 0.4);
	glVertex3f(-0.35, -1.2, 0.37);

	glVertex3f(-0.4, -0.4, -0.4);
	glVertex3f(-0.35, -1.2, -0.37);

	glVertex3f(0.4, -0.4, -0.4);
	glVertex3f(0.35, -1.2, -0.37);

	glVertex3f(0.4, -0.4, 0.4);
	glVertex3f(0.35, -1.2, 0.37);
	glEnd();

	// sides (middles)
	glLineWidth(4.0);
	glBegin(GL_LINES);
	// vertical
	glVertex3f(0.05, -0.4, 0.4);
	glVertex3f(0.05, -1.2, 0.37);

	glVertex3f(-0.05, -0.4, 0.4);
	glVertex3f(-0.05, -1.2, 0.37);

	glVertex3f(-0.4, -0.4, 0.05);
	glVertex3f(-0.35, -1.2, 0.05);

	glVertex3f(-0.4, -0.4, -0.05);
	glVertex3f(-0.35, -1.2, -0.05);

	glVertex3f(-0.05, -0.4, -0.4);
	glVertex3f(-0.05, -1.2, -0.37);

	glVertex3f(0.05, -0.4, -0.4);
	glVertex3f(0.05, -1.2, -0.37);

	glVertex3f(0.4, -0.4, -0.05);
	glVertex3f(0.35, -1.2, -0.05);

	glVertex3f(0.4, -0.4, 0.05);
	glVertex3f(0.35, -1.2, 0.05);

	// horizontal
	glVertex3f(-0.375, -0.75, 0.385);
	glVertex3f(0.375, -0.75, 0.385);

	glVertex3f(-0.375, -0.85, 0.385);
	glVertex3f(0.375, -0.85, 0.385);

	glVertex3f(-0.375, -0.75, -0.385);
	glVertex3f(-0.375, -0.75, 0.385);

	glVertex3f(-0.375, -0.85, -0.385);
	glVertex3f(-0.375, -0.85, 0.385);

	glVertex3f(0.375, -0.75, -0.385);
	glVertex3f(-0.375, -0.75, -0.385);

	glVertex3f(0.375, -0.85, -0.385);
	glVertex3f(-0.375, -0.85, -0.385);

	glVertex3f(0.375, -0.75, 0.385);
	glVertex3f(0.375, -0.75, -0.385);

	glVertex3f(0.375, -0.85, 0.385);
	glVertex3f(0.375, -0.85, -0.385);
	glEnd();

	// bottom square
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.35, -1.2, 0.37);
	glVertex3f(-0.35, -1.2, -0.37);
	glVertex3f(0.35, -1.2, -0.37);
	glVertex3f(0.35, -1.2, 0.37);
	glEnd();
}