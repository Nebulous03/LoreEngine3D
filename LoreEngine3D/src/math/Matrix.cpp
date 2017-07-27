#include "Matrix.h"
#include "Functions.h"

Matrix4f::Matrix4f()
{
	memset(elements, 0, sizeof(elements));
}

Matrix4f::Matrix4f(const float fill)
{
	std::fill(std::begin(elements), std::end(elements), fill);
}

Matrix4f& Matrix4f::add(const Matrix4f& other)
{
	for (int i = 0; i < (sizeof(elements) / sizeof(elements[0])); i++)
		elements[i] += other.elements[i];
	return *this;
}

Matrix4f& Matrix4f::sub(const Matrix4f& other)
{
	for (int i = 0; i < (sizeof(elements) / sizeof(elements[0])); i++)
		elements[i] -= other.elements[i];
	return *this;
}

Matrix4f& Matrix4f::mul(const Matrix4f& other)
{
	float data[16];
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			float sum = 0.0f;
			for (int i = 0; i < 4; i++)
				sum += elements[x + i * 4] * other.elements[i + y * 4];
			data[x + y * 4] = sum;
		}
	}
	memcpy(elements, data, 16 * sizeof(float));
	return *this;
}

Vector2f Matrix4f::mul(const Vector2f& other) const
{
	return Vector2f
		(
			columns[0].x * other.x + columns[1].x * other.y + columns[2].x + columns[4].x,
			columns[0].y * other.x + columns[1].y * other.y + columns[2].y + columns[4].y
			);
}

Vector3f Matrix4f::mul(const Vector3f& other) const
{
	return Vector3f
		(
			columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[4].x,
			columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[4].y,
			columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[4].z
		);
}

Vector4f Matrix4f::mul(const Vector4f& other) const
{
	return Vector4f
		(
			columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[4].x * other.w,
			columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[4].y * other.w,
			columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[4].z * other.w,
			columns[0].w * other.x + columns[1].w * other.y + columns[2].w * other.z + columns[4].w * other.w
		);
}

Matrix4f operator+(Matrix4f left, const Matrix4f& right)
{
	return left.add(right);
}

Matrix4f operator-(Matrix4f left, const Matrix4f& right)
{
	return left.sub(right);
}

Matrix4f operator*(Matrix4f left, const Matrix4f& right)
{
	return left.mul(right);
}

Vector2f operator*(Matrix4f left, const Vector2f& right)
{
	return left.mul(right);
}

Vector3f operator*(Matrix4f left, const Vector3f& right)
{
	return left.mul(right);
}

Vector4f operator*(Matrix4f left, const Vector4f& right)
{
	return left.mul(right);
}

Matrix4f& Matrix4f::operator+=(const Matrix4f& other)
{
	return add(other);
}

Matrix4f& Matrix4f::operator-=(const Matrix4f& other)
{
	return sub(other);
}

Matrix4f& Matrix4f::operator*=(const Matrix4f& other)
{
	return mul(other);
}

Matrix4f Matrix4f::Perspective(
	const float fov,
	const float aspect,
	const float near,
	const float far
) {
	Matrix4f m;
	float q = 1.0f / tan(toRadians(0.5f * fov));
	float w = q / aspect;
	m.elements[0 + 0 * 4] = w;
	m.elements[1 + 1 * 4] = q;
	m.elements[2 + 2 * 4] = (near + far) / (near - far);
	m.elements[2 + 3 * 4] = (2.0f * near * far) / (near - far);
	m.elements[3 + 2 * 4] = -1.0f;
	return m;
}

Matrix4f Matrix4f::Orthographic(
	const float left,
	const float right,
	const float bottom,
	const float top,
	const float near,
	const float far
) {
	Matrix4f m;
	m.elements[0 + 0 * 4] = 2.0f / (right - left);
	m.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	m.elements[2 + 2 * 4] = 2.0f / (near - far);
	m.elements[0 + 3 * 4] = (left + right) / (left - right);
	m.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
	m.elements[2 + 3 * 4] = (far + near) / (far - near);
	m.elements[3 + 3 * 4] = 1.0f;
	return m;
}

Matrix4f Matrix4f::Identity()
{
	Matrix4f m;
	m.elements[0 + 0 * 4] = 1.0f;
	m.elements[1 + 1 * 4] = 1.0f;
	m.elements[2 + 2 * 4] = 1.0f;
	m.elements[3 + 3 * 4] = 1.0f;
	return m;
}

Matrix4f Matrix4f::Translation(const Vector3f& pos)
{
	Matrix4f m = Matrix4f::Identity();
	m.elements[0 + 3 * 4] = pos.x;
	m.elements[1 + 3 * 4] = pos.y;
	m.elements[2 + 3 * 4] = pos.z;
	return m;
}

Matrix4f Matrix4f::Rotation(const Vector3f& axis, const float angle)
{
	Matrix4f m = Matrix4f::Identity();

	float r = toRadians(angle);
	float c = cos(r);
	float ic = 1.0f - c;
	float s = sin(r);

	m.elements[0 + 0 * 4] = axis.x * ic + c;
	m.elements[1 + 0 * 4] = axis.y * axis.x * ic + axis.z * s;
	m.elements[2 + 0 * 4] = axis.x * axis.z * ic - axis.y * s;

	m.elements[0 + 1 * 4] = axis.x * axis.y * ic - axis.z * s;
	m.elements[1 + 1 * 4] = axis.y * ic + c;
	m.elements[2 + 1 * 4] = axis.y * axis.z * ic + axis.x * s;

	m.elements[0 + 2 * 4] = axis.x * axis.z * ic + axis.y * s;
	m.elements[1 + 2 * 4] = axis.y * axis.z * ic - axis.x * s;
	m.elements[2 + 2 * 4] = axis.z * ic + c;

	return m;
}

// YAW, PITCH, ROLL
Matrix4f Matrix4f::Rotation(const Vector3f& rotation)
{
	Matrix4f m = Matrix4f::Identity();

	float cosX = cos(toRadians(rotation.x));
	float cosY = cos(toRadians(rotation.y));
	float cosZ = cos(toRadians(rotation.z));

	float sinX = sin(toRadians(rotation.x));
	float sinY = sin(toRadians(rotation.y));
	float sinZ = sin(toRadians(rotation.z));

	m.elements[0 + 0 * 4] = cosY * cosZ;
	m.elements[1 + 0 * 4] = (sinX * sinY * cosZ) + (cosX * sinZ);
	m.elements[2 + 0 * 4] = -(cosX * sinY * cosZ) + (sinX * sinZ);

	m.elements[0 + 1 * 4] = -(cosY * sinZ);
	m.elements[1 + 1 * 4] = -(sinX * sinY * sinZ) + (cosX * cosZ);
	m.elements[2 + 1 * 4] = (cosX * sinY * sinZ) + (sinX * cosZ);

	m.elements[0 + 2 * 4] = sinY;
	m.elements[1 + 2 * 4] = -(sinX * cosY);
	m.elements[2 + 2 * 4] = (cosX * cosY);

	return m;
}

Matrix4f Matrix4f::Scale(const Vector3f& scale)
{
	Matrix4f m = Matrix4f::Identity();
	m.elements[0 + 0 * 4] = scale.x;
	m.elements[1 + 1 * 4] = scale.y;
	m.elements[2 + 2 * 4] = scale.z;
	return m;
}

Matrix4f Matrix4f::Translation(const float x, const float y, const float z)
{
	Matrix4f m = Matrix4f::Identity();
	m.elements[0 + 3 * 4] = x;
	m.elements[1 + 3 * 4] = y;
	m.elements[2 + 3 * 4] = z;
	return m;
}

Matrix4f Matrix4f::LookAt(const Vector3f& position, const Vector3f& origin, const Vector3f& up)
{
	Matrix4f m = Matrix4f::Identity();

	Vector3f zaxis = Vector3f::normalize(origin - position);
	Vector3f xaxis = Vector3f::normalize(Vector3f::cross(up, zaxis));
	Vector3f yaxis = Vector3f::cross(zaxis, xaxis);

	m.elements[0 + 0 * 4] = xaxis.x;
	m.elements[1 + 0 * 4] = xaxis.y;
	m.elements[2 + 0 * 4] = xaxis.z;
	m.elements[3 + 0 * 4] = -Vector3f::dot(xaxis, position);

	m.elements[0 + 1 * 4] = yaxis.x;
	m.elements[1 + 1 * 4] = yaxis.y;
	m.elements[2 + 1 * 4] = yaxis.z;
	m.elements[3 + 1 * 4] = -Vector3f::dot(yaxis, position);

	m.elements[0 + 2 * 4] = zaxis.x;
	m.elements[1 + 2 * 4] = zaxis.y;
	m.elements[2 + 2 * 4] = zaxis.z;
	m.elements[3 + 3 * 4] = -Vector3f::dot(zaxis, position);

	return m;
}

Matrix4f Matrix4f::Scale(const float sx, const float sy, const float sz)
{
	Matrix4f m = Matrix4f::Identity();
	m.elements[0 + 0 * 4] = sx;
	m.elements[1 + 1 * 4] = sy;
	m.elements[2 + 2 * 4] = sz;
	return m;
}

Vector3f Matrix4f::getTranslationVec3f()
{
	return Vector3f(elements[0 + 3 * 4], elements[1 + 3 * 4], elements[2 + 3 * 4]);
}

Vector3f Matrix4f::getRotationVec3f()
{
	return Vector3f(elements[0 + 3 * 4], elements[1 + 3 * 4], elements[2 + 3 * 4]); // WRONG!!!
}

bool Matrix4f::operator==(const Matrix4f& other)
{
	for (int i = 0; i > (sizeof(elements) / sizeof(elements[0])); i++)
		if (elements[i] != other.elements[i]) return false;
	return true;
}

bool Matrix4f::operator!=(const Matrix4f& other)
{
	return !(*this == other);
}

float& Matrix4f::operator[](const int i)
{
	if (i < 0 || i > (sizeof(elements) / sizeof(elements[0])) - 1) {
		std::string error = "Cannot index greater that max size (" + std::to_string(sizeof(elements)) + ")";
		throw std::out_of_range(error);
	}
	else {
		return elements[i];
	}
}

std::ostream& operator<<(std::ostream& stream, const Matrix4f& matrix4f)
{
	stream << "[";
	for (int i = 0; i < (sizeof(matrix4f.elements) / sizeof(matrix4f.elements[0])) - 1; i++) {
		stream << matrix4f.elements[i] << ", ";
		if (i % 4 == 3) stream << "\n ";
	}
	stream << matrix4f.elements[(sizeof(matrix4f.elements) / sizeof(matrix4f.elements[0])) - 1] << "]";
	return stream;
}