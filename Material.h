#include "st.h"

//stores the ambient, diffuse, specular, mirror reflectance properties of a material
//as well as its shininess
class Material {
public:
	Material(STColor3f ambient, STColor3f diffuse, STColor3f specular, STColor3f mirror, float shine);

	STColor3f ambientRef;
	STColor3f diffuseRef;
	STColor3f specularRef;
	STColor3f mirrorRef;
	float shine;
};
