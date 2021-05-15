#ifndef PROJECT_ICOSAHEDRON_H
#define PROJECT_ICOSAHEDRON_H

#include "../../Material/Material.h"
#include "../Light/Light.h"

class Icosahedron {
private:
	Material material;
	Light light;

public:
	Icosahedron();
	Icosahedron(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void render();
};

#endif //PROJECT_ICOSAHEDRON_H