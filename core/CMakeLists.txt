set(inept_core_sources src/sphere.cpp)
set(inept_core_headers include/core/sphere.h)

add_library(core ${inept_core_sources} ${inept_core_headers})
target_include_directories(core PUBLIC include)
