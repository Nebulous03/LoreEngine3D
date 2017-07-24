#pragma once
#include "../math/Math.h"

#define CAMERA_ORTOGRAPHIC	0
#define CAMERA_PERSPECTIVE	1

#define NEAR_PLANE	0.0001f
#define FAR_PLANE	1000.0f

#define DEFAULT_FOV		90.0f
#define DEFAULT_PITCH	0.0f
#define DEFAULT_YAW		0.0f
#define DEFAULT_ROLL	0.0f

enum CameraDirection {
	FORWARD,
	BACKWARD,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Camera
{
protected:

	float _width;
	float _height;

	Vector3f _position;
	Vector3f _rotation;

	Vector3f _upDirection;
	Vector3f _rightDirection;
	Vector3f _forwardDirection;

	float _fov;

	Matrix4f _projectionMatrix;
	Matrix4f _viewMatix;

	uint _projectionType;

public:

	Camera(const Vector3f pos, const uint projection, const float width, const float height, const float fov = DEFAULT_FOV);

	Camera& resize(const float width, const float height);

	Camera& move(const Vector3f& direction, const float speed);
	Camera& move(CameraDirection direction, const float speed);

	Camera& rotate(const Vector3f& rotation, const float speed);

	const Vector3f& getPosition();
	const Vector3f& getRotation();

	Camera& setPosition(const Vector3f pos);

	float getFOV() const;
	Camera& setFOV(const float fov);

	const Matrix4f& getProjection();
	const Matrix4f& getView();

	const Vector3f getUp();
	const Vector3f getForward();
	const Vector3f getRight();

	uint getProjectionType() const;

};