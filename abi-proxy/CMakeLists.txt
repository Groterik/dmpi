cmake_minimum_required (VERSION 2.6)

#Project name
set(PROJECT mpi_abi_proxy)

enable_testing()

project(${PROJECT})

#####################################
#  OPTIONS
#####################################

option(ENABLE_TRACES "Enable extra dubugging traces" OFF)
option(HAS_LONG_LONG "Support of MPI_LONG_LONG and MPI_UNSIGNED_LONG_LONG types" On)

#####################################
#  COMPILE SETTINGS
#####################################

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

find_package(MPI REQUIRED)
find_package(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})


if(MPI_INCLUDE_PATH)
    include_directories(${MPI_INCLUDE_PATH})
else()
    include_directories(${MPI_C_INCLUDE_PATH} ${MPI_CXX_INCLUDE_PATH})
endif()

#####################################
#  SOURCES
#####################################
set(SOURCES mpi_abi_proxy.h mpi_abi_proxy.cpp)

#####################################
#  Build project
#####################################
add_library(${PROJECT} SHARED ${SOURCES})

set_property(TARGET ${PROJECT} APPEND PROPERTY COMPILE_DEFINITIONS BUILDING_DLL)
if (ENABLE_TRACES)
    set_property(TARGET ${PROJECT} APPEND PROPERTY COMPILE_DEFINITIONS MPI_PROXY_WITH_TRACE)
endif()

target_link_libraries(${PROJECT} ${MPI_LIBRARY} ${MPI_EXTRA_LIBRARY} ${MPI_CXX_LIBRARIES})

set_property(TARGET ${PROJECT} PROPERTY PUBLIC_HEADER mpi_abi_proxy.h)

SET(CMAKE_SWIG_FLAGS "-d2")
SET_SOURCE_FILES_PROPERTIES(swig.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(swig.i PROPERTIES SWIG_FLAGS "-includeall")
SWIG_ADD_MODULE(${PROJECT}_swig d swig.i)
SWIG_LINK_LIBRARIES(${PROJECT}_swig ${PROJECT})

install(TARGETS ${PROJECT} ${PROJECT}_swig
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include)
