#include "core/triangle.h"
#include <cmath>

namespace Inept::Core {

Triangle::Triangle(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3)
    : m_vertex1(v1), m_vertex2(v2), m_vertex3(v3)
{
}

auto Triangle::getVertex1() const -> const Vector3D&
{
    return m_vertex1;
}

auto Triangle::getVertex2() const -> const Vector3D&
{
    return m_vertex2;
}

auto Triangle::getVertex3() const -> const Vector3D&
{
    return m_vertex3;
}

void Triangle::setVertex1(const Vector3D& v1)
{
    m_vertex1 = v1;
}

void Triangle::setVertex2(const Vector3D& v2)
{
    m_vertex2 = v2;
}

void Triangle::setVertex3(const Vector3D& v3)
{
    m_vertex3 = v3;
}

auto Triangle::calculateArea() const -> double
{
    // Heron's formula
    auto a = m_vertex1.distanceTo(m_vertex2);
    auto b = m_vertex2.distanceTo(m_vertex3);
    auto c = m_vertex3.distanceTo(m_vertex1);
    auto s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

auto Triangle::calculatePerimeter() const -> double
{
    return m_vertex1.distanceTo(m_vertex2) + m_vertex2.distanceTo(m_vertex3) + m_vertex3.distanceTo(m_vertex1);
}


} // namespace Inept::Core