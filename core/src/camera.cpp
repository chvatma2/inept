/*
MIT License

Copyright (c) 2024 Martin Chvatal

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "core/camera.h"
#include <cmath>

namespace Inept::Core {

Camera::Camera(const Vector3D& position, const Vector3D& lookAt, const Vector3D& up, double fov, double aspectRatio, double nearPlane) noexcept
    : m_position {position}
    , m_forward {(lookAt - position).normalize()}
    , m_right {m_forward.cross(up).normalize()}
    , m_up {m_right.cross(m_forward).normalize()}
    , m_fov {fov}
    , m_aspectRatio {aspectRatio}
    , m_nearPlane {nearPlane}
{
}

auto Camera::operator==(const Camera& other) const noexcept -> bool
{
    return m_position == other.m_position && m_forward == other.m_forward && m_right == other.m_right && m_up == other.m_up && m_fov == other.m_fov && m_aspectRatio == other.m_aspectRatio && m_nearPlane == other.m_nearPlane;
}

auto Camera::getRay(double u, double v) const noexcept -> Ray
{
    const double halfHeight = std::tan(m_fov / 2.0);
    const double halfWidth = m_aspectRatio * halfHeight;
    const Vector3D direction = m_forward + m_right * (2.0 * u - 1.0) * halfWidth + m_up * (2.0 * v - 1.0) * halfHeight;
    return Ray {m_position, direction};
}

} // namespace Inept::Core