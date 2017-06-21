cmake_minimum_required (VERSION 3.2)
project (stan-config)

include(CTest)
include(ExternalProject)

set (CMAKE_CXX_STANDARD 11)

set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
include(DownloadProject.cmake)

# Boost
#add_subdirectory(boost)

# Google test framework
add_subdirectory(googletest)

add_subdirectory(src)

# Stan math library
#message("Getting Stan math library.")
#add_subdirectory(stan-math)

# Stan algorithms and language compiler
#message("Getting Stan language and algorithms.")
#add_subdirectory(stan)


