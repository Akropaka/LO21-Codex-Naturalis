cmake_minimum_required(VERSION 3.10.0)
project(ProjectLO21-A26 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Qt automatic processing settings
set(CMAKE_AUTOMOC ON) # Enable automatic MOC for Qt
set(CMAKE_AUTOUIC ON) # Enable automatic UIC for Qt
set(CMAKE_AUTORCC ON) # Enable automatic RCC for Qt

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ProjectLO21-A26 main.cpp src/core/card.cpp)
target_link_libraries(ProjectLO21-A26 Qt6::Widgets)

include(CTest)
enable_testing()

