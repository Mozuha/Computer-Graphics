#include "Lantern.h"
#include "../../Material/Material_types.h"
#include <GL/glut.h>

Lantern::Lantern() {
	this->firebag = Firebag();    // #383630, #FF251E, #FBFAF5
	this->pillar = Pillar(LANTERN_PILLAR);  // #FF251E
}

Lantern::Lantern(
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
	float pamar, float pamag, float pamab, float pamaa,
	float pamdr, float pamdg, float pamdb, float pamda,
	float pamsr, float pamsg, float pamsb, float pamsa,
	float pamer, float pameg, float pameb, float pamea,
	float pashine,
	float fmar, float fmag, float fmab, float fmaa,
	float fmdr, float fmdg, float fmdb, float fmda,
	float fmsr, float fmsg, float fmsb, float fmsa,
	float fmer, float fmeg, float fmeb, float fmea,
	float fshine,
	float pimar, float pimag, float pimab, float pimaa,
	float pimdr, float pimdg, float pimdb, float pimda,
	float pimsr, float pimsg, float pimsb, float pimsa,
	float pimer, float pimeg, float pimeb, float pimea,
	float pishine,
	float lmar, float lmag, float lmab, float lmaa,
	float lmdr, float lmdg, float lmdb, float lmda,
	float lmsr, float lmsg, float lmsb, float lmsa,
	float lmer, float lmeg, float lmeb, float lmea,
	float lshine, float x, float y, float z) {

	this->firebag = Firebag(
		tmar, tmag, tmab, tmaa,
		tmdr, tmdg, tmdb, tmda,
		tmsr, tmsg, tmsb, tmsa,
		tmer, tmeg, tmeb, tmea,
		tshine,
		smar, smag, smab, smaa,
		smdr, smdg, smdb, smda,
		smsr, smsg, smsb, smsa,
		smer, smeg, smeb, smea,
		sshine,
		pamar, pamag, pamab, pamaa,
		pamdr, pamdg, pamdb, pamda,
		pamsr, pamsg, pamsb, pamsa,
		pamer, pameg, pameb, pamea,
		pashine,
		fmar, fmag, fmab, fmaa,
		fmdr, fmdg, fmdb, fmda,
		fmsr, fmsg, fmsb, fmsa,
		fmer, fmeg, fmeb, fmea,
		fshine,
		lmar, lmag, lmab, lmaa,
		lmdr, lmdg, lmdb, lmda,
		lmsr, lmsg, lmsb, lmsa,
		lmer, lmeg, lmeb, lmea,
		lshine, x, y, z);

	this->pillar = Pillar(
		pimar, pimag, pimab, pimaa,
		pimdr, pimdg, pimdb, pimda,
		pimsr, pimsg, pimsb, pimsa,
		pimer, pimeg, pimeb, pimea,
		pishine);
}

void Lantern::render() {
	glPushMatrix();
	glTranslatef(0.0, 6.0, 0.0);
	glScalef(1.5, 1.5, 1.5);
	firebag.render();
	glTranslatef(0.0, -4.165, 0.0);
	glScalef(0.3, 0.295, 0.3);
	pillar.render();
	glPopMatrix();
}