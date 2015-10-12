#pragma once
#include "st.h"

//an abstract class that represents a light source in the scene
class Light {
public: 
	//given a surface point, returns the direction from it to the light
	virtual STVector3 surfaceToLight(STPoint3 surfacePoint) = 0;
	
	STColor3f color;
};

class PointLight: public Light {
public:
	PointLight(STPoint3 position, STColor3f color);
	STVector3 surfaceToLight(STPoint3 surfacePoint);

	STPoint3 position;
};

class DirectionalLight: public Light {
public:
	DirectionalLight(STVector3 direction, STColor3f color);
	STVector3 surfaceToLight(STPoint3 surfacePoint);

	STVector3 direction;
};

