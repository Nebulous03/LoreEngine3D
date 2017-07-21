#include "Renderable.h"

Renderable::Renderable(Mesh& mesh, Matrix4f transform) : _mesh(mesh), _transform(transform) {}

Mesh& Renderable::getMesh()
{
	return _mesh;
}

Matrix4f& Renderable::getTransform()
{
	return _transform;
}
