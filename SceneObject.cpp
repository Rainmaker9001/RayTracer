#include "SceneObject.h"

SceneObject::SceneObject(Shape* shape, Material* material, STTransform4 transform) {
	this->shape = shape;
	this->material = material;
	this->transform = transform;
}