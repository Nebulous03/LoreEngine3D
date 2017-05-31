#include "Vector.h"

/* ----------- Vector2f ----------- */

Vector2f::Vector2f(float x, float y) :
	x(x), y(y) {}

Vector2f Vector2f::add(Vector2f vec2, Vector2f& dest)
{
	dest.x = x + vec2.x;
	dest.y = y + vec2.y;
	return *this;	// Return dest?
}

Vector2f Vector2f::add(Vector2f vec2)
{
	x = x + vec2.x;
	y = y + vec2.y;
	return *this;
}

Vector2f Vector2f::sub(Vector2f vec2, Vector2f& dest)
{
	dest.x = x - vec2.x;
	dest.y = y - vec2.y;
	return *this;
}

Vector2f Vector2f::sub(Vector2f vec2)
{
	x = x - vec2.x;
	y = y - vec2.y;
	return *this;
}

/* ----------- Vector3f ----------- */

Vector3f::Vector3f(float x, float y, float z) :
	x(x), y(y), z(z) {}

Vector3f Vector3f::add(Vector3f vec3, Vector3f& dest)
{
	dest.x = x + vec3.x;
	dest.y = y + vec3.y;
	dest.z = z + vec3.z;
	return *this;
}

Vector3f Vector3f::add(Vector3f vec3)
{
	x = x + vec3.x;
	y = y + vec3.y;
	z = z + vec3.z;
	return *this;
}

Vector3f Vector3f::sub(Vector3f vec3, Vector3f& dest)
{
	dest.x = x - vec3.x;
	dest.y = y - vec3.y;
	dest.z = z - vec3.z;
	return *this;
}

Vector3f Vector3f::sub(Vector3f vec3)
{
	x = x - vec3.x;
	y = y - vec3.y;
	z = z - vec3.z;
	return *this;
}

/* ----------- Vector4f ----------- */

Vector4f::Vector4f(float x, float y, float z, float w) :
	x(x), y(y), z(z), w(w) {}

Vector4f Vector4f::add(Vector4f vec4, Vector4f& dest)
{
	dest.x = x + vec4.x;
	dest.y = y + vec4.y;
	dest.z = z + vec4.z;
	dest.w = w + vec4.w;
	return *this;
}

Vector4f Vector4f::add(Vector4f vec4)
{
	x = x + vec4.x;
	y = y + vec4.y;
	z = z + vec4.z;
	w = w + vec4.w;
	return *this;
}

Vector4f Vector4f::sub(Vector4f vec4, Vector4f& dest)
{
	dest.x = x - vec4.x;
	dest.y = y - vec4.y;
	dest.z = z - vec4.z;
	dest.w = w - vec4.w;
	return *this;
}

Vector4f Vector4f::sub(Vector4f vec4)
{
	x = x - vec4.x;
	y = y - vec4.y;
	z = z - vec4.z;
	w = w - vec4.w;
	return *this;
}
