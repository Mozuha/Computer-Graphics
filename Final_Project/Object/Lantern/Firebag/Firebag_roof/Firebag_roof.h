#ifndef PROJECT_FIREBAG_ROOF_H
#define PROJECT_FIREBAG_ROOF_H

#include "../../../../Material/Material.h"

class Firebag_roof {
private:
	Material material_tile, material_stand;
public:
	Firebag_roof();
	Firebag_roof(
		float tmar, float tmag, float tmab, float tmaa,
		float tmdr, float tmdg, float tmdb, float tmda,
		float tmsr, float tmsg, float tmsb, float tmsa,
		float tmer, float tmeg, float tmeb, float tmea,
		float tshine,
		float smar, float smag, float smab, float smaa,
		float smdr, float smdg, float smdb, float smda,
		float smsr, float smsg, float smsb, float smsa,
		float smer, float smeg, float smeb, float smea,
		float sshine);  // for tile and stand
	void render();
};

#endif //PROJECT_FIREBAG_ROOF_H