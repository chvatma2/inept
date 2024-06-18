#include "core/vector3d.h"
#include <stdexcept>
#include <cmath>


namespace Inept::Core {

auto Vector3D::operator+(const Vector3D& other) const noexcept -> Vector3D
{
    return Vector3D{m_x + other.m_x, m_y + other.m_y, m_z + other.m_z};
}

auto Vector3D::operator-(const Vector3D& other) const noexcept -> Vector3D
{
    return Vector3D{m_x - other.m_x, m_y - other.m_y, m_z - other.m_z};
}

auto Vector3D::operator*(double scalar) const noexcept -> Vector3D
{
    return Vector3D{m_x * scalar, m_y * scalar, m_z * scalar};
}

auto Vector3D::operator/(double scalar) const -> Vector3D
{
    if (scalar == 0.0 || std::isnan(scalar)) {
        throw std::invalid_argument("Division by zero or NaN");
    }
    return Vector3D{m_x / scalar, m_y / scalar, m_z / scalar};
}

auto Vector3D::operator==(const Vector3D& other) const noexcept -> bool
{
    return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
}

auto Vector3D::length() const noexcept -> double
{
    return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}
} // namespace Inept::Core