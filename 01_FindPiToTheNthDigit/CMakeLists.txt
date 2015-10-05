cmake_minimum_required( VERSION 3.2 )

get_filename_component( PROJECT_FOLDER_NAME ${CMAKE_SOURCE_DIR} NAME )
string( REPLACE " " "_" ProjectId ${PROJECT_FOLDER_NAME} )
project( ${PROJECT_FOLDER_NAME} )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
set( SOURCE_FILES main.cpp )
add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )

include( FindPkgConfig )

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_HOME_DIRECTORY}/include ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/include )
