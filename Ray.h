#pragma once
#include "st.h"

class Ray
{
	public:
		//constructor
		Ray(STPoint3 startPoint, STVector3 direction, float minT, float maxT);
		
		//instance variables
		STPoint3 startPoint;
		STVector3 direction;
		float minT; 
		float maxT;
};


