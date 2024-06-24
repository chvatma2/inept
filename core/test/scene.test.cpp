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

#include "core/scene.h"
#include "core/primitive.h"
#include "core/sphere.h"
#include "core/camera.h"
#include <memory>
#include <vector>
#include <optional>
#include <limits>
#include <QTest>

class SceneTest : public QObject
{
    Q_OBJECT
private slots:
    static void intersectTest();
    static void cameraTest();
};

void SceneTest::intersectTest()
{
    const Inept::Core::Vector3D origin {0.0, 0.0, 0.0};
    const Inept::Core::Vector3D direction {0.0, 0.0, 1.0};
    const Inept::Core::Ray ray {origin, direction};
    const Inept::Core::Camera camera{ Inept::Core::Vector3D {0.0, 0.0, 0.0}, Inept::Core::Vector3D {0.0, 0.0, 1.0}, Inept::Core::Vector3D {0.0, 1.0, 0.0}, 90.0, 1.0, 1.0};
    std::vector<std::unique_ptr<Inept::Core::Primitive>> primitives;
    const Inept::Core::Material material {Inept::Core::Vector3D {1.0, 1.0, 1.0}, Inept::Core::Vector3D {0.0, 0.0, 0.0}, Inept::Core::MaterialType::Diffuse};
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D {0.0, 0.0, 5.0}, 1.0, material));
    auto sphere = primitives[0].get();
    const Inept::Core::Scene scene { std::move(primitives), camera};
    const auto interaction = scene.intersect(ray);
    QVERIFY(interaction.has_value());
    if(interaction.has_value())
    {
        QCOMPARE(interaction.value().point(), (Inept::Core::Vector3D {0.0, 0.0, 4.0}));
        QCOMPARE(interaction.value().normal(), (Inept::Core::Vector3D {0.0, 0.0, -1.0}));
        QCOMPARE(interaction.value().primitive(), *sphere);
    }

    //TODO (chvatalm) analyze the following edge cases
    // Edge case: Ray origin inside the sphere
    // const Inept::Core::Vector3D originInside {0.0, 0.0, 4.0};
    // const Inept::Core::Ray rayInside {originInside, direction};
    // const auto interactionInside = scene.intersect(rayInside);
    // QVERIFY(interactionInside.has_value());
    // QCOMPARE(interactionInside.value().point(), (Inept::Core::Vector3D {0.0, 0.0, 3.0}));
    // QCOMPARE(interactionInside.value().normal(), (Inept::Core::Vector3D {0.0, 0.0, -1.0}));
    // QCOMPARE(interactionInside.value().primitive(), *sphere);

    // Edge case: Ray direction parallel to the sphere
    const Inept::Core::Vector3D directionParallel {1.0, 0.0, 0.0};
    const Inept::Core::Ray rayParallel {origin, directionParallel};
    const auto interactionParallel = scene.intersect(rayParallel);
    QVERIFY(!interactionParallel.has_value());

    // Edge case: Ray misses the sphere
    const Inept::Core::Vector3D directionMiss {0.0, 1.0, 0.0};
    const Inept::Core::Ray rayMiss {origin, directionMiss};
    const auto interactionMiss = scene.intersect(rayMiss);
    QVERIFY(!interactionMiss.has_value());
}

void SceneTest::cameraTest()
{    
    const Inept::Core::Camera camera{ Inept::Core::Vector3D {0.0, 0.0, 0.0}, Inept::Core::Vector3D {0.0, 0.0, 1.0}, Inept::Core::Vector3D {0.0, 1.0, 0.0}, 90.0, 1.0, 1.0};
    const Inept::Core::Scene scene {std::vector<std::unique_ptr<Inept::Core::Primitive>> {}, camera};
    QCOMPARE(scene.camera(), camera);
}

QTEST_MAIN(SceneTest)
#include "scene.test.moc"
