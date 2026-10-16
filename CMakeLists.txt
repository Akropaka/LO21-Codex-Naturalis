cmake_minimum_required(VERSION 3.14.0)
project(ProjectLO21-A26 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/core)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

# Qt automatic processing settings
set(CMAKE_AUTOMOC ON) # Enable automatic MOC for Qt
set(CMAKE_AUTOUIC ON) # Enable automatic UIC for Qt
set(CMAKE_AUTORCC ON) # Enable automatic RCC for Qt

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ProjectLO21-A26 main.cpp 
src/core/card.cpp
src/core/face.cpp)

target_link_libraries(ProjectLO21-A26 PRIVATE nlohmann_json::nlohmann_json Qt6::Widgets)

include(CTest)
enable_testing()

