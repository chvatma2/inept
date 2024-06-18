/* MIT License

Copyright(c) 2024 Martin Chvatal

 Permission is hereby granted,
 free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"),
 to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge,
 publish, distribute, sublicense, and / or sell copies of the Software,
 and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions :

 The above copyright notice and this permission notice shall be included in all copies
 or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS",
 WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include "core/sphere.h"
#include "core/ray.h"
#include <QtGlobal>

namespace Inept::Core {

Sphere::Sphere(const Vector3D& position, double radius, const Vector3D& color, const Vector3D& emission)
    : Primitive {color, emission}
    , m_position {position}
    , m_radius {radius}
{
}

auto Sphere::intersect(const Ray& ray) const noexcept -> std::optional<SurfaceInteraction>
{
    Q_UNUSED(ray);
    // Calculate the direction from the ray origin to the sphere center
    const Vector3D oc = ray.origin() - m_position;

    // Calculate the coefficients of the quadratic equation
    const double a = ray.direction().dot(ray.direction());
    const double b = 2.0 * oc.dot(ray.direction());
    const double c = oc.dot(oc) - m_radius * m_radius;

    // Calculate the discriminant
    const double discriminant = b * b - 4 * a * c;

    // Check if the ray intersects with the sphere
    if (discriminant > 0) {
        // Calculate the two solutions of the quadratic equation
        const double t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
        const double t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);

        // Check if the solutions are within the valid range
        if (t1 > 0 || t2 > 0) {
            // Choose the closest intersection point
            const double t = (t1 > 0) ? t1 : t2;

            // Calculate the intersection point
            const Vector3D intersectionPoint = ray.origin() + ray.direction() * t;

            // Calculate the surface normal at the intersection point
            const Vector3D surfaceNormal = (intersectionPoint - m_position).normalized();

            // Create a SurfaceInteraction object with the intersection information
            return SurfaceInteraction(*this, intersectionPoint, surfaceNormal);
        }
    }

    // No intersection with the sphere
    return std::nullopt;
    return {};
}
} // namespace Inept::Core
