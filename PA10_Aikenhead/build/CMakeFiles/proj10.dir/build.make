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
CMAKE_SOURCE_DIR = /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/build

# Include any dependencies generated for this target.
include CMakeFiles/proj10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj10.dir/flags.make

CMakeFiles/proj10.dir/src/proj10.cpp.o: CMakeFiles/proj10.dir/flags.make
CMakeFiles/proj10.dir/src/proj10.cpp.o: ../src/proj10.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj10.dir/src/proj10.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj10.dir/src/proj10.cpp.o -c /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/src/proj10.cpp

CMakeFiles/proj10.dir/src/proj10.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj10.dir/src/proj10.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/src/proj10.cpp > CMakeFiles/proj10.dir/src/proj10.cpp.i

CMakeFiles/proj10.dir/src/proj10.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj10.dir/src/proj10.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/src/proj10.cpp -o CMakeFiles/proj10.dir/src/proj10.cpp.s

# Object files for target proj10
proj10_OBJECTS = \
"CMakeFiles/proj10.dir/src/proj10.cpp.o"

# External object files for target proj10
proj10_EXTERNAL_OBJECTS =

proj10: CMakeFiles/proj10.dir/src/proj10.cpp.o
proj10: CMakeFiles/proj10.dir/build.make
proj10: CMakeFiles/proj10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proj10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj10.dir/build: proj10

.PHONY : CMakeFiles/proj10.dir/build

CMakeFiles/proj10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj10.dir/clean

CMakeFiles/proj10.dir/depend:
	cd /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/build /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/build /home/sb/Projects/GitDirs/Intro-Data-Structures/PA10_Aikenhead/build/CMakeFiles/proj10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj10.dir/depend

