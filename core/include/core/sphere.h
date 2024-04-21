#include <QVector3D>

namespace Inept::Core {
class Sphere
{
public:
    Sphere();

private:
    QVector3D m_position;
    qreal m_size {0.0};
};
} // namespace Inept::Core
