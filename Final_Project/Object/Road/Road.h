#ifndef PROJECT_ROAD_H
#define PROJECT_ROAD_H

#include "../../Material/Material.h"

class Road {
private:
	Material material;

public:
	Road();
	Road(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void render();
};

#endif //PROJECT_ROAD_H