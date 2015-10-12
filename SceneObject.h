#include "st.h"
#include "Shape.h"
#include "Material.h"

//aggregates a Shape, its Material, and its transform
class SceneObject {
public:
	SceneObject(Shape* shape, Material* material, STTransform4 transform);

	Shape* shape;
	Material* material;
	STTransform4 transform;
};
