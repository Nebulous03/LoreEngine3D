#pragma once
#include <iostream>
#include <string>

struct Vector2f {

	float x = 0;
	float y = 0;

	Vector2f(const float& x, const float& y);

	Vector2f& add(const float otherX, const float otherY);
	Vector2f& add(const Vector2f& other, Vector2f& dest);
	Vector2f& add(const Vector2f& other);
	Vector2f& sub(const float otherX, const float otherY);
	Vector2f& sub(const Vector2f& other, Vector2f& dest);
	Vector2f& sub(const Vector2f& other);
	Vector2f& mul(const float otherX, const float otherY);
	Vector2f& mul(const Vector2f& other, Vector2f& dest);
	Vector2f& mul(const Vector2f& other);
	Vector2f& div(const float otherX, const float otherY);
	Vector2f& div(const Vector2f& other, Vector2f& dest);
	Vector2f& div(const Vector2f& other);

	friend Vector2f operator+(Vector2f first, const Vector2f& second);
	friend Vector2f operator-(Vector2f first, const Vector2f& second);
	friend Vector2f operator*(Vector2f first, const Vector2f& second);
	friend Vector2f operator/(Vector2f first, const Vector2f& second);

	Vector2f& operator+=(const Vector2f& other);
	Vector2f& operator-=(const Vector2f& other);
	Vector2f& operator*=(const Vector2f& other);
	Vector2f& operator/=(const Vector2f& other);

	bool operator==(const Vector2f& other);
	bool operator!=(const Vector2f& other);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vector2f);

};

struct Vector3f {

	float x = 0;
	float y = 0;
	float z = 0;

	Vector3f(const float& x, const float& y, const float& z);

	Vector3f& add(const float otherX, const float otherY, const float otherZ);
	Vector3f& add(const Vector3f& other, Vector3f& dest);
	Vector3f& add(const Vector3f& other);
	Vector3f& sub(const float otherX, const float otherY, const float otherZ);
	Vector3f& sub(const Vector3f& other, Vector3f& dest);
	Vector3f& sub(const Vector3f& other);
	Vector3f& mul(const float otherX, const float otherY, const float otherZ);
	Vector3f& mul(const Vector3f& other, Vector3f& dest);
	Vector3f& mul(const Vector3f& other);
	Vector3f& div(const float otherX, const float otherY, const float otherZ);
	Vector3f& div(const Vector3f& other, Vector3f& dest);
	Vector3f& div(const Vector3f& other);

	Vector2f xy();

	friend Vector3f operator+(Vector3f first, const Vector3f& second);
	friend Vector3f operator-(Vector3f first, const Vector3f& second);
	friend Vector3f operator*(Vector3f first, const Vector3f& second);
	friend Vector3f operator/(Vector3f first, const Vector3f& second);

	Vector3f& operator+=(const Vector3f& other);
	Vector3f& operator-=(const Vector3f& other);
	Vector3f& operator*=(const Vector3f& other);
	Vector3f& operator/=(const Vector3f& other);

	bool operator==(const Vector3f& other);
	bool operator!=(const Vector3f& other);

	friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vector3f);

};

struct Vector4f {

	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;

	Vector4f(const float& x, const float& y, const float& z, const float& w);

	Vector4f& add(const float otherX, const float otherY, const float otherZ, const float otherW);
	Vector4f& add(const Vector4f& other, Vector4f& dest);
	Vector4f& add(const Vector4f& other);
	Vector4f& sub(const float otherX, const float otherY, const float otherZ, const float otherW);
	Vector4f& sub(const Vector4f& other, Vector4f& dest);
	Vector4f& sub(const Vector4f& other);
	Vector4f& mul(const float otherX, const float otherY, const float otherZ, const float otherW);
	Vector4f& mul(const Vector4f& other, Vector4f& dest);
	Vector4f& mul(const Vector4f& other);
	Vector4f& div(const float otherX, const float otherY, const float otherZ, const float otherW);
	Vector4f& div(const Vector4f& other, Vector4f& dest);
	Vector4f& div(const Vector4f& other);

	Vector2f xy();
	Vector3f xyz();

	friend Vector4f operator+(Vector4f first, const Vector4f& second);
	friend Vector4f operator-(Vector4f first, const Vector4f& second);
	friend Vector4f operator*(Vector4f first, const Vector4f& second);
	friend Vector4f operator/(Vector4f first, const Vector4f& second);

	Vector4f& operator+=(const Vector4f& other);
	Vector4f& operator-=(const Vector4f& other);
	Vector4f& operator*=(const Vector4f& other);
	Vector4f& operator/=(const Vector4f& other);

	bool operator==(const Vector4f& other);
	bool operator!=(const Vector4f& other);

	friend std::ostream& operator<<(std::ostream& stream, const Vector4f& vector4f);

};