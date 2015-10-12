#include "Ray.h"

Ray::Ray(STPoint3 startPoint, STVector3 direction, float minT, float maxT) {
		this->startPoint = startPoint;
		this->direction = direction;
		this->minT = minT;
		this->maxT = maxT;
}

