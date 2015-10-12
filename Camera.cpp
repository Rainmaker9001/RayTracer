#include "Camera.h"

Camera::Camera(STPoint3 location, STVector3 up, STVector3 lookAt, float fovyX, float fovyY) {

	//set values for camera location and orthonormal basis
	this->location = location;
	w = lookAt;
	w.Normalize();
	v = up - STVector3::Dot(up, w) * w;
	v.Normalize();
	u = STVector3::Cross(v, w);
	u.Normalize();


	//Initialize ImagePlane
	//get variables for calculation
	STPoint3 C = location + w; //center of ImagePlane
	float y = tan(fovyY / 2);
	float x = tan(fovyX / 2); 

	//calculate four corners of image plane
	STPoint3* LL = new STPoint3(C + x * u - y * v);
	STPoint3* UL = new STPoint3(C + x * u + y * v);
	STPoint3* LR = new STPoint3(C - x * u - y * v);
	STPoint3* UR = new STPoint3(C - x * u + y * v);

	screen = new ImagePlane(LL, UL, LR, UR);
}

//generate ray from camera to point on image plane
Ray Camera::genRay(int imX, int imY) {
	STVector3 direction = *(screen->imgToWorld(imX, imY)) - location;
	Ray ray = Ray(location, direction, 1.0, 99999999.0);
	return ray;
}

//compute color of pixel
Pixel Camera::findColor(vector<SceneObject*> objects, vector<Light*> lights, Intersection* intsct, STVector3 view) {
	STColor3f color(0, 0, 0);
	for (int i = 0 ; i < lights.size(); i++) {
		//get variables for calculation
		Material* material = objects[i]->material;
		Light* light = lights[i];
		STVector3 L = light->surfaceToLight(intsct->intPoint);
		L.Normalize();
		STVector3 N = intsct->normal;
		STVector3 R = view - 2 * N * STVector3::Dot(view, N);
		R.Normalize();

		//compute diffuse and specular
		STColor3f diffuse = material->diffuseRef * light->color * max(0, STVector3::Dot(L, N));
		STColor3f specular = material->specularRef * light->color * pow(max(0, STVector3::Dot(R, L)) , material->shine);
		color += diffuse + specular;
	}
	return color;
}

void Camera::fillScreen(vector<SceneObject*> objects, vector<Light*> lights, STColor3f ambient) {
	//sample at every pixel in screen
	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			Ray ray = genRay(i, j);
			float t = 999999999; //only color shape with closest t

			//check intersection with all shapes 
			for (int k = 0; k < objects.size(); k++) {
				Shape* shape = objects[k]->shape;
				Intersection* inter = shape->intersect(ray);

				//determine color and set it
				if (inter != NULL) { //if intersect
					if (inter->t < t) { //AND if this is the closest shape
						Pixel color = ambient + findColor(objects, lights, inter, ray.direction);
						screen->setPixel(i, j, color); 
					}
				}
			}
		}
	}
}