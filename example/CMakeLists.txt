cmake_minimum_required(VERSION 2.8)

project (Laboratory-work-7-sem2_example)
set(SOURCES main.cpp)
add_executable (${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Laboratory-work-7-sem2)