cmake_minimum_required(VERSION 2.8.9)
#-----------------------------------------------------------------------------

#Naming the project
project(proj9)

#-----------------------------------------------------------------------------

#Add subfolder named [include] to the list directories to be
#considered for #include statements throughout the entire project
include_directories(include)

#-----------------------------------------------------------------------------

#Create a variable with source files for ArrayQueue
set(ARRAYQUEUE_SOURCES src/ArrayQueue/ArrayQueue.cpp)
#Create a library by compiling these files
add_library(ArrayQueue ${ARRAYQUEUE_SOURCES})

#-----------------------------------------------------------------------------

#Create a variable with the source files for DataType
set(DATATYPE_SOURCES src/DataType/DataType.cpp)
#Create a library by compiling these files
add_library(DataType ${DATATYPE_SOURCES})

#-----------------------------------------------------------------------------

#Create a variable with the source files for NodeQueue
set(NODEQUEUE_SOURCES src/NodeQueue/NodeQueue.cpp)
#Create a library by compiling these files
add_library(NodeQueue ${NODEQUEUE_SOURCES})

#-----------------------------------------------------------------------------

#Rule for creating the project executable
add_executable(proj9 src/proj9.cpp)

#-----------------------------------------------------------------------------

#Specify any necessary linking for the above rule, against any other libraries
target_link_libraries(proj9 ArrayQueue DataType NodeQueue)

#-----------------------------------------------------------------------------

#Specify where to place build products for a [make install] command
install(TARGETS proj9 ArrayQueue DataType NodeQueue
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

#-----------------------------------------------------------------------------

#Copy the headers to install path
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

#-----------------------------------------------------------------------------
