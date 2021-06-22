project(exer CXX)
add_executable(exer2 exer2.cpp ../exer3/exer3.cpp)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")