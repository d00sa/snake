cmake_minimum_required(VERSION 3.20)
project(Test VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
set(CURSES_INCLUDE_PATH "C:/MinGW/include/ncursesw")
set(CURSES_LIBRARY "C:/MinGW/lib/libncursesw.a")

include_directories(${CURSES_INCLUDE_PATH})
include_directories(${CMAKE_SOURCE_DIR})
link_libraries(${CURSES_LIBRARY})

file(GLOB PROJ_SRC "*.h" "*.cpp")
add_executable(${PROJECT_NAME} ${PROJ_SRC})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)