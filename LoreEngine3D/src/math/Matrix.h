#pragma once
#include "Vector.h"

#define X_AXIS Vector3f(1,0,0)
#define Y_AXIS Vector3f(0,1,0)
#define Z_AXIS Vector3f(0,0,1)

#define MATRIX4F_SIZE 4 * 4

struct Matrix4f {

	union
	{
		float elements[MATRIX4F_SIZE];
		Vector4f columns[4];
	};

	Matrix4f();
	Matrix4f(const float fill);

	Matrix4f& add(const Matrix4f& other);
	Matrix4f& sub(const Matrix4f& other);
	Matrix4f& mul(const Matrix4f& other);

	Vector2f& mul(const Vector2f& other) const;
	Vector3f& mul(const Vector3f& other) const;
	Vector4f& mul(const Vector4f& other) const;

	friend Matrix4f operator+(Matrix4f left, const Matrix4f& right);
	friend Matrix4f operator-(Matrix4f left, const Matrix4f& right);
	friend Matrix4f operator*(Matrix4f left, const Matrix4f& right);

	friend Vector2f operator*(Matrix4f left, const Vector2f& right);
	friend Vector3f operator*(Matrix4f left, const Vector3f& right);
	friend Vector4f operator*(Matrix4f left, const Vector4f& right);

	Matrix4f& operator+=(const Matrix4f& other);
	Matrix4f& operator-=(const Matrix4f& other);
	Matrix4f& operator*=(const Matrix4f& other);

	static Matrix4f Perspective (
		const float fov,
		const float aspect,
		const float near,
		const float far
	);

	static Matrix4f Orthographic (
		const float left,
		const float right,
		const float bottom,
		const float top,
		const float near,
		const float far
	);

	static Matrix4f Identity();
	static Matrix4f Translation(const Vector3f& pos);
	static Matrix4f Rotation(const Vector3f& axis, const float angle);
	static Matrix4f Scale(const Vector3f& scale);

	static Matrix4f Translation(const float x, const float y, const float z);
	static Matrix4f Scale(const float sx, const float sy, const float sz);

	bool operator==(const Matrix4f& other);
	bool operator!=(const Matrix4f& other);

	float& operator[](const int i);
	friend std::ostream& operator<<(std::ostream& stream, const Matrix4f& matrix4f);

};