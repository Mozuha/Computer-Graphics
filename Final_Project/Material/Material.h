#ifndef PROJECT_MATERIAL_H
#define PROJECT_MATERIAL_H

class Material {
private:
	float mat_ambient[4], mat_diffuse[4], mat_specular[4], mat_emission[4], mat_shininess[1];

public:
	Material();
	Material(
		float mar, float mag, float mab, float maa,
		float mdr, float mdg, float mdb, float mda,
		float msr, float msg, float msb, float msa,
		float mer, float meg, float meb, float mea,
		float shine);
	void define(int mat_type);
	void apply();
	void apply_light();
};

#endif //PROJECT_MATERIAL_H