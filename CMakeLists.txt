cmake_minimum_required(VERSION 3.15...3.30)
set(CMAKE_TOOLCHAIN_FILE "D:/vcpkg-2025.12.12/scripts/buildsystems/vcpkg.cmake")

project(CPP_L2D_SDK_TEST VERSION 1.0)



find_package(glm CONFIG REQUIRED)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)




add_library(${PROJECT_NAME} STATIC
    src/core/math/package.cpp
    src/core/math/package.hpp
    src/core/math/trig.hpp
    src/core/math/range.hpp
    src/core/math/deform.hpp
    src/core/math/math.hpp
    src/core/math/transform.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm)
# target_include_directories(${PROJECT_NAME} PUBLIC 
# ${CMAKE_CURRENT_BINARY_DIR}/include
# )
