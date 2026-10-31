cmake_minimum_required(VERSION 3.14.0)
project(ProjectLO21-A26 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/core)
include_directories(${CMAKE_SOURCE_DIR}/include/view)
include_directories(${CMAKE_SOURCE_DIR}/include/tools)

# Qt automatic processing settings
set(CMAKE_AUTOMOC ON) # Enable automatic MOC for Qt
set(CMAKE_AUTOUIC ON) # Enable automatic UIC for Qt
set(CMAKE_AUTORCC ON) # Enable automatic RCC for Qt

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ProjectLO21-A26 main.cpp 
src/core/card.cpp
src/core/face.cpp
src/core/board.cpp
src/view/consoleViewer.cpp
src/tools/generator.cpp
src/utils/json.cpp
src/core/player.cpp
src/core/condition.cpp)

target_link_libraries(ProjectLO21-A26 PRIVATE Qt6::Widgets)

