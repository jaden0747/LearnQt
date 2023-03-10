cmake_minimum_required(VERSION 3.17)

project(LearnQt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(QT_DIR "C:/Qt/")
list(APPEND CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64/lib/cmake")
find_package(Qt5 COMPONENTS Core Gui REQUIRED)

file(GLOB ANALOG_CLOCK_SOURCES ${PROJECT_SOURCE_DIR}/libs/AnalogClock/*)


# qt_standard_project_setup()

add_executable(${PROJECT_NAME}
    main.cpp
    ${ANALOG_CLOCK_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${Qt5_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui)