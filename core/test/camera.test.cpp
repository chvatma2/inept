#include <QtTest>
#include "core/camera.h"

class CameraTest : public QObject
{
    Q_OBJECT

private slots:
    static void testGetRay();
    static void testOperatorEquals();
};

void CameraTest::testGetRay()
{
    // Arrange
    const Inept::Core::Vector3D position(0, 0, 0);
    const Inept::Core::Vector3D lookAt(1, 0, 0);
    const Inept::Core::Vector3D up(0, 1, 0);
    const double fov = 90.0;
    const double aspectRatio = 16.0 / 9.0;
    const double nearPlane = 0.1;
    const Inept::Core::Camera camera(position, lookAt, up, fov, aspectRatio, nearPlane);

    // Act
    const Inept::Core::Ray ray = camera.getRay(0.5, 0.5);

    // Assert
    QCOMPARE(ray.origin(), position);
    QCOMPARE(ray.direction(), (lookAt - position).normalize());
}

void CameraTest::testOperatorEquals()
{
    // Arrange
    const Inept::Core::Vector3D position1(0, 0, 0);
    const Inept::Core::Vector3D lookAt1(1, 0, 0);
    const Inept::Core::Vector3D up1(0, 1, 0);
    const double fov1 = 90.0;
    const double aspectRatio1 = 16.0 / 9.0;
    const double nearPlane1 = 0.1;
    const Inept::Core::Camera camera1(position1, lookAt1, up1, fov1, aspectRatio1, nearPlane1);

    const Inept::Core::Vector3D position2(0, 0, 0);
    const Inept::Core::Vector3D lookAt2(1, 0, 0);
    const Inept::Core::Vector3D up2(0, 1, 0);
    const double fov2 = 90.0;
    const double aspectRatio2 = 16.0 / 9.0;
    const double nearPlane2 = 0.1;
    const Inept::Core::Camera camera2(position2, lookAt2, up2, fov2, aspectRatio2, nearPlane2);

    const Inept::Core::Vector3D position3(1, 1, 1);
    const Inept::Core::Vector3D lookAt3(1, 0, 0);
    const Inept::Core::Vector3D up3(0, 1, 0);
    const double fov3 = 90.0;
    const double aspectRatio3 = 16.0 / 9.0;
    const double nearPlane3 = 0.1;
    const Inept::Core::Camera camera3(position3, lookAt3, up3, fov3, aspectRatio3, nearPlane3);

    // Act & Assert
    QVERIFY(camera1 == camera2);
    QVERIFY(!(camera1 == camera3));
}

QTEST_APPLESS_MAIN(CameraTest)

#include "camera.test.moc"