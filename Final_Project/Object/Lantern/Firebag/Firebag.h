#ifndef PROJECT_FIREBAG_H
#define PROJECT_FIREBAG_H

#include "Firebag_roof/Firebag_roof.h"
#include "Firebag_paper/Firebag_paper.h"
#include "Firebag_frame/Firebag_frame.h"
#include "../../Light/Light.h"

class Firebag {
private:
	Firebag_roof firebag_roof;
	Firebag_paper firebag_paper;
	Firebag_frame firebag_frame;
	Light light;

public:
	Firebag();
	// material info for roof tile, roof stand, paper, and frame
	Firebag(
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
		float lshine, float x, float y, float z);
	void render();
};

#endif //PROJECT_FIREBAG_H