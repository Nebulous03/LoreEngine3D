#pragma once

struct Vector2f {

	float x = 0;
	float y = 0;

	Vector2f(float, float);
	Vector2f add(Vector2f, Vector2f&);
	Vector2f add(Vector2f);
	Vector2f sub(Vector2f, Vector2f&);
	Vector2f sub(Vector2f);
};

struct Vector3f {

	float x = 0;
	float y = 0;
	float z = 0;

	Vector3f(float, float, float);
	Vector3f add(Vector3f, Vector3f&);
	Vector3f add(Vector3f);
	Vector3f sub(Vector3f, Vector3f&);
	Vector3f sub(Vector3f);
};

struct Vector4f {

	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;

	Vector4f(float, float, float, float);
	Vector4f add(Vector4f, Vector4f&);
	Vector4f add(Vector4f);
	Vector4f sub(Vector4f, Vector4f&);
	Vector4f sub(Vector4f);
};