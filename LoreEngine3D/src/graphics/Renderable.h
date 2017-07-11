#pragma once
#include "Mesh.h"
#include "Shader.h"

class Renderable
{
private:

	Mesh* _mesh;
	Matrix4f* _translation;

public:

	Renderable(Mesh* mesh, Matrix4f* translation = &Matrix4f::Translation(0,0,0));
	virtual ~Renderable();
	
	Mesh* getMesh() const;
	Matrix4f* getTranslation() const;

};