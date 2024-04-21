find_package(
  Qt6
  COMPONENTS Test Core Gui
  REQUIRED)

set(classes primitive ray sampler scene sphere surfaceinteraction)

add_library(core STATIC)
target_include_directories(core PUBLIC include)
target_link_libraries(core PUBLIC Qt6::Core Qt6::Gui)

function(process_sources)
  foreach(class ${ARGN})
    target_sources(
      core
      INTERFACE include/core/${class}.h
      PRIVATE src/${class}.cpp)
    qt_add_executable(tst_${class} test/${class}.test.cpp)
    add_test(NAME tst_${class} COMMAND tst_${class})
    target_link_libraries(tst_${class} PRIVATE Qt::Test core)
  endforeach()
endfunction()

process_sources(${classes})
