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

#include "core/integrator.h"

namespace Inept::Core {

Integrator::Integrator(const IntegratorConfiguration& configuration)
    : m_configuration {configuration}
{
}

void Integrator::render(const Scene& scene) const
{
    for (quint32 y = 0; y < m_configuration.height; ++y) {
        for (quint32 x = 0; x < m_configuration.width; ++x) {
            const double u = static_cast<double>(x) / m_configuration.width;
            const double v = static_cast<double>(y) / m_configuration.height;
            const Ray ray = scene.camera().getRay(u, v);
            const auto interaction = scene.intersect(ray);
            if (interaction.has_value()) {
                //TODO (chvatalm): Implement rendering
            }
        }
    }
}
} // namespace Inept::Core