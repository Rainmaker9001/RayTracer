#include "Material.h"

Material::Material(STColor3f ambient, STColor3f diffuse, STColor3f specular, STColor3f mirror, float shine) {
	ambientRef = ambient;
	diffuseRef = diffuse;
	specularRef = specular;
	mirrorRef = mirror;
	this->shine = shine;
}