#ifndef PROJECT_FIREBAG_PAPER_H
#define PROJECT_FIREBAG_PAPER_H

#include "../../../../Material/Material.h"

class Firebag_paper {
private:
	Material material;

public:
	Firebag_paper();
	Firebag_paper(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void render();
};

#endif //PROJECT_FIREBAG_PAPER_H