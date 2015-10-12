#pragma once
#include "st.h"
#include "Intersection.h"
#include "Ray.h"
using namespace std;
#include <iostream>

//abstract class that represents a geometric primitive in the scene
class Shape {
public:
	//determines whether a given ray interesects with the shape
	virtual Intersection* intersect(Ray ray) = 0;
};

//reprsents a sphere in the scene
class Sphere: public Shape {
public: 
	Sphere(STPoint3 center, float radius);
	Intersection* intersect(Ray ray);
private:
	STPoint3 center;
	float radius;
};

//represents a triangle in the scene
class Triangle: public Shape {
public:
	Triangle(STPoint3 p1, STPoint3 p2, STPoint3 p3);
	Intersection* intersect(Ray ray);
private:
	STPoint3 p;
	STPoint3 q;
	STPoint3 r;
};