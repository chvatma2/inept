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

#ifndef SCENE_H
#define SCENE_H

#include "core/surfaceinteraction.h"
#include "core/vector3d.h"
#include <memory>
#include <optional>
#include <vector>

namespace Inept::Core {
class Primitive;
class Ray;
class Scene
{
public:
    Scene(std::vector<std::unique_ptr<Primitive>>&& primitives, const Vector3D& camera);
    auto intersect(const Ray& ray) const -> std::optional<SurfaceInteraction>;
    auto camera() const -> Vector3D;

private:
    std::vector<std::unique_ptr<Primitive>> m_primitives;
    Vector3D m_camera;
};;

} // namespace Inept::Core

#endif // SCENE_H
