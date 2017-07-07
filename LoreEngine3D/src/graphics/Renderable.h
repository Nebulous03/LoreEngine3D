#pragma once
#include "Mesh.h"
#include "Shader.h"

class Renderable
{
private:

	Mesh* _mesh;
	Shader* _shader;

	Matrix4f* _translation;	// Move?

public:

	Renderable(Mesh& mesh, Shader& shader, Matrix4f& translation = Matrix4f::Translation(0,0,0));
	
	Mesh* getMesh() const;
	Shader* getShader() const;
	Matrix4f* getTranslation() const;

};