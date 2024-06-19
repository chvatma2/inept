#ifndef VECTOR3D_H
#define VECTOR3D_H

namespace Inept::Core {

class Vector3D {
public:
    explicit Vector3D(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z} {}

    [[nodiscard]] auto x() const noexcept -> double { return m_x; }
    [[nodiscard]] auto y() const noexcept -> double { return m_y; }
    [[nodiscard]] auto z() const noexcept -> double { return m_z; }

    void setX(double x) noexcept { m_x = x; }
    void setY(double y) noexcept { m_y = y; }
    void setZ(double z) noexcept { m_z = z; }

    [[nodiscard]] auto operator+(const Vector3D& other) const noexcept -> Vector3D;
    [[nodiscard]] auto operator-(const Vector3D& other) const noexcept -> Vector3D;
    [[nodiscard]] auto operator*(double scalar) const noexcept -> Vector3D;
    [[nodiscard]] auto operator/(double scalar) const -> Vector3D;
    [[nodiscard]] auto operator==(const Vector3D& other) const noexcept -> bool;
    [[nodiscard]] auto length() const noexcept -> double;
    [[nodiscard]] auto dot(const Vector3D& other) const noexcept -> double;
    [[nodiscard]] auto normalize() const noexcept -> Vector3D;
    [[nodiscard]] auto cross(const Vector3D& other) const noexcept -> Vector3D;

private:
    double m_x{0.0};
    double m_y{0.0};
    double m_z{0.0};
};;

} // namespace Inept::Core

#endif // VECTOR3D_H