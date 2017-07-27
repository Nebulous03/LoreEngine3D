#include "Vector.h"
#include "Functions.h"
#include "Matrix.h"
#include <math.h>

/* ----------- Vector2f ----------- */


Vector2f::Vector2f(const float& x, const float& y) :
	x(x), y(y) {}

Vector2f::Vector2f(const float& fill) :
	x(fill), y(fill) {}

Vector2f& Vector2f::add(const float otherX, const float otherY)
{
	x = x + otherX;
	y = y + otherY;
	return *this;
}

Vector2f& Vector2f::add(const Vector2f& other, Vector2f& dest)
{
	dest.x = x + other.x;
	dest.y = y + other.y;
	return *this;
}

Vector2f& Vector2f::add(const Vector2f& other)
{
	x = x + other.x;
	y = y + other.y;
	return *this;
}

Vector2f& Vector2f::sub(const float otherX, const float otherY)
{
	x = x - otherX;
	y = y - otherY;
	return *this;
}

Vector2f& Vector2f::sub(const Vector2f& other, Vector2f& dest)
{
	dest.x = x - other.x;
	dest.y = y - other.y;
	return *this;
}

Vector2f& Vector2f::sub(const Vector2f& other)
{
	x = x - other.x;
	y = y - other.y;
	return *this;
}

Vector2f& Vector2f::mul(const float otherX, const float otherY)
{
	x = x * otherX;
	y = y * otherY;
	return *this;
}

Vector2f& Vector2f::mul(const Vector2f& other, Vector2f& dest)
{
	dest.x = x * other.x;
	dest.y = y * other.y;
	return *this;
}

Vector2f& Vector2f::mul(const Vector2f& other)
{
	x = x * other.x;
	y = y * other.y;
	return *this;
}

Vector2f& Vector2f::div(const float otherX, const float otherY)
{
	x = x / otherX;
	y = y / otherY;
	return *this;
}

Vector2f& Vector2f::div(const Vector2f& other, Vector2f& dest)
{
	dest.x = x / other.x;
	dest.y = y / other.y;
	return *this;
}

Vector2f& Vector2f::div(const Vector2f& other)
{
	x = x / other.x;
	y = y / other.y;
	return *this;
}

float Vector2f::dot(const Vector2f& vec3f, const Vector2f& other)
{
	return (vec3f.x * other.x) + (vec3f.y * other.y);
}

Vector2f operator+(Vector2f first, const Vector2f& second)
{
	return first.add(second);
}

Vector2f operator-(Vector2f first, const Vector2f& second)
{
	return first.sub(second);
}

Vector2f operator*(Vector2f first, const Vector2f& second)
{
	return first.mul(second);
}

Vector2f operator/(Vector2f first, const Vector2f& second)
{
	return first.div(second);
}

Vector2f& Vector2f::operator+=(const Vector2f& other)
{
	return add(other);
}

Vector2f& Vector2f::operator-=(const Vector2f& other)
{
	return sub(other);
}

Vector2f& Vector2f::operator*=(const Vector2f& other)
{
	return mul(other);
}

Vector2f& Vector2f::operator/=(const Vector2f& other)
{
	return div(other);
}

bool Vector2f::operator==(const Vector2f& other)
{
	return (x == other.x) && (y == other.y);
}

bool Vector2f::operator!=(const Vector2f& other)
{
	return (x != other.x) || (y != other.y);
}

std::ostream& operator<<(std::ostream& stream, const Vector2f& vector2f)
{
	stream << "(" << vector2f.x << ", " << vector2f.y << ")";
	return stream;
}


/* ----------- Vector3f ----------- */


Vector3f::Vector3f(const float& x, const float& y, const float& z) :
	x(x), y(y), z(z) {}

Vector3f::Vector3f(const float& fill) :
	x(fill), y(fill), z(fill) {}

Vector3f& Vector3f::add(const float otherX, const float otherY, const float otherZ)
{
	x = x + otherX;
	y = y + otherY;
	z = z + otherZ;
	return *this;
}

Vector3f& Vector3f::add(const Vector3f& other, Vector3f& dest)
{
	dest.x = x + other.x;
	dest.y = y + other.y;
	dest.z = z + other.z;
	return *this;
}

Vector3f& Vector3f::add(const Vector3f& other)
{
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
	return *this;
}

Vector3f& Vector3f::add(const float num)
{
	x = x + num;
	y = y + num;
	z = z + num;
	return *this;
}

Vector3f& Vector3f::sub(const float otherX, const float otherY, const float otherZ)
{
	x = x - otherX;
	y = y - otherY;
	z = z - otherZ;
	return *this;
}

Vector3f& Vector3f::sub(const Vector3f& other, Vector3f& dest)
{
	dest.x = x - other.x;
	dest.y = y - other.y;
	dest.z = z - other.z;
	return *this;
}

Vector3f& Vector3f::sub(const Vector3f& other)
{
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;
	return *this;
}

Vector3f& Vector3f::sub(const float num)
{
	x = x - num;
	y = y - num;
	z = z - num;
	return *this;
}

Vector3f& Vector3f::mul(const float otherX, const float otherY, const float otherZ)
{
	x = x * otherX;
	y = y * otherY;
	z = z * otherZ;
	return *this;
}

Vector3f& Vector3f::mul(const Vector3f& other, Vector3f& dest)
{
	dest.x = x * other.x;
	dest.y = y * other.y;
	dest.z = z * other.z;
	return *this;
}

Vector3f& Vector3f::mul(const Vector3f& other)
{
	x = x * other.x;
	y = y * other.y;
	z = z * other.z;
	return *this;
}

Vector3f& Vector3f::mul(const float num)
{
	x = x * num;
	y = y * num;
	z = z * num;
	return *this;
}

Vector3f& Vector3f::div(const float otherX, const float otherY, const float otherZ)
{
	x = x / otherX;
	y = y / otherY;
	z = z / otherZ;
	return *this;
}

Vector3f& Vector3f::div(const Vector3f& other, Vector3f& dest)
{
	dest.x = x / other.x;
	dest.y = y / other.y;
	dest.z = z / other.z;
	return *this;
}

Vector3f& Vector3f::div(const Vector3f& other)
{
	x = x / other.x;
	y = y / other.y;
	z = z / other.z;
	return *this;
}

Vector3f& Vector3f::div(const float num)
{
	x = x / num;
	y = y / num;
	z = z / num;
	return *this;
}

Vector3f& Vector3f::normalize()
{
	return div(magnitude());
}

Vector3f Vector3f::normalize(const Vector3f& vec3f)
{
	Vector3f result = vec3f;
	return result.normalize();	// Not great...
}

Vector3f Vector3f::cross(const Vector3f& vec3f, const Vector3f& other)
{
	return Vector3f
	(
		(vec3f.y * other.z) - (vec3f.z * other.y),
		(vec3f.z * other.x) - (vec3f.x * other.z),
		(vec3f.x * other.y) - (vec3f.y * other.x)
	);
}

float Vector3f::dot(const Vector3f& vec3f, const Vector3f& other)
{
	return (vec3f.x * other.x) + (vec3f.y * other.y) + (vec3f.z * other.z);
}

Vector3f& Vector3f::rotate(const Vector3f& axis, const float angle)
{
	float halfAngleSin = sin(toRadians(angle / 2.0f));
	float halfAngleCos = cos(toRadians(angle / 2.0f));

	Quaternion rotation (
		axis.x * halfAngleSin,
		axis.y * halfAngleSin, 
		axis.z * halfAngleSin, 
		halfAngleCos
	);

	Quaternion result = rotation.mul(*this).mul(Quaternion::conjugate(rotation));

	x = rotation.x;
	y = rotation.y;
	z = rotation.z;

	return *this;
}

Vector2f Vector3f::xy()
{
	return Vector2f(x, y);
}

float Vector3f::magnitude()
{
	return (float)(sqrt((x * x) + (y * y) + (z * z)));
}

Vector3f operator+(Vector3f first, const Vector3f& second)
{
	return first.add(second);
}

Vector3f operator-(Vector3f first, const Vector3f& second)
{
	return first.sub(second);
}

Vector3f operator*(Vector3f first, const Vector3f& second)
{
	return first.mul(second);
}

Vector3f operator/(Vector3f first, const Vector3f& second)
{
	return first.div(second);
}

Vector3f& Vector3f::operator+=(const Vector3f& other)
{
	return add(other);
}

Vector3f& Vector3f::operator-=(const Vector3f& other)
{
	return sub(other);
}

Vector3f& Vector3f::operator*=(const Vector3f& other)
{
	return mul(other);
}

Vector3f& Vector3f::operator/=(const Vector3f& other)
{
	return div(other);
}

bool Vector3f::operator==(const Vector3f& other)
{
	return (x == other.x) && (y == other.y) && (z == other.z);
}

bool Vector3f::operator!=(const Vector3f& other)
{
	return (x != other.x) || (y != other.y) || (z != other.z);
}

std::ostream& operator<<(std::ostream& stream, const Vector3f& vector3f)
{
	stream << "(" << vector3f.x << ", " << vector3f.y << ", " << vector3f.z << ")";
	return stream;
}


/* ----------- Vector4f ----------- */


Vector4f::Vector4f(const float& x, const float& y, const float& z, const float& w) :
	x(x), y(y), z(z), w(w) {}

Vector4f::Vector4f(const float& fill) :
	x(fill), y(fill), z(fill), w(fill) {}

Vector4f& Vector4f::add(const float otherX, const float otherY, const float otherZ, const float otherW)
{
	x = x + otherX;
	y = y + otherY;
	z = z + otherZ;
	w = w + otherW;
	return *this;
}

Vector4f& Vector4f::add(const Vector4f& other, Vector4f& dest)
{
	dest.x = x + other.x;
	dest.y = y + other.y;
	dest.z = z + other.z;
	dest.w = w + other.w;
	return *this;
}

Vector4f& Vector4f::add(const Vector4f& other)
{
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
	w = w + other.w;
	return *this;
}

Vector4f& Vector4f::sub(const float otherX, const float otherY, const float otherZ, const float otherW)
{
	x = x - otherX;
	y = y - otherY;
	z = z - otherZ;
	w = w - otherW;
	return *this;
}

Vector4f& Vector4f::sub(const Vector4f& other, Vector4f& dest)
{
	dest.x = x - other.x;
	dest.y = y - other.y;
	dest.z = z - other.z;
	dest.w = w - other.w;
	return *this;
}

Vector4f& Vector4f::sub(const Vector4f& other)
{
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;
	w = w - other.w;
	return *this;
}

Vector4f& Vector4f::mul(const float otherX, const float otherY, const float otherZ, const float otherW)
{
	x = x * otherX;
	y = y * otherY;
	z = z * otherZ;
	w = w * otherW;
	return *this;
}

Vector4f& Vector4f::mul(const Vector4f& other, Vector4f& dest)
{
	dest.x = x * other.x;
	dest.y = y * other.y;
	dest.z = z * other.z;
	dest.w = w * other.w;
	return *this;
}

Vector4f& Vector4f::mul(const Vector4f& other)
{
	x = x * other.x;
	y = y * other.y;
	z = z * other.z;
	w = w * other.w;
	return *this;
}

Vector4f& Vector4f::div(const float otherX, const float otherY, const float otherZ, const float otherW)
{
	x = x / otherX;
	y = y / otherY;
	z = z / otherZ;
	w = w / otherW;
	return *this;
}

Vector4f& Vector4f::div(const Vector4f& other, Vector4f& dest)
{
	dest.x = x / other.x;
	dest.y = y / other.y;
	dest.z = z / other.z;
	dest.w = w / other.w;
	return *this;
}

Vector4f& Vector4f::div(const Vector4f& other)
{
	x = x / other.x;
	y = y / other.y;
	z = z / other.z;
	w = w / other.w;
	return *this;
}

Vector2f Vector4f::xy()
{
	return Vector2f(x, y);
}

Vector3f Vector4f::xyz()
{
	return Vector3f(x, y, z);
}

Vector4f operator+(Vector4f first, const Vector4f& second)
{
	return first.add(second);
}

Vector4f operator-(Vector4f first, const Vector4f& second)
{
	return first.sub(second);
}

Vector4f operator*(Vector4f first, const Vector4f& second)
{
	return first.mul(second);
}

Vector4f operator/(Vector4f first, const Vector4f& second)
{
	return first.div(second);
}

Vector4f& Vector4f::operator+=(const Vector4f& other)
{
	return add(other);
}

Vector4f& Vector4f::operator-=(const Vector4f& other)
{
	return sub(other);
}

Vector4f& Vector4f::operator*=(const Vector4f& other)
{
	return mul(other);
}

Vector4f& Vector4f::operator/=(const Vector4f& other)
{
	return div(other);
}

bool Vector4f::operator==(const Vector4f& other)
{
	return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
}

bool Vector4f::operator!=(const Vector4f& other)
{
	return (x != other.x) || (y != other.y) || (z != other.z) || (w != other.w);
}

std::ostream& operator<<(std::ostream& stream, const Vector4f& vector4f)
{
	stream << "(" << vector4f.x << ", " << vector4f.y << ", " << vector4f.z << ", " << vector4f.w << ")";
	return stream;
}