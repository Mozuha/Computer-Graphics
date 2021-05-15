#ifndef PROJECT_WALL_H
#define PROJECT_WALL_H

#include "../../Material/Material.h"

class Wall {
private:
	Material material;

public:
	Wall();
	Wall(int mat_type);
	Wall(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void render();
};

#endif //PROJECT_WALL_H