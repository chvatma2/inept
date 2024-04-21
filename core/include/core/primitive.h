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

#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "core/ray.h"
#include "core/surfaceinteraction.h"
#include <optional>
#include <QVector3D>

namespace Inept::Core {

class Primitive
{
public:
    Primitive(QVector3D color, QVector3D emission)
        : m_color {color}
        , m_emission {emission} {};
    virtual ~Primitive() = default;
    Primitive(const Primitive&) = delete;
    Primitive& operator=(const Primitive&) = delete;
    Primitive(Primitive&&) = delete;
    Primitive& operator=(Primitive&&) = delete;
    [[nodiscard]] virtual std::optional<SurfaceInteraction> intersect(const Ray& ray) const = 0;
    [[nodiscard]] QVector3D color() const;
    [[nodiscard]] QVector3D emission() const;

private:
    QVector3D m_color;
    QVector3D m_emission;
};

} // namespace Inept::Core
#endif // PRIMITIVE_H
