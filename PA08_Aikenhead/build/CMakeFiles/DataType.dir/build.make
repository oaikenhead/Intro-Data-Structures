# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ollie/CS/Computer-Science-II/PA08_Aikenhead

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ollie/CS/Computer-Science-II/PA08_Aikenhead/build

# Include any dependencies generated for this target.
include CMakeFiles/DataType.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataType.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataType.dir/flags.make

CMakeFiles/DataType.dir/src/DataType/DataType.cpp.o: CMakeFiles/DataType.dir/flags.make
CMakeFiles/DataType.dir/src/DataType/DataType.cpp.o: ../src/DataType/DataType.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ollie/CS/Computer-Science-II/PA08_Aikenhead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataType.dir/src/DataType/DataType.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataType.dir/src/DataType/DataType.cpp.o -c /home/ollie/CS/Computer-Science-II/PA08_Aikenhead/src/DataType/DataType.cpp

CMakeFiles/DataType.dir/src/DataType/DataType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataType.dir/src/DataType/DataType.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ollie/CS/Computer-Science-II/PA08_Aikenhead/src/DataType/DataType.cpp > CMakeFiles/DataType.dir/src/DataType/DataType.cpp.i

CMakeFiles/DataType.dir/src/DataType/DataType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataType.dir/src/DataType/DataType.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ollie/CS/Computer-Science-II/PA08_Aikenhead/src/DataType/DataType.cpp -o CMakeFiles/DataType.dir/src/DataType/DataType.cpp.s

# Object files for target DataType
DataType_OBJECTS = \
"CMakeFiles/DataType.dir/src/DataType/DataType.cpp.o"

# External object files for target DataType
DataType_EXTERNAL_OBJECTS =

libDataType.a: CMakeFiles/DataType.dir/src/DataType/DataType.cpp.o
libDataType.a: CMakeFiles/DataType.dir/build.make
libDataType.a: CMakeFiles/DataType.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ollie/CS/Computer-Science-II/PA08_Aikenhead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libDataType.a"
	$(CMAKE_COMMAND) -P CMakeFiles/DataType.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataType.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataType.dir/build: libDataType.a

.PHONY : CMakeFiles/DataType.dir/build

CMakeFiles/DataType.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataType.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataType.dir/clean

CMakeFiles/DataType.dir/depend:
	cd /home/ollie/CS/Computer-Science-II/PA08_Aikenhead/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ollie/CS/Computer-Science-II/PA08_Aikenhead /home/ollie/CS/Computer-Science-II/PA08_Aikenhead /home/ollie/CS/Computer-Science-II/PA08_Aikenhead/build /home/ollie/CS/Computer-Science-II/PA08_Aikenhead/build /home/ollie/CS/Computer-Science-II/PA08_Aikenhead/build/CMakeFiles/DataType.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataType.dir/depend

