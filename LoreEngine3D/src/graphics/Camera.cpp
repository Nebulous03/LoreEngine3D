#include "camera.h"

Camera::Camera(const Vector3f pos, const uint projection, const float width, const float height, const float fov) :
	_position(pos), _projectionType(projection), _fov(fov)
{
	switch (projection)
	{
	case CAMERA_ORTOGRAPHIC:
		_projectionMatrix = Matrix4f::Orthographic(0, width, 0, height, -1.0f, 1.0f);
		break;
	case CAMERA_PERSPECTIVE:
		_projectionMatrix = Matrix4f::Perspective(fov, width / height, NEAR_PLANE, FAR_PLANE);
		break;
	default:
		break;
	}

	_viewMatix = Matrix4f::Identity();
}

Camera& Camera::move(const Vector3f& direction, const float speed)
{
	_position += (direction * speed);
	_viewMatix *= Matrix4f::Translation((direction * -speed));	//Fixme: Might cause errors
	return *this;
}

Camera& Camera::rotate(const Vector3f& axis, const float degrees)
{
	//_rotation += (delta)
	_viewMatix *= Matrix4f::Rotation(axis, degrees);
	return *this;
}

Camera& Camera::setPosition(const Vector3f pos)
{
	_position = pos;
	_viewMatix = Matrix4f::Translation(pos);
	return *this;
}

Vector3f& Camera::getPosition()
{
	return _position;
}

float Camera::getFOV() const
{
	return _fov;
}

Camera& Camera::setFOV(const float fov)
{
	_fov = fov;
	return *this;
}

Matrix4f& Camera::getProjection()
{
	return _projectionMatrix;
}

Matrix4f& Camera::getView()
{
	return _viewMatix;
}

uint Camera::getProjectionType() const
{
	return _projectionType;
}