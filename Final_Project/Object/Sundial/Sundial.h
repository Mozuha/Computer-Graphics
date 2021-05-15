#ifndef PROJECT_SUNDIAL_H
#define PROJECT_SUNDIAL_H

#include "Cylinder/Cylinder.h"
#include "Stick/Stick.h"
#include "../../Material/Material.h"

class Sundial {
private:
	Cylinder cylinder;
	Stick stick;
	Material material;

public:
	Sundial();
	Sundial(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine, float radius, float height);
	void render();
};

#endif //PROJECT_SUNDIAL_H