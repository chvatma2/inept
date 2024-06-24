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

auto Vector3D::dot(const Vector3D& other) const noexcept -> double
{
    return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

auto Vector3D::normalize() const noexcept -> Vector3D
{
    const double len = length();
    if (len == 0.0) {
        return Vector3D{0.0, 0.0, 0.0};
    }
    return Vector3D{m_x / len, m_y / len, m_z / len};
}

auto Vector3D::cross(const Vector3D& other) const noexcept -> Vector3D
{
    return Vector3D{m_y * other.m_z - m_z * other.m_y, m_z * other.m_x - m_x * other.m_z, m_x * other.m_y - m_y * other.m_x};   
}

auto Vector3D::distanceTo(const Vector3D& other) const noexcept -> double
{
    return std::sqrt(std::pow(m_x - other.m_x, 2) + std::pow(m_y - other.m_y, 2) + std::pow(m_z - other.m_z, 2));
}

} // namespace Inept::Core