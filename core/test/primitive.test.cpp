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

#include "core/primitive.h"
#include "core/ray.h"
#include "core/surfaceinteraction.h"
#include <optional>
#include <QTest>

class PrimitiveImpl : public Inept::Core::Primitive
{
public:
    explicit PrimitiveImpl(const Inept::Core::Material& material)
        : Primitive(material) {};
    [[nodiscard]] std::optional<Inept::Core::SurfaceInteraction> intersect(const Inept::Core::Ray& ray) const noexcept override
    {
        Q_UNUSED(ray)
        return std::nullopt;
    };
};

class PrimitiveTest : public QObject
{
    Q_OBJECT
private slots:
    static void constructorTest()
    {
        const Inept::Core::Vector3D color {0.7, 0.7, 0.6};
        const Inept::Core::Vector3D emission {0.1, 0.0, 0.0};
        const Inept::Core::Material material {color, emission, Inept::Core::MaterialType::Diffuse};
        const PrimitiveImpl primitive {material};
        QCOMPARE(material, primitive.material());
    }
    static void operatorEqualsTest()
    {
        const Inept::Core::Vector3D color1 {0.7, 0.7, 0.6};
        const Inept::Core::Vector3D emission1 {0.1, 0.0, 0.0};
        const Inept::Core::Material material1 {color1, emission1, Inept::Core::MaterialType::Diffuse};
        const PrimitiveImpl primitive1 {material1};

        const Inept::Core::Vector3D color2 {0.5, 0.5, 0.5};
        const Inept::Core::Vector3D emission2 {0.0, 0.0, 0.0};
        const Inept::Core::Material material2 {color2, emission2, Inept::Core::MaterialType::Diffuse};
        const PrimitiveImpl primitive2 {material2};

        QVERIFY(primitive1 == primitive1); // Same object
        QVERIFY(!(primitive1 == primitive2)); // Different color and emission
    }
    static void intersectTest()
    {
        const Inept::Core::Vector3D origin {0.0, 0.0, 0.0};
        const Inept::Core::Vector3D direction {0.0, 0.0, 1.0};
        const Inept::Core::Vector3D color {0.7, 0.7, 0.6};
        const Inept::Core::Vector3D emission {0.1, 0.0, 0.0};
        const Inept::Core::Material material {color, emission, Inept::Core::MaterialType::Diffuse};
        const Inept::Core::Ray ray {origin, direction};
        const PrimitiveImpl primitive {material};
        const auto interaction = primitive.intersect(ray);
        QVERIFY(!interaction.has_value());
    }
};
QTEST_MAIN(PrimitiveTest)
#include "primitive.test.moc"