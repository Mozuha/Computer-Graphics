#include "Firebag_roof.h"
#include "../../../../Material/Material_types.h"
#include <GL/glut.h>

Firebag_roof::Firebag_roof() {
	this->material_tile = Material();
	material_tile.define(FIREBAG_ROOF);

	this->material_stand = Material();
	material_stand.define(LANTERN_PILLAR);
}

Firebag_roof::Firebag_roof(
	float tmar, float tmag, float tmab, float tmaa,
	float tmdr, float tmdg, float tmdb, float tmda,
	float tmsr, float tmsg, float tmsb, float tmsa,
	float tmer, float tmeg, float tmeb, float tmea,
	float tshine,
	float smar, float smag, float smab, float smaa,
	float smdr, float smdg, float smdb, float smda,
	float smsr, float smsg, float smsb, float smsa,
	float smer, float smeg, float smeb, float smea,
	float sshine) {

	this->material_tile = Material(
		tmar, tmag, tmab, tmaa,
		tmdr, tmdg, tmdb, tmda,
		tmsr, tmsg, tmsb, tmsa,
		tmer, tmeg, tmeb, tmea,
		tshine);

	this->material_stand = Material(
		smar, smag, smab, smaa,
		smdr, smdg, smdb, smda,
		smsr, smsg, smsb, smsa,
		smer, smeg, smeb, smea,
		sshine);
}

void Firebag_roof::render() {
	material_tile.apply();

	// right tile
	glPushMatrix();
	glRotatef(-40.0, 0.0, 0.0, 1.0);
	glTranslatef(0.4, 0.0, 0.0);
	glScalef(0.8, 0.1, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	// left tile
	glPushMatrix();
	glRotatef(40.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.4, 0.0, 0.0);
	glScalef(0.8, 0.1, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	// top tile
	glPushMatrix();
	glTranslatef(0.0, 0.05, 0.0);
	glScalef(0.12, 0.12, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	material_stand.apply();

	// front stand
	glPushMatrix();
	glTranslatef(0.0, -0.25, 0.25);
	glScalef(0.12, 0.3, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	// back stand
	glPushMatrix();
	glTranslatef(0.0, -0.25, -0.25);
	glScalef(0.12, 0.3, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
}