#include "Firebag.h"
#include "../../../Material/Material_types.h"
#include <GL/glut.h>

Firebag::Firebag() {
	this->firebag_roof = Firebag_roof();    // #383630, #FF251E
	this->firebag_paper = Firebag_paper();  // #FBFAF5
	this->firebag_frame = Firebag_frame();  // #FF251E
	this->light = Light(0.0, 5.0, 0.0, LANTERN_LIGHT);
}

Firebag::Firebag(
	float tmar, float tmag, float tmab, float tmaa,
	float tmdr, float tmdg, float tmdb, float tmda,
	float tmsr, float tmsg, float tmsb, float tmsa,
	float tmer, float tmeg, float tmeb, float tmea,
	float tshine,
	float smar, float smag, float smab, float smaa,
	float smdr, float smdg, float smdb, float smda,
	float smsr, float smsg, float smsb, float smsa,
	float smer, float smeg, float smeb, float smea,
	float sshine,
	float pmar, float pmag, float pmab, float pmaa,
	float pmdr, float pmdg, float pmdb, float pmda,
	float pmsr, float pmsg, float pmsb, float pmsa,
	float pmer, float pmeg, float pmeb, float pmea,
	float pshine,
	float fmar, float fmag, float fmab, float fmaa,
	float fmdr, float fmdg, float fmdb, float fmda,
	float fmsr, float fmsg, float fmsb, float fmsa,
	float fmer, float fmeg, float fmeb, float fmea,
	float fshine,
	float lmar, float lmag, float lmab, float lmaa,
	float lmdr, float lmdg, float lmdb, float lmda,
	float lmsr, float lmsg, float lmsb, float lmsa,
	float lmer, float lmeg, float lmeb, float lmea,
	float lshine, float x, float y, float z) {

	this->firebag_roof = Firebag_roof(
		tmar, tmag, tmab, tmaa,
		tmdr, tmdg, tmdb, tmda,
		tmsr, tmsg, tmsb, tmsa,
		tmer, tmeg, tmeb, tmea,
		tshine,
		smar, smag, smab, smaa,
		smdr, smdg, smdb, smda,
		smsr, smsg, smsb, smsa,
		smer, smeg, smeb, smea,
		sshine);

	this->firebag_paper = Firebag_paper(
		pmar, pmag, pmab, pmaa,
		pmdr, pmdg, pmdb, pmda,
		pmsr, pmsg, pmsb, pmsa,
		pmer, pmeg, pmeb, pmea,
		pshine);

	this->firebag_frame = Firebag_frame(
		fmar, fmag, fmab, fmaa,
		fmdr, fmdg, fmdb, fmda,
		fmsr, fmsg, fmsb, fmsa,
		fmer, fmeg, fmeb, fmea,
		fshine);
}

void Firebag::render() {
	glPushMatrix();
	firebag_roof.render();
	firebag_frame.render();
	//firebag_paper.render();
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_LIGHT1);
	GLfloat light_position1[] = { 0.0, -1.3, 0.0 };
	GLfloat light_diffuse1[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_specular1[] = { 0.99610, 0.85547, 0.30859, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);

	glTranslatef(0.0, -1.3, 0.0);
	glScalef(0.1, 0.1, 0.1);
	light.render();

	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);

	glTranslatef(0.0, 13.0, 0.0);
	glScalef(10.0, 10.0, 10.0);
	firebag_paper.render();

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	glPopMatrix();
}