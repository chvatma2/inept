#include "core/sphere.h"
#include <QTest>

class SphereTest : public QObject
{
    Q_OBJECT
private slots:
    static void placeholderTest()
    {
        QVERIFY(true);
    }
};
QTEST_MAIN(SphereTest)
#include "sphere.test.moc"
