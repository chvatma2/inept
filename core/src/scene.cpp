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

#include "core/scene.h"
#include "core/primitive.h"
#include "core/ray.h"
#include <limits>

namespace Inept::Core {

Scene::Scene(std::vector<std::unique_ptr<Primitive>>&& primitives, const Camera& camera)
    : m_primitives {std::move(primitives)}
    , m_camera {camera}
{
}

std::optional<SurfaceInteraction> Scene::intersect(const Ray& ray) const
{
    std::optional<SurfaceInteraction> result;
    double closestDistance {std::numeric_limits<double>::max()};
    for (auto& primitive : m_primitives) {
        auto interaction = primitive->intersect(ray);
        if (!interaction.has_value()) {
            continue;
        }
        const double distance = (ray.origin() - interaction->point()).length();
        if (distance < closestDistance) {
            closestDistance = distance;
            result.emplace(interaction.value());
        }
    }
    return result;
}

auto Scene::camera() const -> const Camera&
{
    return m_camera;
}

} // namespace Inept::Core
