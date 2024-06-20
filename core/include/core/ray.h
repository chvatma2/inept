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

#ifndef RAY_H
#define RAY_H

#include "core/vector3d.h"

namespace Inept::Core {
class Ray
{
public:
    Ray(const Vector3D& origin, const Vector3D& direction)
        : m_origin(origin)
        , m_direction(direction) {};
    /// @brief  Returns the origin of the ray.
    /// @return The origin of the ray.
    [[nodiscard]] auto origin() const -> Vector3D;
    /// @brief  Returns the direction of the ray.
    /// @return The direction of the ray.
    [[nodiscard]] auto direction() const -> Vector3D;
    /// @brief  Compares two rays for equality.
    /// @param  other The ray to compare against.
    /// @return True if the rays are equal, false otherwise.
    [[nodiscard]] auto operator==(const Ray& other) const -> bool;
    

private:
    Vector3D m_origin;
    Vector3D m_direction;
};
} // namespace Inept::Core
#endif // RAY_H
