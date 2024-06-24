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

#ifndef CORE_TRIANGLE_H
#define CORE_TRIANGLE_H

#include "core/vector3d.h"

namespace Inept::Core
{
    class Triangle
    {
    public:
        Triangle(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3);

        // Getter methods
        auto getVertex1() const -> const Vector3D&;
        auto getVertex2() const -> const Vector3D&;
        auto getVertex3() const -> const Vector3D&;

        // Setter methods
        void setVertex1(const Vector3D& v1);
        void setVertex2(const Vector3D& v2);
        void setVertex3(const Vector3D& v3);

        // Other methods
        auto calculateArea() const -> double;
        auto calculatePerimeter() const -> double;

    private:
        Vector3D m_vertex1;
        Vector3D m_vertex2;
        Vector3D m_vertex3;
    };;
} // namespace Inept::Core

#endif // CORE_TRIANGLE_H