set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG -g)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
add_executable(DishMain main.cpp Dish.cpp)
