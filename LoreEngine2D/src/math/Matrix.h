#pragma once

#include "Vector.h"

#define MATRIX4F_SIZE 16

struct Matrix4f {

	float elements[MATRIX4F_SIZE];

	Matrix4f();
	Matrix4f(const float fill);

	Matrix4f& add(const Matrix4f& other);
	Matrix4f& sub(const Matrix4f& other);
	Matrix4f& mul(const Matrix4f& other);
	Matrix4f& div(const Matrix4f& other);

	friend Matrix4f operator+(Matrix4f left, const Matrix4f& right);
	friend Matrix4f operator-(Matrix4f left, const Matrix4f& right);
	friend Matrix4f operator*(Matrix4f left, const Matrix4f& right);
	friend Matrix4f operator/(Matrix4f left, const Matrix4f& right);

	Matrix4f& operator+=(const Matrix4f& other);
	Matrix4f& operator-=(const Matrix4f& other);
	Matrix4f& operator*=(const Matrix4f& other);
	Matrix4f& operator/=(const Matrix4f& other);

	static Matrix4f Perspective(
		const float fov,
		const float aspect,
		const float near,
		const float far
	);

	static Matrix4f Orthographic(
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

	bool operator==(const Matrix4f& other);
	bool operator!=(const Matrix4f& other);

	float& operator[](const int i);
	friend std::ostream& operator<<(std::ostream& stream, const Matrix4f& matrix4f);

};