cmake_minimum_required(VERSION 3.19)






set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -lSDL2 -lSDL2_image -lSDL2_ttf")
project(PizzaLand)

add_executable(
  PizzaLand
  src/main.cpp
  src/Game.cpp
  src/Text.cpp
  src/Entity.cpp
)
