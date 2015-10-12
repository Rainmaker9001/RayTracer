#pragma once
#include "st.h"

//stores information about a ray-object instersection
class Intersection
{
	public:
		//constructor
		Intersection(float t, STPoint3 intPoint, STVector3 normal); 
		
		//instance variables
		float t; //t value at which intersection occurred
		STPoint3 intPoint; //point at which intersection occurred
		STVector3 normal; //the normal at the intersection point
};