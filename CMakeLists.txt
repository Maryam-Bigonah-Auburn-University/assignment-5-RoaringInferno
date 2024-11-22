cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(assignment-5)

add_executable(exercise-1)
file(GLOB_RECURSE EXERCISE_1_SOURCES "exercise-1/*.cpp")
target_sources(exercise-1 PRIVATE ${EXERCISE_1_SOURCES})

add_executable(exercise-2)
file(GLOB_RECURSE EXERCISE_2_SOURCES "exercise-2/*.cpp")
target_sources(exercise-2 PRIVATE ${EXERCISE_2_SOURCES})

#add_executable(exercise-3)
#file(GLOB_RECURSE EXERCISE_3_SOURCES "exercise-3/*.cpp")
#target_sources(exercise-3 PRIVATE ${EXERCISE_3_SOURCES})