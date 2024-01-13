cmake_minimum_required(VERSION 3.12.4)
project(lvgl_sim_v8.2.0 VERSION 1.0.0)

add_definitions(-DUSE_SDL)

include_directories(app)
include_directories(porting)

add_subdirectory("lvgl")
add_subdirectory("lv_drivers")
file(GLOB_RECURSE SRC ./app/*.c ./porting/*.c)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} lvgl)
target_link_libraries(${PROJECT_NAME} lv_drivers)
target_link_libraries(${PROJECT_NAME} mingw32)
target_link_libraries(${PROJECT_NAME} SDL2main)
target_link_libraries(${PROJECT_NAME} SDL2)

file(COPY SDL2.dll DESTINATION build)
