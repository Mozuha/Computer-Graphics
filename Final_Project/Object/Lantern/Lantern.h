#ifndef PROJECT_LANTERN_H
#define PROJECT_LANTERN_H

#include "Firebag/Firebag.h"
#include "../Gate/Pillar/Pillar.h"

class Lantern {
private:
	Firebag firebag;
	Pillar pillar;

public:
	Lantern();
	// material info for roof tile, roof stand, paper, frame, pillar, and light
	Lantern(
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
		float lshine, float x, float y, float z);
	void render();
};

#endif //PROJECT_LANTERN_H