#include "camera.h"

Camera::Camera(const Vector3f pos, const uint projection, const float width, const float height, const float fov) :
	_position(pos), _projectionType(projection), _width(width), _height(height), _fov(fov)
{
	_upDirection = Vector3f(0.0f, 1.0f, 0.0f);
	_rightDirection = Vector3f(1.0f, 0.0f, 0.0f);
	_forwardDirection = Vector3f(0.0f, 0.0f, -1.0f);
	_rotation = Vector3f(0.0f, 0.0f, 0.0f);

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

	_viewMatix = Matrix4f::Translation(pos);
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
	_position += temp;
	//_viewMatix *= Matrix4f::Translation(temp);
	return *this;
}

Camera& Camera::move(CameraDirection direction, const float speed)
{
	switch (direction)
	{
	case FORWARD: move(getForward(), speed);
	default:
		break;
	}
	return *this;
}

Camera& Camera::rotate(const Vector3f& rotation, const float speed)
{
	Vector3f temp = rotation;  temp.mul(speed);	// Meh.
	_rotation += temp;

	Vector3f tempFront;
	tempFront.x = cos(toRadians(_rotation.y)) * cos(toRadians(_rotation.x));
	tempFront.y = sin(toRadians(_rotation.x));
	tempFront.z = sin(toRadians(_rotation.y)) * cos(toRadians(_rotation.x));

	_forwardDirection = tempFront.normalize();

	//_forwardDirection = _rotation;

	//_viewMatix *= Matrix4f::Rotation(temp);
	return *this;
}

Camera& Camera::setPosition(const Vector3f pos)
{
	_position = pos;
	_viewMatix = Matrix4f::Translation(pos);
	return *this;
}

const Vector3f& Camera::getPosition()
{
	return _position;
}

const Vector3f& Camera::getRotation()
{
	return _rotation;
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

const Matrix4f& Camera::getView()
{
	return Matrix4f::Rotation(_rotation + _position) * Matrix4f::Translation(_position);
}

const Vector3f Camera::getUp()
{
	return Vector3f::cross(_rightDirection, _forwardDirection).normalize();
}

const Vector3f Camera::getForward()
{
	return _forwardDirection;
}

const Vector3f Camera::getRight()
{
	return Vector3f::cross(_forwardDirection, _upDirection).normalize();
}

uint Camera::getProjectionType() const
{
	return _projectionType;
}