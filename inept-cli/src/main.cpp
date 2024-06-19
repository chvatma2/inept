/* MIT License

Copyright(c) 2024 Martin Chvatal

 Permission is hereby granted,
 free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"),
 to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge,
 publish, distribute, sublicense, and / or sell copies of the Software,
 and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions :

 The above copyright notice and this permission notice shall be included in all copies
 or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS",
 WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

// GCOV_EXCL_START

#include "core/scene.h"
#include "core/sphere.h"
#include <memory>

auto setupCornellBox() -> Inept::Core::Scene
{
    std::vector<std::unique_ptr<Inept::Core::Primitive>> primitives;
    // Define materials
    // Material whiteMaterial; // Assuming you have a way to define colors and other properties
    // Material redMaterial;
    // Material greenMaterial;
    // Material lightMaterial;

    // Large spheres acting as walls, floor, and ceiling
    // Note: The positions and sizes are symbolic and need to be adjusted based on your scene's scale
    const Inept::Core::Vector3D noEmissions{0, 0, 0};
    const Inept::Core::Vector3D whiteEmissions{200, 200, 200};
    const Inept::Core::Vector3D white{1.0, 1.0, 1.0};
    const Inept::Core::Vector3D red{1.0, 0, 0};
    const Inept::Core::Vector3D green{0, 1.0, 0};
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{0, -10004, -20}, 10000.0, white, noEmissions)); // Floor
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{0, 10004, -20}, 10000, white, noEmissions)); // Ceiling
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{10004, 0, -20}, 10000, white, noEmissions)); // Right Wall
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{-10004, 0, -20}, 10000, white, noEmissions)); // Left Wall
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{0, 0, -10004}, 10000, white, noEmissions)); // Back Wall
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{0, 0, 10004}, 10000, white, noEmissions)); // Front Wall (Assuming the camera is inside the box)

    // Smaller spheres inside the Cornell Box
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{-0.5, -0.5, -1}, 0.5, red, noEmissions));
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{0.5, -0.5, -1}, 0.5, green, noEmissions));

    // Light source (represented as a small, bright sphere for simplicity)
    primitives.push_back(std::make_unique<Inept::Core::Sphere>(Inept::Core::Vector3D{0.0, 0.99, -2}, 0.2, white, whiteEmissions));
    const Inept::Core::Camera camera{Inept::Core::Vector3D{0.0, 0.0, 0.0}, Inept::Core::Vector3D{0.0, 0.0, -1.0}, Inept::Core::Vector3D{0.0, 1.0, 0.0}, 90.0, 16.0 / 9.0, 0.1};
    return {std::move(primitives), camera};
}

auto main() -> int
{
    
    return 0;
}
// GCOV_EXCL_STOP
