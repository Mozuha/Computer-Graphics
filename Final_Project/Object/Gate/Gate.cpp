#include "Gate.h"
#include "../../Material/Material_types.h"
#include <GL/glut.h>

Gate::Gate() {
	this->pillar = Pillar(GATE_PILLAR);

	this->material = Material();
	material.define(GATE_PILLAR);
}

Gate::Gate(
	float mar, float mag, float mab, float maa,
	float mdr, float mdg, float mdb, float mda,
	float msr, float msg, float msb, float msa,
	float mer, float meg, float meb, float mea,
	float shine) {

	this->pillar = Pillar(
		mar, mag, mab, maa,
		mdr, mdg, mdb, mda,
		msr, msg, msb, msa,
		mer, meg, meb, mea,
		shine);

	this->material = Material(
		mar, mag, mab, maa,
		mdr, mdg, mdb, mda,
		msr, msg, msb, msa,
		mer, meg, meb, mea,
		shine);
}

void Gate::render() {
	material.apply();

	// vertical pillars
	glPushMatrix();
	glTranslatef(-2.5, 0.25, 0.0);
	pillar.render();
	glTranslatef(5.0, 0.0, 0.0);
	pillar.render();
	glPopMatrix();

	// horizontal pillars
	glPushMatrix();
	glTranslatef(5.0, 7.75, 0.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	pillar.render();
	glTranslatef(2.75, 0.0, 0.0);
	pillar.render();
	glPopMatrix();
}