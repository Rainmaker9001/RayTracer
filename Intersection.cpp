#include "Intersection.h"

Intersection::Intersection(float t, STPoint3 intPoint, STVector3 normal) {
	this->t = t;
	this->intPoint = intPoint;
	this->normal = normal;
}