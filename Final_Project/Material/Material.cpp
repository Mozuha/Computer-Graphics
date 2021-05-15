#include "Material.h"
#include "Material_types.h"
#include <GL/glut.h>

Material::Material() {
	for (int i = 0; i < 3; i++) {
		this->mat_ambient[i] = 0.2;
		this->mat_diffuse[i] = 0.8;
		this->mat_specular[i] = 0.0;
		this->mat_emission[i] = 0.0;
	}
	this->mat_ambient[3] = this->mat_diffuse[3] = this->mat_specular[3] = this->mat_emission[3] = 1.0;
	this->mat_shininess[0] = 0.0;
}

Material::Material(
	float mar, float mag, float mab, float maa,
	float mdr, float mdg, float mdb, float mda,
	float msr, float msg, float msb, float msa,
	float mer, float meg, float meb, float mea,
	float shine) {

	this->mat_ambient[0] = mar; this->mat_ambient[1] = mag; this->mat_ambient[2] = mab; this->mat_ambient[3] = maa;
	this->mat_diffuse[0] = mdr; this->mat_diffuse[1] = mdg; this->mat_diffuse[2] = mdb; this->mat_diffuse[3] = mda;
	this->mat_specular[0] = msr; this->mat_specular[1] = msg; this->mat_specular[2] = msb; this->mat_specular[3] = msa;
	this->mat_emission[0] = mer; this->mat_emission[1] = meg; this->mat_emission[2] = meb; this->mat_emission[3] = mea;
	this->mat_shininess[0] = shine;
}

void Material::define(int mat_type) {
	switch (mat_type) {

	case GATE_PILLAR:
		// #FB3C02
		//mat_ambient[0] = 0.9; mat_ambient[1] = 0.2; mat_ambient[2] = 0.2; mat_ambient[3] = 1.0;
		mat_ambient[0] = 0.98047; mat_ambient[1] = 0.23438; mat_ambient[2] = 0.00781; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.98047; mat_diffuse[1] = 0.23438; mat_diffuse[2] = 0.00781; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.1; mat_specular[1] = 0.1; mat_specular[2] = 0.1; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case FIREBAG_ROOF:
		// #383630
		//mat_ambient[0] = 0.2; mat_ambient[1] = 0.2; mat_ambient[2] = 0.2; mat_ambient[3] = 1.0;
		mat_ambient[0] = 0.21875; mat_ambient[1] = 0.21094; mat_ambient[2] = 0.18750; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.21875; mat_diffuse[1] = 0.21094; mat_diffuse[2] = 0.18750; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.1; mat_specular[1] = 0.1; mat_specular[2] = 0.1; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case FIREBAG_PAPER:
		// #FBFAF5
		//mat_ambient[0] = 0.2; mat_ambient[1] = 0.2; mat_ambient[2] = 0.2; mat_ambient[3] = 1.0;
		//mat_ambient[0] = 0.98047; mat_ambient[1] = 0.97656; mat_ambient[2] = 0.95703; mat_ambient[3] = 1.0;
		//mat_diffuse[0] = 0.98047; mat_diffuse[1] = 0.97656; mat_diffuse[2] = 0.95703; mat_diffuse[3] = 1.0;
		// #FFFFF1, #FFDB4F
		mat_ambient[0] = 0.99610; mat_ambient[1] = 0.85547; mat_ambient[2] = 0.30859; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.99610; mat_diffuse[1] = 0.99610; mat_diffuse[2] = 0.94141; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.99610; mat_specular[1] = 0.85547; mat_specular[2] = 0.30859; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case LANTERN_PILLAR:
		// #FF251E
		//mat_ambient[0] = 0.2; mat_ambient[1] = 0.2; mat_ambient[2] = 0.2; mat_ambient[3] = 1.0;
		mat_ambient[0] = 0.99609; mat_ambient[1] = 0.14453; mat_ambient[2] = 0.11719; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.99609; mat_diffuse[1] = 0.14453; mat_diffuse[2] = 0.11719; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.1; mat_specular[1] = 0.1; mat_specular[2] = 0.1; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case SUNDIAL:
		// #A3A3A2
		//mat_ambient[0] = 0.5; mat_ambient[1] = 0.5; mat_ambient[2] = 0.5; mat_ambient[3] = 1.0;
		mat_ambient[0] = 0.63672; mat_ambient[1] = 0.63672; mat_ambient[2] = 0.63281; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.63672; mat_diffuse[1] = 0.63672; mat_diffuse[2] = 0.63281; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.1; mat_specular[1] = 0.1; mat_specular[2] = 0.1; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case ICOSAHEDRON:
		// #7D4B28
		//mat_ambient[0] = 0.2; mat_ambient[1] = 0.2; mat_ambient[2] = 0.2; mat_ambient[3] = 1.0;
		mat_ambient[0] = 0.48828; mat_ambient[1] = 0.29297; mat_ambient[2] = 0.15625; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.48828; mat_diffuse[1] = 0.29297; mat_diffuse[2] = 0.15625; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.1; mat_specular[1] = 0.1; mat_specular[2] = 0.1; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case GROUND:
		// #2E7E16
		//mat_ambient[0] = 0.2; mat_ambient[1] = 0.2; mat_ambient[2] = 0.2; mat_ambient[3] = 1.0;
		mat_ambient[0] = 0.17969; mat_ambient[1] = 0.49219; mat_ambient[2] = 0.08594; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.17969; mat_diffuse[1] = 0.49219; mat_diffuse[2] = 0.08594; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.1; mat_specular[1] = 0.1; mat_specular[2] = 0.1; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case WALL:
		// #007B43
		//mat_ambient[0] = 0.2; mat_ambient[1] = 0.2; mat_ambient[2] = 0.2; mat_ambient[3] = 1.0;
		mat_ambient[0] = 0.0; mat_ambient[1] = 0.48047; mat_ambient[2] = 0.26172; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.0; mat_diffuse[1] = 0.48047; mat_diffuse[2] = 0.26172; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.1; mat_specular[1] = 0.1; mat_specular[2] = 0.1; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case ROAD:
		// #716F68
		//mat_ambient[0] = 0.2; mat_ambient[1] = 0.2; mat_ambient[2] = 0.2; mat_ambient[3] = 1.0;
		mat_ambient[0] = 0.44141; mat_ambient[1] = 0.43359; mat_ambient[2] = 0.40625; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.44141; mat_diffuse[1] = 0.43359; mat_diffuse[2] = 0.40625; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.1; mat_specular[1] = 0.1; mat_specular[2] = 0.1; mat_specular[3] = 1.0;
		mat_shininess[0] = 5.0;
		break;

	case SUN_LIGHT:
		mat_ambient[0] = 1.0; mat_ambient[1] = 1.0; mat_ambient[2] = 0.0; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.0; mat_diffuse[1] = 0.0; mat_diffuse[2] = 0.0; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.0; mat_specular[1] = 0.0; mat_specular[2] = 0.0; mat_specular[3] = 1.0;
		mat_emission[0] = 1.0; mat_emission[1] = 1.0; mat_emission[2] = 0.0; mat_emission[3] = 1.0;
		mat_shininess[0] = 5.0;

	case LANTERN_LIGHT:
		// #FFDB4F
		mat_ambient[0] = 0.99610; mat_ambient[1] = 0.85547; mat_ambient[2] = 0.30859; mat_ambient[3] = 1.0;
		mat_diffuse[0] = 0.0; mat_diffuse[1] = 0.0; mat_diffuse[2] = 0.0; mat_diffuse[3] = 1.0;
		mat_specular[0] = 0.99610; mat_specular[1] = 0.85547; mat_specular[2] = 0.30859; mat_specular[3] = 1.0;
		mat_emission[0] = 0.1; mat_emission[1] = 0.1; mat_emission[2] = 0.1; mat_emission[3] = 0.1;
		mat_shininess[0] = 5.0;

	default:
		break;
	}
}

void Material::apply() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void Material::apply_light() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
}