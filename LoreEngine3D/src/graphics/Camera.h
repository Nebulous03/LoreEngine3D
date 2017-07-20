#pragma once
#include "../math/Math.h"

#define CAMERA_ORTOGRAPHIC	0
#define CAMERA_PERSPECTIVE	1

#define NEAR_PLANE	0.0001f
#define FAR_PLANE	1000.0f

#define DEFAULT_FOV 90.0f

class Camera
{
protected:

	float _width;
	float _height;

	Vector3f _position;
	Vector3f _rotation;

	float _fov;

	Matrix4f _projectionMatrix;
	Matrix4f _viewMatix;

	uint _projectionType;

public:

	Camera(const Vector3f pos, const uint projection, const float width, const float height, const float fov = DEFAULT_FOV);

	Camera& resize(const float width, const float height);

	Camera& move(const Vector3f& direction, const float speed);
	//Camera& move(Vector3f angle, float delta);

	Camera& rotate(const Vector3f& axis, const float degrees);

	Vector3f& getPosition();
	Camera& setPosition(const Vector3f pos);

	float getFOV() const;
	Camera& setFOV(const float fov);

	Matrix4f& getProjection();
	Matrix4f& getView();

	uint getProjectionType() const;

};