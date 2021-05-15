#ifndef PROJECT_LIGHT_H
#define PROJECT_LIGHT_H

#include "../../Material/Material.h"

class Light {
private:
	float x, y, z;
	Material material;

public:
	Light();
	Light(float x, float y, float z, int mat_type);
	Light(
		float x, float y, float z,
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void render();
};

#endif //PROJECT_LIGHT_H