/* MIT License

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
SOFTWARE. */

#ifndef SURFACEINTERACTION_H
#define SURFACEINTERACTION_H

#include "core/vector3d.h"

namespace Inept::Core {
class Primitive;
class SurfaceInteraction
{
public:
    SurfaceInteraction(const Primitive& primitive, const Vector3D& point, const Vector3D& normal) noexcept
        : m_primitive {primitive}
        , m_point {point}
        , m_normal {normal} {};
    [[nodiscard]] auto primitive() const noexcept -> const Primitive&;
    [[nodiscard]] auto point() const noexcept -> Vector3D;
    [[nodiscard]] auto normal() const noexcept -> Vector3D;

private:
    const Primitive& m_primitive;
    Vector3D m_point;
    Vector3D m_normal;
};

} // namespace Inept::Core

#endif // SURFACEINTERACTION_H
