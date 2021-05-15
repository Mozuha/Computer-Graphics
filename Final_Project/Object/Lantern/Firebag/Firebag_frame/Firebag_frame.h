#ifndef PROJECT_FIREBAG_FRAME_H
#define PROJECT_FIREBAG_FRAME_H

#include "../../../../Material/Material.h"

class Firebag_frame {
private:
	Material material;

public:
	Firebag_frame();
	Firebag_frame(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void render();
};

#endif //PROJECT_FIREBAG_FRAME_H