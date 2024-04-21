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
    void constructorTest()
    {
        const QVector3D color {1.0f, 0.0f, 0.5f};
        const QVector3D emission {0.0f, 0.5f, 1.0f};
        const QVector3D position {0.5f, 1.0f, 0.0f};
        float size {2.0f};
        Inept::Core::Sphere sphere(color, emission, position, size);
        QCOMPARE(sphere.color(), color);
        QCOMPARE(sphere.emission(), emission);
    }

private:
};
QTEST_MAIN(SphereTest)
#include "sphere.test.moc"
