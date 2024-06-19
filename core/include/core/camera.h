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

#ifndef CAMERA_H
#define CAMERA_H

#include "core/vector3d.h"
#include "core/ray.h"

namespace Inept::Core {

/// @brief A camera class that represents a camera in a 3D scene.
/// @details The camera class is used to generate rays that are cast into the scene.
class Camera {
public:
    /// @brief Constructs a camera object.
    /// @param position The position of the camera.
    /// @param lookAt The point the camera is looking at.
    /// @param up The up vector of the camera.
    /// @param fov The field of view of the camera.
    /// @param aspectRatio The aspect ratio of the camera.
    /// @param nearPlane The near plane of the camera.
    Camera(const Inept::Core::Vector3D& position, const Inept::Core::Vector3D& lookAt, const Inept::Core::Vector3D& up, double fov, double aspectRatio, double nearPlane) noexcept;

    /// @brief Equality operator for comparing two Camera objects.
    /// @param other The Camera object to compare with.
    /// @return True if the Camera objects are equal, false otherwise.
    auto operator==(const Camera& other) const noexcept -> bool;

    /// @brief Generates a ray from the camera.
    /// @param u The normalized u coordinate of the pixel.
    /// @param v The normalized v coordinate of the pixel.
    /// @return A ray from the camera to the pixel.
    /// @details The u and v coordinates are normalized to the range [0, 1]. 
    [[nodiscard]] auto getRay(double u, double v) const noexcept -> Inept::Core::Ray;

    /// @brief Returns the position of the camera.
    /// @return The position of the camera.
    [[nodiscard]] auto position() const noexcept -> const Inept::Core::Vector3D& { return m_position; }

    /// @brief Returns the forward vector of the camera.
    /// @return The forward vector of the camera.
    [[nodiscard]] auto forward() const noexcept -> const Inept::Core::Vector3D& { return m_forward; }

    /// @brief Returns the right vector of the camera.
    /// @return The right vector of the camera.
    [[nodiscard]] auto right() const noexcept -> const Inept::Core::Vector3D& { return m_right; }

    /// @brief Returns the up vector of the camera.
    /// @return The up vector of the camera.
    [[nodiscard]] auto up() const noexcept -> const Inept::Core::Vector3D& { return m_up; }

    /// @brief Returns the field of view of the camera.
    /// @return The field of view of the camera.
    [[nodiscard]] auto fov() const noexcept -> double { return m_fov; }

    /// @brief Returns the aspect ratio of the camera.
    /// @return The aspect ratio of the camera.
    [[nodiscard]] auto aspectRatio() const noexcept -> double { return m_aspectRatio; }

    /// @brief Returns the near plane of the camera.
    /// @return The near plane of the camera.
    [[nodiscard]] auto nearPlane() const noexcept -> double { return m_nearPlane; }

private:
    Inept::Core::Vector3D m_position;
    Inept::Core::Vector3D m_forward;
    Inept::Core::Vector3D m_right;
    Inept::Core::Vector3D m_up;
    double m_fov{0.0};
    double m_aspectRatio{0.0};
    double m_nearPlane{0.0};
};

} // namespace Inept::Core
#endif // CAMERA_H
