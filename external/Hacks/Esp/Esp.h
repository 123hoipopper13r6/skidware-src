#pragma once
class ImDrawList;
namespace Hacks::Esp
{
	struct HitMarker3D final {

		float x{ 0.0f }, y{ 0.0f }, z{ 0.0f };

		HitMarker3D operator+(const HitMarker3D& rhs) const {
			return { x + rhs.x, y + rhs.y, z + rhs.z };
		}

		HitMarker3D operator-(const HitMarker3D& rhs) const {
			return { x - rhs.x, y - rhs.y, z - rhs.z };
		}

		HitMarker3D operator*(float scalar) const {
			return { x * scalar, y * scalar, z * scalar };
		}

		HitMarker3D operator*(const HitMarker3D& other) const {
			return { x * other.x, y * other.y, z * other.z };
		}

		HitMarker3D operator/(const HitMarker3D& rhs) const {
			return { x / rhs.x, y / rhs.y, z / rhs.z };
		}

		HitMarker3D& operator+=(const HitMarker3D& rhs) {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		HitMarker3D& operator-=(const HitMarker3D& rhs) {
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}


		bool operator== (const HitMarker3D& other) const {
			return (this->x == other.x && this->y == other.y && this->z == other.z);
		}


		HitMarker3D operator/(float scalar) const {
			return { x / scalar, y / scalar, z / scalar };
		}
		HitMarker3D operator-() const {
			return { -x, -y, -z };
		}







	};
	void InsertHitMarker(HitMarker3D Start, HitMarker3D End);
	void Render();
	void RenderRaycastPreview(ImDrawList* Draw);
}