#include "Renderable.h"

Renderable::Renderable(Mesh* mesh, Matrix4f* translation) : _mesh(mesh), _translation(translation) {}

Renderable::~Renderable()
{
	delete _mesh;
	delete _translation;
}

Mesh* Renderable::getMesh() const
{
	return _mesh;
}

Matrix4f* Renderable::getTranslation() const
{
	return _translation;
}