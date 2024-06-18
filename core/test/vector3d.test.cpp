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

#include <QtTest>
#include "core/vector3d.h"

/// @brief Test the Vector3D class.
/// @details The test checks the functionality of the Vector3D class.
class TestVector3D : public QObject {
    Q_OBJECT

private slots:
    void testAddition();
    void testAdditionWithZero();
    void testAdditionWithNegative();
    void testSubtraction();
    void testMultiplication();
    void testDivision();
    void testAdditionWithLargeValues();
    void testSubtractionWithSmallValues();
    void testMultiplicationWithZeroScalar();
    void testEqualityOperator();
    void testDivisionByZeroScalarAndNaN();
    void testLength();
};

/// @brief Test the addition operator of the Vector3D class.
/// @details The test checks if the addition operator of the Vector3D class returns the correct result.
void TestVector3D::testAddition() {
    Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    Inept::Core::Vector3D v2(4.0, 5.0, 6.0);
    Inept::Core::Vector3D result = v1 + v2;

    QCOMPARE(result.x(), 5.0);
    QCOMPARE(result.y(), 7.0);
    QCOMPARE(result.z(), 9.0);
}

/// @brief Test the addition operator of the Vector3D class with zero.
/// @details The test checks if the addition operator of the Vector3D class returns the correct result when adding a vector with a zero vector.
void TestVector3D::testAdditionWithZero() {
    Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    Inept::Core::Vector3D v2(0.0, 0.0, 0.0);
    Inept::Core::Vector3D result = v1 + v2;

    QCOMPARE(result.x(), 1.0);
    QCOMPARE(result.y(), 2.0);
    QCOMPARE(result.z(), 3.0);
}

/// @brief Test the addition operator of the Vector3D class with negative values.
/// @details The test checks if the addition operator of the Vector3D class returns the correct result when adding a vector with a negative vector.
void TestVector3D::testAdditionWithNegative() {
    Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    Inept::Core::Vector3D v2(-1.0, -2.0, -3.0);
    Inept::Core::Vector3D result = v1 + v2;

    QCOMPARE(result.x(), 0.0);
    QCOMPARE(result.y(), 0.0);
    QCOMPARE(result.z(), 0.0);
}

/// @brief Test the subtraction operator of the Vector3D class.
/// @details The test checks if the subtraction operator of the Vector3D class returns the correct result.
void TestVector3D::testSubtraction() {
    Inept::Core::Vector3D v1(5.0, 7.0, 9.0);
    Inept::Core::Vector3D v2(2.0, 3.0, 4.0);
    Inept::Core::Vector3D result = v1 - v2;
    QCOMPARE(result.x(), 3.0);
    QCOMPARE(result.y(), 4.0);
    QCOMPARE(result.z(), 5.0);
}

/// @brief Test the multiplication operator of the Vector3D class.
/// @details The test checks if the multiplication operator of the Vector3D class returns the correct result.
void TestVector3D::testMultiplication() {
    Inept::Core::Vector3D v1(2.0, 3.0, 4.0);
    double scalar = 2.5;
    Inept::Core::Vector3D result = v1 * scalar;
    QCOMPARE(result.x(), 5.0);
    QCOMPARE(result.y(), 7.5);
    QCOMPARE(result.z(), 10.0);
}

/// @brief Test the division operator of the Vector3D class.
/// @details The test checks if the division operator of the Vector3D class returns the correct result.
void TestVector3D::testDivision() {
    Inept::Core::Vector3D v1(10.0, 15.0, 20.0);
    double scalar = 2.0;
    Inept::Core::Vector3D result = v1 / scalar;
    QCOMPARE(result.x(), 5.0);
    QCOMPARE(result.y(), 7.5);
    QCOMPARE(result.z(), 10.0);
}

/// @brief Test the addition operator of the Vector3D class with large values.
/// @details The test checks if the addition operator of the Vector3D class returns the correct result when adding vectors with large values.
void TestVector3D::testAdditionWithLargeValues() {
    Inept::Core::Vector3D v1(1e9, 1e9, 1e9);
    Inept::Core::Vector3D v2(1e9, 1e9, 1e9);
    Inept::Core::Vector3D result = v1 + v2;
    QCOMPARE(result.x(), 2e9);
    QCOMPARE(result.y(), 2e9);
    QCOMPARE(result.z(), 2e9);
}

/// @brief Test the subtraction operator of the Vector3D class with small values.
/// @details The test checks if the subtraction operator of the Vector3D class returns the correct result when subtracting vectors with small values.
void TestVector3D::testSubtractionWithSmallValues() {
    Inept::Core::Vector3D v1(1e-9, 1e-9, 1e-9);
    Inept::Core::Vector3D v2(1e-9, 1e-9, 1e-9);
    Inept::Core::Vector3D result = v1 - v2;
    QCOMPARE(result.x(), 0.0);
    QCOMPARE(result.y(), 0.0);
    QCOMPARE(result.z(), 0.0);
}

/// @brief Test the multiplication operator of the Vector3D class with zero scalar.
/// @details The test checks if the multiplication operator of the Vector3D class returns the correct result when multiplying a vector with a zero scalar.
void TestVector3D::testMultiplicationWithZeroScalar() {
    Inept::Core::Vector3D v1(2.0, 3.0, 4.0);
    double scalar = 0.0;
    Inept::Core::Vector3D result = v1 * scalar;
    QCOMPARE(result.x(), 0.0);
    QCOMPARE(result.y(), 0.0);
    QCOMPARE(result.z(), 0.0);
}

/// @brief Test the division operator of the Vector3D class with zero scalar and NaN.
/// @details The test checks if the division operator of the Vector3D class throws an exception when dividing a vector by a zero scalar or a NaN scalar.
void TestVector3D::testDivisionByZeroScalarAndNaN() {
    Inept::Core::Vector3D v1(10.0, 15.0, 20.0);
    double scalar = 0.0;
    QVERIFY_EXCEPTION_THROWN({
        [[maybe_unused]] Inept::Core::Vector3D result = v1 / scalar;
    }, std::invalid_argument);
    double nanScalar = std::numeric_limits<double>::quiet_NaN();
    QVERIFY_EXCEPTION_THROWN({
        [[maybe_unused]] Inept::Core::Vector3D result = v1 / nanScalar;
    }, std::invalid_argument);
}

/// @brief Test the equality operator of the Vector3D class.
/// @details The test checks if the equality operator of the Vector3D class returns the correct result.
void TestVector3D::testEqualityOperator() {
    Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    Inept::Core::Vector3D v2(1.0, 2.0, 3.0);
    QVERIFY(v1 == v2);

    Inept::Core::Vector3D v3(4.0, 5.0, 6.0);
    QVERIFY(!(v1 == v3));
}

/// @brief Test the length() function of the Vector3D class.
/// @details The test checks if the length() function of the Vector3D class returns the correct result.
void TestVector3D::testLength() {
    Inept::Core::Vector3D v1(3.0, 4.0, 0.0);
    double expectedLength1 = 5.0;
    QCOMPARE(v1.length(), expectedLength1);

    Inept::Core::Vector3D v2(0.0, 0.0, 0.0);
    double expectedLength2 = 0.0;
    QCOMPARE(v2.length(), expectedLength2);

    Inept::Core::Vector3D v3(1.0, 0.0, 0.0);
    double expectedLength3 = 1.0;
    QCOMPARE(v3.length(), expectedLength3);

    Inept::Core::Vector3D v4(0.0, 1.0, 0.0);
    double expectedLength4 = 1.0;
    QCOMPARE(v4.length(), expectedLength4);

    Inept::Core::Vector3D v5(0.0, 0.0, 1.0);
    double expectedLength5 = 1.0;
    QCOMPARE(v5.length(), expectedLength5);

    Inept::Core::Vector3D v6(1e9, 1e9, 1e9);
    double expectedLength6 = 1.73205080757e9;
    QCOMPARE(v6.length(), expectedLength6);

    Inept::Core::Vector3D v7(1e-9, 1e-9, 1e-9);
    double expectedLength7 = 1.73205080757e-9;
    QCOMPARE(v7.length(), expectedLength7);
}

QTEST_MAIN(TestVector3D)
#include "vector3d.test.moc"