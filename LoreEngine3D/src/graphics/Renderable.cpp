#include "Renderable.h"

Renderable::Renderable(Mesh& mesh, Matrix4f translation) : _mesh(mesh), _translation(translation) {}

Mesh& Renderable::getMesh()
{
	return _mesh;
}

Matrix4f& Renderable::getTranslation()
{
	return _translation;
}