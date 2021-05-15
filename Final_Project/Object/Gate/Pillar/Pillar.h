#ifndef PROJECT_PILLAR_H
#define PROJECT_PILLAR_H

#include "../../../Material/Material.h"

class Pillar {
private:
	Material material;

public:
	Pillar();
	Pillar(int mat_type);
	Pillar(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void render();
};

#endif //PROJECT_PILLAR_H