cmake_minimum_required(VERSION 3.15)
project(ConfigLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../LogLib/resources)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ConfigFileLib/resources)

include_directories(include/ConfigFileLib)

add_library(ConfigLib STATIC src/ConfigFile.cpp src/ConfigFilePrepare.cpp include/ConfigFileLib/ConfigFile.h include/ConfigFileLib/ConfigFilePrepare.h)
target_link_libraries(ConfigLib stdc++fs)

add_library(ConfigLibShared SHARED src/ConfigFile.cpp src/ConfigFilePrepare.cpp include/ConfigFileLib/ConfigFile.h include/ConfigFileLib/ConfigFilePrepare.h)
target_link_libraries(ConfigLibShared stdc++fs)

set_target_properties(ConfigLibShared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ConfigFileLib/resources)
set_target_properties(ConfigLibShared PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/ConfigFileLib/resources)

