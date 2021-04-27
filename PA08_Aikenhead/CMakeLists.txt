cmake_minimum_required(VERSION 2.8.9)
#-----------------------------------------------------------------------------

#Naming the project
project(proj8)

#-----------------------------------------------------------------------------

#Add subfolder named [include] to the list directories to be
#considered for #include statements throughout the entire project
include_directories(include)

#-----------------------------------------------------------------------------

#Create a variable with source files for ArrayList
set(ARRAYLIST_SOURCES src/ArrayList/ArrayList.cpp)
#Create a library by compiling these files
add_library(ArrayList ${ARRAYLIST_SOURCES})

#-----------------------------------------------------------------------------

#Create a variable with the source files for DataType
set(DATATYPE_SOURCES src/DataType/DataType.cpp)
#Create a library by compiling these files
add_library(DataType ${DATATYPE_SOURCES})

#-----------------------------------------------------------------------------

#Create a variable with the source files for NodeList
set(NODELIST_SOURCES src/NodeList/NodeList.cpp)
#Create a library by compiling these files
add_library(NodeList ${NODELIST_SOURCES})

#-----------------------------------------------------------------------------

#Rule for creating the project executable
add_executable(proj8 src/proj8.cpp)

#-----------------------------------------------------------------------------

#Specify any necessary linking for the above rule, against any other libraries
target_link_libraries(proj8 ArrayList DataType NodeList)

#-----------------------------------------------------------------------------

#Specify where to place build products for a [make install] command
install(TARGETS proj8 ArrayList DataType NodeList
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

#-----------------------------------------------------------------------------

#Copy the headers to install path
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

#-----------------------------------------------------------------------------
