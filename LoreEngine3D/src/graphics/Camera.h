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
	float _fov;

	Vector3f _pos;
	Vector3f _rot;

	Matrix4f _rotation;
	Matrix4f _translation;

	Vector3f _forward;
	Vector3f _right;
	Vector3f _up;

	Matrix4f _projectionMatrix;
	uint _projectionType;

	void updateVectors();

public:

	Camera(const Vector3f pos, const Vector3f rot, const uint projection, const float width, const float height, const float fov = DEFAULT_FOV);

	Camera& resize(const float width, const float height);

	Camera& move(const Vector3f& direction, const float speed);

	Camera& rotate(const Vector3f& rotation, const float speed);
	Camera& rotateX(const float angle);
	Camera& rotateY(const float angle);
	Camera& rotateZ(const float angle);

	const Vector3f& getPosition();
	const Vector3f& getRotation();

	Camera& setPosition(const Vector3f pos);
	Camera& setRotation(const Vector3f rot);

	float getFOV() const;
	Camera& setFOV(const float fov);

	const Matrix4f& getTranslationMatrix();
	const Matrix4f& getRotationMatrix();

	const Matrix4f& getProjection();
	const Matrix4f getView();

	const Vector3f getUp();
	const Vector3f getForward();
	const Vector3f getRight();

	uint getProjectionType() const;

};