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
CMAKE_SOURCE_DIR = /home/ollie/CS/Computer-Science-II/PA09_Aikenhead

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ollie/CS/Computer-Science-II/PA09_Aikenhead/build

# Include any dependencies generated for this target.
include CMakeFiles/ArrayQueue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ArrayQueue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ArrayQueue.dir/flags.make

CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.o: CMakeFiles/ArrayQueue.dir/flags.make
CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.o: ../src/ArrayQueue/ArrayQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ollie/CS/Computer-Science-II/PA09_Aikenhead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.o -c /home/ollie/CS/Computer-Science-II/PA09_Aikenhead/src/ArrayQueue/ArrayQueue.cpp

CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ollie/CS/Computer-Science-II/PA09_Aikenhead/src/ArrayQueue/ArrayQueue.cpp > CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.i

CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ollie/CS/Computer-Science-II/PA09_Aikenhead/src/ArrayQueue/ArrayQueue.cpp -o CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.s

# Object files for target ArrayQueue
ArrayQueue_OBJECTS = \
"CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.o"

# External object files for target ArrayQueue
ArrayQueue_EXTERNAL_OBJECTS =

libArrayQueue.a: CMakeFiles/ArrayQueue.dir/src/ArrayQueue/ArrayQueue.cpp.o
libArrayQueue.a: CMakeFiles/ArrayQueue.dir/build.make
libArrayQueue.a: CMakeFiles/ArrayQueue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ollie/CS/Computer-Science-II/PA09_Aikenhead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libArrayQueue.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ArrayQueue.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ArrayQueue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ArrayQueue.dir/build: libArrayQueue.a

.PHONY : CMakeFiles/ArrayQueue.dir/build

CMakeFiles/ArrayQueue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ArrayQueue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ArrayQueue.dir/clean

CMakeFiles/ArrayQueue.dir/depend:
	cd /home/ollie/CS/Computer-Science-II/PA09_Aikenhead/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ollie/CS/Computer-Science-II/PA09_Aikenhead /home/ollie/CS/Computer-Science-II/PA09_Aikenhead /home/ollie/CS/Computer-Science-II/PA09_Aikenhead/build /home/ollie/CS/Computer-Science-II/PA09_Aikenhead/build /home/ollie/CS/Computer-Science-II/PA09_Aikenhead/build/CMakeFiles/ArrayQueue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ArrayQueue.dir/depend
