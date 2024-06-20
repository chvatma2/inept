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

#include "core/ray.h"
#include <QTest>

class RayTest : public QObject
{
    Q_OBJECT
private slots:
    static void constructorTest()
    {
        const Inept::Core::Vector3D origin {0.0, 0.0, 0.0};
        const Inept::Core::Vector3D direction {1.0, 0.0, 0.0};
        const Inept::Core::Ray ray {origin, direction};
        QCOMPARE(ray.origin(), origin);
        QCOMPARE(ray.direction(), direction);
    }
    static void equalityOperatorTest()
    {
        const Inept::Core::Vector3D origin1 {0.0, 0.0, 0.0};
        const Inept::Core::Vector3D direction1 {1.0, 0.0, 0.0};
        const Inept::Core::Ray ray1 {origin1, direction1};

        const Inept::Core::Vector3D origin2 {0.0, 0.0, 0.0};
        const Inept::Core::Vector3D direction2 {1.0, 0.0, 0.0};
        const Inept::Core::Ray ray2 {origin2, direction2};

        const Inept::Core::Vector3D origin3 {1.0, 1.0, 1.0};
        const Inept::Core::Vector3D direction3 {0.0, 1.0, 0.0};
        const Inept::Core::Ray ray3 {origin3, direction3};

        QVERIFY(ray1 == ray2);
        QVERIFY(!(ray1 == ray3));
    }
};
QTEST_MAIN(RayTest)
#include "ray.test.moc"
