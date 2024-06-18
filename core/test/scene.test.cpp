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
#include <memory>
#include <vector>
#include <QTest>

class SceneTest : public QObject
{
    Q_OBJECT
private slots:
    static void constructorTest()
    {
        std::vector<std::unique_ptr<Inept::Core::Primitive>> primitives;
        primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D(0,0,0), Inept::Core::Vector3D(0,0,0), Inept::Core::Vector3D(0,0,0), 1.0));
        const Inept::Core::Vector3D camera {1.0, 0.0, 0.0};
        const Inept::Core::Scene scene {std::move(primitives), camera};
        QCOMPARE(scene.camera(), camera);
    }
};
QTEST_MAIN(SceneTest)
#include "scene.test.moc"
