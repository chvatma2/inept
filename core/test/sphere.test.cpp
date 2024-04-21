#include "core/sphere.h"
#include <QTest>

class SphereTest : public QObject
{
    Q_OBJECT
private slots:
    void placeholderTest()
    {
        QVERIFY(&m_sphere);
    }

private:
    Inept::Core::Sphere m_sphere;
};
QTEST_MAIN(SphereTest)
#include "sphere.test.moc"
