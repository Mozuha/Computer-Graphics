#ifndef PROJECT_GATE_H
#define PROJECT_GATE_H

#include "Pillar/Pillar.h"
#include "../../Material/Material.h"

class Gate {
private:
	Pillar pillar;
	Material material;

public:
	Gate();
	Gate(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void render();
};

#endif //PROJECT_GATE_H