#pragma once
#include "../../Includes.hpp"
#include <vector>
#include <string>
namespace SDK
{
	struct Vector2 final {
		float x{ 0.0f }, y{ 0.0f };

		Vector2 operator+(const Vector2& rhs) const {
			return { x + rhs.x, y + rhs.y };
		}
		Vector2 operator-(const Vector2& rhs) const {
			return { x - rhs.x, y - rhs.y };
		}
		Vector2 operator*(float scalar) const {
			return { x * scalar, y * scalar };
		}
		Vector2& operator+=(const Vector2& rhs) {
			x += rhs.x;
			y += rhs.y;
			return *this;
		}
		Vector2& operator-=(const Vector2& rhs) {
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		
		float distance(const Vector2& other) const {
			float dx = x - other.x;
			float dy = y - other.y;
			return std::sqrt(dx * dx + dy * dy);
		}
	};
	struct Vector3 final {

		float x{ 0.0f }, y{ 0.0f }, z{ 0.0f };

		Vector3 operator+(const Vector3& rhs) const {
			return { x + rhs.x, y + rhs.y, z + rhs.z };
		}

		Vector3 operator-(const Vector3& rhs) const {
			return { x - rhs.x, y - rhs.y, z - rhs.z };
		}

		Vector3 operator*(float scalar) const {
			return { x * scalar, y * scalar, z * scalar };
		}

		Vector3 operator*(const Vector3& other) const {
			return { x * other.x, y * other.y, z * other.z };
		}

		Vector3 operator/(const Vector3& rhs) const {
			return { x / rhs.x, y / rhs.y, z / rhs.z };
		}

		Vector3& operator+=(const Vector3& rhs) {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		Vector3& operator-=(const Vector3& rhs) {
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}


		bool operator== (const Vector3& other) const {
			return (this->x == other.x && this->y == other.y && this->z == other.z);
		}


		Vector3 operator/(float scalar) const {
			return { x / scalar, y / scalar, z / scalar };
		}
		Vector3 operator-() const {
			return { -x, -y, -z };
		}

		const float magnitude() const
		{
			return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
		}



		const float distance(Vector3 vector) const
		{
			return (*this - vector).magnitude();
		}

		const Vector3 normalize() const
		{
			Vector3 ret;
			float mag = this->magnitude();
			ret.x = x / mag;
			ret.y = y / mag;
			ret.z = z / mag;
			return ret;
		}

		auto cross(Vector3 vec) const
		{
			Vector3 ret;
			ret.x = y * vec.z - z * vec.y;
			ret.y = -(x * vec.z - z * vec.x);
			ret.z = x * vec.y - y * vec.x;
			return ret;
		}

	};
	struct Matrix4 final { float data[16]; };
	struct Matrix3 final { float data[9]; };
	struct Vector4 final { float x, y, z, w; };

	// Roblox memory layout: 3x4 row-major matrix (rotation rows + translation column)
	struct CFrame final {
		float data[12]{};

		CFrame() {
			data[0] = 1.0f; data[4] = 1.0f; data[8] = 1.0f; // identity rotation
		}
		CFrame(const Vector3& pos) : CFrame() {
			data[3] = pos.x; data[7] = pos.y; data[11] = pos.z;
		}
		CFrame(const Matrix3& rot, const Vector3& pos) {
			for (int i = 0; i < 9; ++i) data[i] = rot.data[i];
			data[9] = pos.x; data[10] = pos.y; data[11] = pos.z;
		}

		Vector3 position() const {
			return { data[3], data[7], data[11] };
		}
		Vector3 rightVector() const {
			return { data[0], data[1], data[2] };
		}
		Vector3 upVector() const {
			return { data[4], data[5], data[6] };
		}
		Vector3 lookVector() const {
			return { -data[8], -data[9], -data[10] }; // Z column is backwards
		}

		CFrame operator*(const CFrame& rhs) const {
			CFrame out{};
			for (int col = 0; col < 3; ++col) {
				for (int i = 0; i < 3; ++i)
					out.data[col * 4 + i] =
						data[i] * rhs.data[col * 4] +
						data[4 + i] * rhs.data[col * 4 + 1] +
						data[8 + i] * rhs.data[col * 4 + 2];
				out.data[col * 4 + 3] =
					data[3] * rhs.data[col * 4] +
					data[7] * rhs.data[col * 4 + 1] +
					data[11] * rhs.data[col * 4 + 2] +
					rhs.data[col * 4 + 3];
			}
			return out;
		}

		Vector3 operator*(const Vector3& point) const {
			return {
				data[0] * point.x + data[1] * point.y + data[2] * point.z + data[3],
				data[4] * point.x + data[5] * point.y + data[6] * point.z + data[7],
				data[8] * point.x + data[9] * point.y + data[10] * point.z + data[11]
			};
		}
	};
}