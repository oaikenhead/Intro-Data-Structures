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
CMAKE_SOURCE_DIR = /home/ollie/CS/Computer-Science-II/PA05_Aikenhead

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ollie/CS/Computer-Science-II/PA05_Aikenhead/build

# Include any dependencies generated for this target.
include CMakeFiles/Vehicle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vehicle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vehicle.dir/flags.make

CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.o: CMakeFiles/Vehicle.dir/flags.make
CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.o: ../src/Vehicle/Vehicle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ollie/CS/Computer-Science-II/PA05_Aikenhead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.o -c /home/ollie/CS/Computer-Science-II/PA05_Aikenhead/src/Vehicle/Vehicle.cpp

CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ollie/CS/Computer-Science-II/PA05_Aikenhead/src/Vehicle/Vehicle.cpp > CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.i

CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ollie/CS/Computer-Science-II/PA05_Aikenhead/src/Vehicle/Vehicle.cpp -o CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.s

# Object files for target Vehicle
Vehicle_OBJECTS = \
"CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.o"

# External object files for target Vehicle
Vehicle_EXTERNAL_OBJECTS =

libVehicle.a: CMakeFiles/Vehicle.dir/src/Vehicle/Vehicle.cpp.o
libVehicle.a: CMakeFiles/Vehicle.dir/build.make
libVehicle.a: CMakeFiles/Vehicle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ollie/CS/Computer-Science-II/PA05_Aikenhead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libVehicle.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Vehicle.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vehicle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vehicle.dir/build: libVehicle.a

.PHONY : CMakeFiles/Vehicle.dir/build

CMakeFiles/Vehicle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vehicle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vehicle.dir/clean

CMakeFiles/Vehicle.dir/depend:
	cd /home/ollie/CS/Computer-Science-II/PA05_Aikenhead/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ollie/CS/Computer-Science-II/PA05_Aikenhead /home/ollie/CS/Computer-Science-II/PA05_Aikenhead /home/ollie/CS/Computer-Science-II/PA05_Aikenhead/build /home/ollie/CS/Computer-Science-II/PA05_Aikenhead/build /home/ollie/CS/Computer-Science-II/PA05_Aikenhead/build/CMakeFiles/Vehicle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vehicle.dir/depend

