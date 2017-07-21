#pragma once
#include "Mesh.h"
#include "Shader.h"

class Renderable
{
private:

	Mesh& _mesh;
	Matrix4f _transform;

public:

	Renderable(Mesh& mesh, Matrix4f transform = Matrix4f::Translation(0,0,0));
	
	Mesh& getMesh();
	Matrix4f& getTransform();

};