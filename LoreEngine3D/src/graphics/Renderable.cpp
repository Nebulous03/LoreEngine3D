#include "Renderable.h"

Renderable::Renderable(Mesh& mesh, Shader& shader, Matrix4f& translation) : _mesh(&mesh), _shader(&shader), _translation(&translation) {}

Mesh* Renderable::getMesh() const
{
	return _mesh;
}

Shader* Renderable::getShader() const
{
	return _shader;
}

Matrix4f* Renderable::getTranslation() const
{
	return _translation;
}