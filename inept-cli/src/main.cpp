// GCOV_EXCL_START
#include "core/sphere.h"
#include <iostream>
auto main() -> int
{
    const Inept::Core::Sphere test;
    Inept::Core::Sphere* point {nullptr};
    if (&test != point) {
        std::cout << "Hello World!" << '\n';
    }
    return 0;
}
// GCOV_EXCL_STOP
