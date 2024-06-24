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

#include "core/material.h"
#include <QTest>

using Inept::Core::Vector3D;
using Inept::Core::Material;
using Inept::Core::MaterialType;

class MaterialTest : public QObject {
    Q_OBJECT

private slots:
    static void testColor() {
        const Vector3D color(0.5, 0.5, 0.5);
        const Vector3D emission(0.2, 0.2, 0.2);
        const Material material(color, emission, MaterialType::Diffuse);

        QCOMPARE(material.color(), color);
    }

    static void testEmission() {
        const Vector3D color(0.5, 0.5, 0.5);
        const Vector3D emission(0.2, 0.2, 0.2);
        const Material material(color, emission, MaterialType::Diffuse);

        QCOMPARE(material.emission(), emission);
    }

    static void testType() {
        const Vector3D color(0.5, 0.5, 0.5);
        const Vector3D emission(0.2, 0.2, 0.2);
        const Material material(color, emission, MaterialType::Diffuse);

        QCOMPARE(material.type(), MaterialType::Diffuse);
    }

    static void testEquality() {
        const Vector3D color(0.5, 0.5, 0.5);
        const Vector3D emission(0.2, 0.2, 0.2);
        const Material material1(color, emission, MaterialType::Diffuse);
        const Material material2(color, emission, MaterialType::Diffuse);

        QVERIFY(material1 == material2);
    }
};

QTEST_APPLESS_MAIN(MaterialTest)

#include "material.test.moc"
