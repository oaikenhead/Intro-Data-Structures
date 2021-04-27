cmake_minimum_required(VERSION 2.8.9)
#-----------------------------------------------------------------------------

#Naming the project
project(proj10)

#-----------------------------------------------------------------------------

#Add subfolder named [include] to the list directories to be
include_directories(include)

#-----------------------------------------------------------------------------

#Rule for creating the project executable
add_executable(proj10 src/proj10.cpp)

#-----------------------------------------------------------------------------

#Specify any necessary linking for the above rule, against any other libraries
target_link_libraries(proj10)

#-----------------------------------------------------------------------------

#Specify where to place build products for a [make install] command
install(TARGETS proj10
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

#-----------------------------------------------------------------------------

#Copy the headers to install path
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

#-----------------------------------------------------------------------------
