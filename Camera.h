#pragma once
#include "st.h"
#include "Ray.h"
#include "ImagePlane.h"
#include "SceneObject.h"
#include "Light.h"
using namespace std;

//Represents the virtual scene camera
//Generates viewing rays 
class Camera
{
	public:
		//constructor
		Camera(STPoint3 location, STVector3 up, STVector3 lookAt, float fovyX, float fovyY);

		//generates viewing ray from camera location to point on image plane
		Ray genRay(int imX, int imY);

		//finds specular and diffuse color of pixel
		Pixel findColor(vector<SceneObject*> objects, vector<Light*> lights, Intersection* intsct, STVector3 view);

		//get everything going; shine rays through screen and determine colors
		void fillScreen(vector<SceneObject*> objects, vector<Light*> lights, STColor3f ambient);


		ImagePlane* screen; //defines pixels that user sees

	private:
		//orthonormal basis for camera
		STVector3 w;
		STVector3 v;
		STVector3 u; 

		STPoint3 location; //camera location


};