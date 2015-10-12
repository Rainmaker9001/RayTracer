#include "Shape.h"

//methods for spheres

Sphere::Sphere(STPoint3 center, float radius) {
	this->center = center;
	this->radius = radius;
}

Intersection* Sphere::intersect(Ray ray) {
	STVector3 dir = ray.direction;
	STVector3 cam = STVector3(ray.startPoint);

	//get A, B, and C for quadratic formula
	float A = dir.LengthSq();
	STVector3 bvect = 2 * STVector3::DirectProduct(dir, cam - STVector3(center));
	float B = bvect.x + bvect.y + bvect.z;
	float C = (cam - STVector3(center)).LengthSq() - radius * radius;

	//plug into quadratic formula
	if ((B * B - 4 * A * C) < 0) return NULL; //remove imaginary
	float t1 = (-1 * B - sqrt(B * B - 4 * A * C)) / 2 / A;
	float t2 = (-1 * B + sqrt(B * B - 4 * A * C)) / 2 / A;

	float t = min(t1, t2);
	if (t < 1) return NULL; //if t < 1, no intersection

	//generate intersection point
	STPoint3 intPoint = STPoint3(cam + t * dir);

	//generate normal
	STVector3 normal = STVector3(intPoint) - STVector3(center);
	normal.Normalize();

	return new Intersection(t, intPoint, normal);
}


//methods for triangles

Triangle::Triangle(STPoint3 p1, STPoint3 p2, STPoint3 p3) {
	p = p1;
	q = p2;
	r = p3;
}

Intersection* Triangle::intersect(Ray ray) {
	//compute alpha, beta, gamma, and t with Cramer's rule
	STVector3 D = ray.direction;
	STVector3 A = STVector3(ray.startPoint);
	float a = p.x - r.x, b = p.y - r.y, c = p.z - r.z;
	float d = q.x - r.x, e = q.y - r.y, f = q.z - r.z;
	float g = -1 * D.x, h = -1 * D.y, i = -1 * D.z;
	float j = A.x - r.x, k = A.y - r.y, l = A.z - r.z;
	float g1 = e * i - h * f, g2 = g * f - d * i, g3 = d * h - e * g;
	float g4 = a * k - j * b, g5 = j * c - a * l, g6 = b * l - k * c;
	float M = a * g1 + b * g2 + c * g3;
	float alpha = (j * g1 + k * g2 + l * g3) / M;
	float beta = (i * g4 + h * g5 + g * g6) / M;
	float t = -1 * (f * g4 + e * g5 + d * g6) / M;
	float gamma = 1 - alpha - beta;

	//Compute if intersection occurred; if so, compute intersection
	if (alpha > 0 && beta > 0 && gamma > 0 && t > 1) {
		STPoint3 hitPoint = p * alpha + STVector3(q * beta) + STVector3(r * gamma);
		STVector3 normal = STVector3::Cross( (r - p), (q - p) );

		//make sure normal is facing right direction
		if (STVector3::Dot(D, normal) > 0) normal *= -1;

		normal.Normalize();
		return new Intersection(t, hitPoint, normal);
	}
	else return NULL;

}
