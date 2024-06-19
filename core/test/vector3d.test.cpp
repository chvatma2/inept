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
    static void testAddition();
    static void testAdditionWithZero();
    static void testAdditionWithNegative();
    static void testSubtraction();
    static void testMultiplication();
    static void testDivision();
    static void testAdditionWithLargeValues();
    static void testSubtractionWithSmallValues();
    static void testMultiplicationWithZeroScalar();
    static void testEqualityOperator();
    static void testDivisionByZeroScalarAndNaN();
    static void testLength();
    static void testDotProduct();
    static void testNormalized();
    static void testCrossProduct();
};

/// @brief Test the addition operator of the Vector3D class.
/// @details The test checks if the addition operator of the Vector3D class returns the correct result.
void TestVector3D::testAddition() {
    const Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    const Inept::Core::Vector3D v2(4.0, 5.0, 6.0);
    const Inept::Core::Vector3D result = v1 + v2;

    QCOMPARE(result.x(), 5.0);
    QCOMPARE(result.y(), 7.0);
    QCOMPARE(result.z(), 9.0);
}

/// @brief Test the addition operator of the Vector3D class with zero.
/// @details The test checks if the addition operator of the Vector3D class returns the correct result when adding a vector with a zero vector.
void TestVector3D::testAdditionWithZero() {
    const Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    const Inept::Core::Vector3D v2(0.0, 0.0, 0.0);
    const Inept::Core::Vector3D result = v1 + v2;

    QCOMPARE(result.x(), 1.0);
    QCOMPARE(result.y(), 2.0);
    QCOMPARE(result.z(), 3.0);
}

/// @brief Test the addition operator of the Vector3D class with negative values.
/// @details The test checks if the addition operator of the Vector3D class returns the correct result when adding a vector with a negative vector.
void TestVector3D::testAdditionWithNegative() {
    const Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    const Inept::Core::Vector3D v2(-1.0, -2.0, -3.0);
    const Inept::Core::Vector3D result = v1 + v2;

    QCOMPARE(result.x(), 0.0);
    QCOMPARE(result.y(), 0.0);
    QCOMPARE(result.z(), 0.0);
}

/// @brief Test the subtraction operator of the Vector3D class.
/// @details The test checks if the subtraction operator of the Vector3D class returns the correct result.
void TestVector3D::testSubtraction() {
    const Inept::Core::Vector3D v1(5.0, 7.0, 9.0);
    const Inept::Core::Vector3D v2(2.0, 3.0, 4.0);
    const Inept::Core::Vector3D result = v1 - v2;
    QCOMPARE(result.x(), 3.0);
    QCOMPARE(result.y(), 4.0);
    QCOMPARE(result.z(), 5.0);
}

/// @brief Test the multiplication operator of the Vector3D class.
/// @details The test checks if the multiplication operator of the Vector3D class returns the correct result.
void TestVector3D::testMultiplication() {
    const Inept::Core::Vector3D v1(2.0, 3.0, 4.0);
    const double scalar = 2.5;
    const Inept::Core::Vector3D result = v1 * scalar;
    QCOMPARE(result.x(), 5.0);
    QCOMPARE(result.y(), 7.5);
    QCOMPARE(result.z(), 10.0);
}

/// @brief Test the division operator of the Vector3D class.
/// @details The test checks if the division operator of the Vector3D class returns the correct result.
void TestVector3D::testDivision() {
    const Inept::Core::Vector3D v1(10.0, 15.0, 20.0);
    const double scalar = 2.0;
    const Inept::Core::Vector3D result = v1 / scalar;
    QCOMPARE(result.x(), 5.0);
    QCOMPARE(result.y(), 7.5);
    QCOMPARE(result.z(), 10.0);
}

/// @brief Test the addition operator of the Vector3D class with large values.
/// @details The test checks if the addition operator of the Vector3D class returns the correct result when adding vectors with large values.
void TestVector3D::testAdditionWithLargeValues() {
    const Inept::Core::Vector3D v1(1e9, 1e9, 1e9);
    const Inept::Core::Vector3D v2(1e9, 1e9, 1e9);
    const Inept::Core::Vector3D result = v1 + v2;
    QCOMPARE(result.x(), 2e9);
    QCOMPARE(result.y(), 2e9);
    QCOMPARE(result.z(), 2e9);
}

/// @brief Test the subtraction operator of the Vector3D class with small values.
/// @details The test checks if the subtraction operator of the Vector3D class returns the correct result when subtracting vectors with small values.
void TestVector3D::testSubtractionWithSmallValues() {
    const Inept::Core::Vector3D v1(1e-9, 1e-9, 1e-9);
    const Inept::Core::Vector3D v2(1e-9, 1e-9, 1e-9);
    const Inept::Core::Vector3D result = v1 - v2;
    QCOMPARE(result.x(), 0.0);
    QCOMPARE(result.y(), 0.0);
    QCOMPARE(result.z(), 0.0);
}

/// @brief Test the multiplication operator of the Vector3D class with zero scalar.
/// @details The test checks if the multiplication operator of the Vector3D class returns the correct result when multiplying a vector with a zero scalar.
void TestVector3D::testMultiplicationWithZeroScalar() {
    const Inept::Core::Vector3D v1(2.0, 3.0, 4.0);
    const double scalar = 0.0;
    const Inept::Core::Vector3D result = v1 * scalar;
    QCOMPARE(result.x(), 0.0);
    QCOMPARE(result.y(), 0.0);
    QCOMPARE(result.z(), 0.0);
}

/// @brief Test the division operator of the Vector3D class with zero scalar and NaN.
/// @details The test checks if the division operator of the Vector3D class throws an exception when dividing a vector by a zero scalar or a NaN scalar.
void TestVector3D::testDivisionByZeroScalarAndNaN() {
    const Inept::Core::Vector3D v1(10.0, 15.0, 20.0);
    const double scalar = 0.0;
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, {
        [[maybe_unused]] const Inept::Core::Vector3D result = v1 / scalar;
    });
    const double nanScalar = std::numeric_limits<double>::quiet_NaN();
    QVERIFY_THROWS_EXCEPTION(std::invalid_argument, {
        [[maybe_unused]] const Inept::Core::Vector3D result = v1 / nanScalar;
    });
}

/// @brief Test the equality operator of the Vector3D class.
/// @details The test checks if the equality operator of the Vector3D class returns the correct result.
void TestVector3D::testEqualityOperator() {
    const Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    const Inept::Core::Vector3D v2(1.0, 2.0, 3.0);
    QVERIFY(v1 == v2);

    const Inept::Core::Vector3D v3(4.0, 5.0, 6.0);
    QVERIFY(!(v1 == v3));
}

/// @brief Test the length() function of the Vector3D class.
/// @details The test checks if the length() function of the Vector3D class returns the correct result.
void TestVector3D::testLength() {
    const Inept::Core::Vector3D v1(3.0, 4.0, 0.0);
    const double expectedLength1 = 5.0;
    QCOMPARE(v1.length(), expectedLength1);

    const Inept::Core::Vector3D v2(0.0, 0.0, 0.0);
    const double expectedLength2 = 0.0;
    QCOMPARE(v2.length(), expectedLength2);

    const Inept::Core::Vector3D v3(1.0, 0.0, 0.0);
    const double expectedLength3 = 1.0;
    QCOMPARE(v3.length(), expectedLength3);

    const Inept::Core::Vector3D v4(0.0, 1.0, 0.0);
    const double expectedLength4 = 1.0;
    QCOMPARE(v4.length(), expectedLength4);

    const Inept::Core::Vector3D v5(0.0, 0.0, 1.0);
    const double expectedLength5 = 1.0;
    QCOMPARE(v5.length(), expectedLength5);

    const Inept::Core::Vector3D v6(1e9, 1e9, 1e9);
    const double expectedLength6 = 1.73205080757e9;
    QCOMPARE(v6.length(), expectedLength6);

    const Inept::Core::Vector3D v7(1e-9, 1e-9, 1e-9);
    const double expectedLength7 = 1.73205080757e-9;
    QCOMPARE(v7.length(), expectedLength7);
}

/// @brief Test the dot product of the Vector3D class.
/// @details The test checks if the dot product of the Vector3D class returns the correct result.
void TestVector3D::testDotProduct() {
    const Inept::Core::Vector3D v1(1.0, 2.0, 3.0);
    const Inept::Core::Vector3D v2(4.0, 5.0, 6.0);
    const double expectedDotProduct = 32.0;
    QCOMPARE(v1.dot(v2), expectedDotProduct);
    
    const Inept::Core::Vector3D v3(0.0, 0.0, 0.0);
    const Inept::Core::Vector3D v4(1.0, 2.0, 3.0);
    const double expectedDotProduct2 = 0.0;
    QCOMPARE(v3.dot(v4), expectedDotProduct2);
    
    const Inept::Core::Vector3D v5(-1.0, -2.0, -3.0);
    const Inept::Core::Vector3D v6(1.0, 2.0, 3.0);
    const double expectedDotProduct3 = -14.0;
    QCOMPARE(v5.dot(v6), expectedDotProduct3);
}

/// @brief Test the normalized() function of the Vector3D class.
/// @details The test checks if the normalized() function of the Vector3D class returns the correct result.
void TestVector3D::testNormalized() {
    const Inept::Core::Vector3D v1(3.0, 4.0, 0.0);
    const Inept::Core::Vector3D normalizedV1 = v1.normalize();
    const double expectedLength1 = 1.0;
    QCOMPARE(normalizedV1.length(), expectedLength1);
    QCOMPARE(normalizedV1.x(), 0.6);
    QCOMPARE(normalizedV1.y(), 0.8);
    QCOMPARE(normalizedV1.z(), 0.0);

    const Inept::Core::Vector3D v2(0.0, 0.0, 0.0);
    const Inept::Core::Vector3D normalizedV2 = v2.normalize();
    const double expectedLength2 = 0.0;
    QCOMPARE(normalizedV2.length(), expectedLength2);
    QCOMPARE(normalizedV2.x(), 0.0);
    QCOMPARE(normalizedV2.y(), 0.0);
    QCOMPARE(normalizedV2.z(), 0.0);

    const Inept::Core::Vector3D v3(1.0, 0.0, 0.0);
    const Inept::Core::Vector3D normalizedV3 = v3.normalize();
    const double expectedLength3 = 1.0;
    QCOMPARE(normalizedV3.length(), expectedLength3);
    QCOMPARE(normalizedV3.x(), 1.0);
    QCOMPARE(normalizedV3.y(), 0.0);
    QCOMPARE(normalizedV3.z(), 0.0);

    const Inept::Core::Vector3D v4(0.0, 1.0, 0.0);
    const Inept::Core::Vector3D normalizedV4 = v4.normalize();
    const double expectedLength4 = 1.0;
    QCOMPARE(normalizedV4.length(), expectedLength4);
    QCOMPARE(normalizedV4.x(), 0.0);
    QCOMPARE(normalizedV4.y(), 1.0);
    QCOMPARE(normalizedV4.z(), 0.0);

    const Inept::Core::Vector3D v5(0.0, 0.0, 1.0);
    const Inept::Core::Vector3D normalizedV5 = v5.normalize();
    const double expectedLength5 = 1.0;
    QCOMPARE(normalizedV5.length(), expectedLength5);
    QCOMPARE(normalizedV5.x(), 0.0);
    QCOMPARE(normalizedV5.y(), 0.0);
    QCOMPARE(normalizedV5.z(), 1.0);

    const Inept::Core::Vector3D v6(1e9, 1e9, 1e9);
    const Inept::Core::Vector3D normalizedV6 = v6.normalize();
    const double expectedLength6 = 1.0;
    QCOMPARE(normalizedV6.length(), expectedLength6);
    QCOMPARE(normalizedV6.x(), 0.57735026919);
    QCOMPARE(normalizedV6.y(), 0.57735026919);
    QCOMPARE(normalizedV6.z(), 0.57735026919);

    const Inept::Core::Vector3D v7(1e-9, 1e-9, 1e-9);
    const Inept::Core::Vector3D normalizedV7 = v7.normalize();
    const double expectedLength7 = 1.0;
    QCOMPARE(normalizedV7.length(), expectedLength7);
    QCOMPARE(normalizedV7.x(), 0.57735026919);
    QCOMPARE(normalizedV7.y(), 0.57735026919);
    QCOMPARE(normalizedV7.z(), 0.57735026919);
}

/// @brief Test the cross product of the Vector3D class.
/// @details The test checks if the cross product of the Vector3D class returns the correct result.
void TestVector3D::testCrossProduct() {
    const Inept::Core::Vector3D v1(1.0, 0.0, 0.0);
    const Inept::Core::Vector3D v2(0.0, 1.0, 0.0);
    const Inept::Core::Vector3D expectedCrossProduct1(0.0, 0.0, 1.0);
    QCOMPARE(v1.cross(v2), expectedCrossProduct1);
    
    const Inept::Core::Vector3D v3(2.0, 3.0, 4.0);
    const Inept::Core::Vector3D v4(5.0, 6.0, 7.0);
    const Inept::Core::Vector3D expectedCrossProduct2(-3.0, 6.0, -3.0);
    QCOMPARE(v3.cross(v4), expectedCrossProduct2);
    
    const Inept::Core::Vector3D v5(0.0, 0.0, 0.0);
    const Inept::Core::Vector3D v6(1.0, 2.0, 3.0);
    const Inept::Core::Vector3D expectedCrossProduct3(0.0, 0.0, 0.0);
    QCOMPARE(v5.cross(v6), expectedCrossProduct3);
    
    const Inept::Core::Vector3D v7(-1.0, -2.0, -3.0);
    const Inept::Core::Vector3D v8(1.0, 2.0, 3.0);
    const Inept::Core::Vector3D expectedCrossProduct4(0.0, 0.0, 0.0);
    QCOMPARE(v7.cross(v8), expectedCrossProduct4);
}

QTEST_MAIN(TestVector3D)
#include "vector3d.test.moc"