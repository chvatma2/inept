#include "core/triangle.h"
#include <QtTest>

// Define a test class
class TriangleTest : public QObject
{
    Q_OBJECT

private slots:
    // Test case to check the calculation of the area
    static void testCalculateArea()
    {
        // Create a Triangle object with specific vertices
        const Inept::Core::Triangle triangle(Inept::Core::Vector3D{0.0, 0.0, 0.0}, Inept::Core::Vector3D{0.0, 3.0, 0.0}, Inept::Core::Vector3D{4.0, 0.0, 0.0});

        // Calculate the expected area
        const double expectedArea = 6.0;

        // Compare the calculated area with the expected area
        QCOMPARE(triangle.calculateArea(), expectedArea);
    }

    // Test case to check the calculation of the perimeter
    static void testCalculatePerimeter()
    {
        // Create a Triangle object with specific vertices
        const Inept::Core::Triangle triangle(Inept::Core::Vector3D{0.0, 0.0, 0.0}, Inept::Core::Vector3D{0.0, 3.0, 0.0}, Inept::Core::Vector3D{4.0, 0.0, 0.0});

        // Calculate the expected perimeter
        const double expectedPerimeter = 12.0;

        // Compare the calculated perimeter with the expected perimeter
        QCOMPARE(triangle.calculatePerimeter(), expectedPerimeter);
    }

    static void testVertex1()
    {
        // Create a Triangle object with specific vertices
        Inept::Core::Triangle triangle(Inept::Core::Vector3D{0.0, 0.0, 0.0}, Inept::Core::Vector3D{0.0, 3.0, 0.0}, Inept::Core::Vector3D{4.0, 0.0, 0.0});
        // Create a Vector3D object for testing
        const Inept::Core::Vector3D vertex1{1.0, 2.0, 3.0};
        // Set vertex 1 using the setter
        triangle.setVertex1(vertex1);
        // Check if the getter returns the correct value
        QCOMPARE(triangle.getVertex1(), vertex1);
    }

    // Test case to check the getter and setter for vertex 2
    static void testVertex2()
    {
        // Create a Triangle object with specific vertices
        Inept::Core::Triangle triangle(Inept::Core::Vector3D{0.0, 0.0, 0.0}, Inept::Core::Vector3D{0.0, 3.0, 0.0}, Inept::Core::Vector3D{4.0, 0.0, 0.0});
        // Create a Vector3D object for testing
        const Inept::Core::Vector3D vertex2{5.0, 6.0, 7.0};
        // Set vertex 2 using the setter
        triangle.setVertex2(vertex2);
        // Check if the getter returns the correct value
        QCOMPARE(triangle.getVertex2(), vertex2);
    }

// Test case to check the getter and setter for vertex 3
    static void testVertex3()
    {
        // Create a Triangle object with specific vertices
        Inept::Core::Triangle triangle(Inept::Core::Vector3D{0.0, 0.0, 0.0}, Inept::Core::Vector3D{0.0, 3.0, 0.0}, Inept::Core::Vector3D{4.0, 0.0, 0.0});
        // Create a Vector3D object for testing
        const Inept::Core::Vector3D vertex3{8.0, 9.0, 10.0};
        // Set vertex 3 using the setter
        triangle.setVertex3(vertex3);
        // Check if the getter returns the correct value
        QCOMPARE(triangle.getVertex3(), vertex3);
    }
};

// Run the tests
QTEST_APPLESS_MAIN(TriangleTest)

#include "triangle.test.moc"// Test case to check the getter and setter for vertex 1