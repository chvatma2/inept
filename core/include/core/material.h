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
#ifndef CORE_MATERIAL_H
#define CORE_MATERIAL_H

#include "core/vector3d.h"

namespace Inept::Core {

enum class MaterialType {
    Diffuse,
    Speculative,
    Refractive
};

/// @brief Material class represents a material with color, emission and type.
/// @details The material can be of type Diffuse, Speculative or Refractive.
class Material {
private:
    Vector3D m_color;
    Vector3D m_emission;
    MaterialType m_type{MaterialType::Diffuse};

public:
    Material(const Vector3D& color, const Vector3D& emission, MaterialType type = MaterialType::Diffuse)
        : m_color(color), m_emission(emission), m_type(type) {}

    [[nodiscard]] auto operator==(const Material& other) const noexcept -> bool;

    [[nodiscard]] auto color() const noexcept -> Vector3D { return m_color; }
    [[nodiscard]] auto emission() const noexcept -> Vector3D { return m_emission; }
    [[nodiscard]] auto type() const noexcept -> MaterialType { return m_type; }
};

} // namespace Inept::Core

#endif // CORE_MATERIAL_H
