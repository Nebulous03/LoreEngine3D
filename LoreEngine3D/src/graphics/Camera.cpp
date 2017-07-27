#include "camera.h"
#include "../logic/Input.h"

Camera::Camera(const Vector3f pos, const Vector3f rot, const uint projection, const float width, const float height, const float fov) :
	_pos(pos), _rot(rot), _projectionType(projection), _width(width), _height(height), _fov(fov)
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

	_rotation = Matrix4f::Rotation(rot);
	_translation = Matrix4f::Translation(pos);

	updateVectors();
}

Camera& Camera::resize(const float width, const float height)
{
	_width = width;
	_height = height;
	switch (_projectionType)
	{
	case CAMERA_ORTOGRAPHIC:
		_projectionMatrix = Matrix4f::Orthographic(0, width, 0, height, -1.0f, 1.0f);
		break;
	case CAMERA_PERSPECTIVE:
		_projectionMatrix = Matrix4f::Perspective(_fov, width / height, NEAR_PLANE, FAR_PLANE);
		break;
	default:
		break;
	}
	return *this;
}

Camera& Camera::move(const Vector3f& direction, const float speed)
{
	Vector3f temp = direction; temp.mul(speed);
	_pos += temp;
	_translation = Matrix4f::Translation(_pos);
	return *this;
}

Camera& Camera::rotate(const Vector3f& axis, const float angle)
{
	Vector3f temp = axis; temp.mul(angle);
	_rot += temp;

	if (_rot.x >= 360.0f) _rot.x -= 360.0f;
	if (_rot.x <= -360.0f) _rot.x += 360.0f;

	if (_rot.y >= 360.0f) _rot.y -= 360.0f;
	if (_rot.y <= -360.0f) _rot.y += 360.0f;

	if (_rot.z >= 360.0f) _rot.z -= 360.0f;
	if (_rot.z <= -360.0f) _rot.z += 360.0f;

	_rotation = Matrix4f::Rotation(_rot);
	updateVectors();
	return *this;
}

Camera& Camera::setPosition(const Vector3f pos)
{
	_pos = pos;
	_translation = Matrix4f::Translation(_pos);
	return *this;
}

Camera& Camera::setRotation(const Vector3f rot)
{
	_rot = rot;
	_rotation = Matrix4f::Rotation(_rot);
	return *this;
}

const Vector3f& Camera::getPosition()
{
	return _pos;
}

const Vector3f& Camera::getRotation()
{
	return _rot;
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

const Matrix4f& Camera::getProjection()
{
	return _projectionMatrix;
}

const Matrix4f Camera::getView()
{
	return _rotation * _translation;
}

const Vector3f Camera::getUp()
{
	return _up;
}

const Vector3f Camera::getForward()
{
	return _forward;
}

const Vector3f Camera::getRight()
{
	return _right;
}

const Matrix4f& Camera::getTranslationMatrix()
{
	return _translation;
}

const Matrix4f& Camera::getRotationMatrix()
{
	return _rotation;
}

uint Camera::getProjectionType() const
{
	return _projectionType;
}

void Camera::updateVectors()
{
	_forward.x = _rotation[2 + 0 * 4];
	_forward.y = _rotation[2 + 1 * 4];
	_forward.z = _rotation[2 + 2 * 4];
	_right = (Vector3f::cross(_forward, vec3f(0, 1, 0))).normalize();
	_up = (Vector3f::cross(_right, _forward)).normalize();
}