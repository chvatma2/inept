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

#include "core/sphere.h"
#include <QTest>

class SphereTest : public QObject
{
    Q_OBJECT
private slots:
    static void intersectTest();
    static void noIntersectTest();
};

// Test case for ray intersecting with the sphere
void SphereTest::intersectTest()
{
    // Create a sphere
    const Inept::Core::Vector3D position {0.0, 0.0, 0.0};
    const double radius {1.0};
    const Inept::Core::Vector3D color {1.0, 1.0, 1.0};
    const Inept::Core::Vector3D emission {0.0, 0.0, 0.0};
    const Inept::Core::Material material {color, emission};
    const Inept::Core::Sphere sphere(position, radius, material);

    // Create a ray that intersects with the sphere
    const Inept::Core::Vector3D rayOrigin {0.0, 0.0, -2.0};
    const Inept::Core::Vector3D rayDirection {0.0, 0.0, 1.0};
    const Inept::Core::Ray ray(rayOrigin, rayDirection);

    // Perform the intersection test
    const std::optional<Inept::Core::SurfaceInteraction> intersection = sphere.intersect(ray);

    // Check if the intersection is valid
    QVERIFY(intersection.has_value());

    // Check the intersection point
    const Inept::Core::Vector3D expectedIntersectionPoint {0.0, 0.0, -1.0};
    if (intersection.has_value())
    {
        QCOMPARE(intersection->point(), expectedIntersectionPoint);
    }

    // Check the surface normal
    const Inept::Core::Vector3D expectedSurfaceNormal {0.0, 0.0, -1.0};
    if (intersection.has_value())
    {
        QCOMPARE(intersection->normal(), expectedSurfaceNormal);
    }
}

// Test case for ray not intersecting with the sphere
void SphereTest::noIntersectTest()
{
    // Create a sphere
    const Inept::Core::Vector3D position {0.0, 0.0, 0.0};
    const double radius {1.0};
    const Inept::Core::Vector3D color {1.0, 1.0, 1.0};
    const Inept::Core::Vector3D emission {0.0, 0.0, 0.0};
    const Inept::Core::Material material {color, emission};
    const Inept::Core::Sphere sphere(position, radius, material);

    // Create a ray that does not intersect with the sphere
    const Inept::Core::Vector3D rayOrigin {0.0, 0.0, -2.0};
    const Inept::Core::Vector3D rayDirection {0.0, 1.0, 0.0};
    const Inept::Core::Ray ray(rayOrigin, rayDirection);

    // Perform the intersection test
    const std::optional<Inept::Core::SurfaceInteraction> intersection = sphere.intersect(ray);

    // Check if there is no intersection
    QVERIFY(!intersection.has_value());
}

QTEST_MAIN(SphereTest)
#include "sphere.test.moc"