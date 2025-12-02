cmake_minimum_required(VERSION 3.13)
project(indi_sv241 CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find INDI using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(INDI REQUIRED libindi)

# Include directories
include_directories(${INDI_INCLUDE_DIRS})
link_directories(${INDI_LIBRARY_DIRS})

# Set source files
set(SV241_SOURCES
    indi_sv241.cpp
)

# Build the driver
add_executable(indi_sv241 ${SV241_SOURCES})

# Link libraries - need indidriver for driver development
target_link_libraries(indi_sv241
    indidriver
    ${INDI_LIBRARIES}
)

# Install the driver
install(TARGETS indi_sv241 RUNTIME DESTINATION bin)

# Install the XML driver description
set(INDI_DATA_DIR "/usr/local/share/indi")
install(FILES indi_sv241.xml DESTINATION ${INDI_DATA_DIR})

# Print configuration summary
message(STATUS "")
message(STATUS "SVBONY SV241 INDI Driver Configuration:")
message(STATUS "  INDI include dirs: ${INDI_INCLUDE_DIRS}")
message(STATUS "  INDI libraries: ${INDI_LIBRARIES}")
message(STATUS "  INDI library dirs: ${INDI_LIBRARY_DIRS}")
message(STATUS "  INDI data dir: ${INDI_DATA_DIR}")
message(STATUS "  Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "")
