#include "Light.h"

//for PointLight
PointLight::PointLight(STPoint3 position, STColor3f color) {
	this->position = position;
	this->color = color;
}

STVector3 PointLight::surfaceToLight(STPoint3 surfacePoint) {
	return position - surfacePoint;
}


//for DirectionalLight
DirectionalLight::DirectionalLight(STVector3 direction, STColor3f color) {
	this->direction = direction;
	this->color = color;
}

STVector3 DirectionalLight::surfaceToLight(STPoint3 surfacePoint) {
	return -1 * direction;
}