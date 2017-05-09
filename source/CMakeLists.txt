cmake_minimum_required (VERSION 3.7)
# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  rectangel.cpp
  circel.cpp
    color.cpp
  Mat2.cpp)
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  test.cpp
  vec2.cpp
  Mat2.cpp
  rectangel.cpp
  circel.cpp
    color.cpp
  window.cpp
  glew.c)
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES})
add_dependencies(tests glfw nanovg ${COPY_BINARY})


