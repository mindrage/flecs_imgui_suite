cmake_minimum_required(VERSION 3.11)


project(flecs_imgui)

set(CXX_STANDARD_REQUIRED 11)
set(C_STANDARD_REQUIRED 99)

option(USE_TESTBENCH "Build the testbench and GLFW/OpenGL3 backends" ON)

add_subdirectory(glfw)

include_directories(
  flecs/
  imgui/
  imgui_extras/
  flecs_imgui/
)

set (FLECS_IMGUI_SRC
  ./flecs/flecs.h
  ./flecs/flecs.c

  ./flecs_imgui/flecs_imgui.cpp
)

set (IMGUI_SRC
  ./imgui/imgui_demo.cpp
  ./imgui/imgui_draw.cpp
  ./imgui/imgui_tables.cpp
  ./imgui/imgui_widgets.cpp
  ./imgui/imgui.cpp
)


# Additional widgets
set (IMGUI_EXTRAS_SRC
  imgui_extras/imgui_extras
)

# add_library(imgui_extras STATIC ${IMGUI_EXTRAS_SRC})
add_library(flecs_imgui STATIC ${FLECS_IMGUI_SRC} ${IMGUI_SRC})


if(USE_TESTBENCH)
  # Backends are only used for testbench or client.
  set (IMGUI_BACKEND_SRC
    ./imgui/backends/imgui_impl_opengl3.cpp
    ./imgui/backends/imgui_impl_glfw.cpp
    ./imgui_backends/imgui_backend_glfw_opengl3.cpp
    ./imgui/examples/libs/gl3w/GL/gl3w.c
  )

  include_directories(
    ./imgui/backends/
    ./imgui_backends/
    ./testbench/
    ./imgui/examples/libs/glfw/include
    ./imgui/examples/libs/gl3w/
  )


  set (FLECS_IMGUI_TESTBENCH_SRC
    ./testbench/main.cpp
  )

  add_executable(flecs_imgui_testbench ${FLECS_IMGUI_TESTBENCH_SRC} ${IMGUI_BACKEND_SRC})
  target_link_libraries(flecs_imgui_testbench flecs_imgui glfw opengl32.lib)

endif()

