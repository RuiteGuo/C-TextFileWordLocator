# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mbpro/CLionProjects/STAGE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mbpro/CLionProjects/STAGE/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/STAGE.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/STAGE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/STAGE.dir/flags.make

CMakeFiles/STAGE.dir/main.cpp.o: CMakeFiles/STAGE.dir/flags.make
CMakeFiles/STAGE.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mbpro/CLionProjects/STAGE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/STAGE.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/STAGE.dir/main.cpp.o -c /Users/mbpro/CLionProjects/STAGE/main.cpp

CMakeFiles/STAGE.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/STAGE.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mbpro/CLionProjects/STAGE/main.cpp > CMakeFiles/STAGE.dir/main.cpp.i

CMakeFiles/STAGE.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/STAGE.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mbpro/CLionProjects/STAGE/main.cpp -o CMakeFiles/STAGE.dir/main.cpp.s

CMakeFiles/STAGE.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/STAGE.dir/main.cpp.o.requires

CMakeFiles/STAGE.dir/main.cpp.o.provides: CMakeFiles/STAGE.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/STAGE.dir/build.make CMakeFiles/STAGE.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/STAGE.dir/main.cpp.o.provides

CMakeFiles/STAGE.dir/main.cpp.o.provides.build: CMakeFiles/STAGE.dir/main.cpp.o


# Object files for target STAGE
STAGE_OBJECTS = \
"CMakeFiles/STAGE.dir/main.cpp.o"

# External object files for target STAGE
STAGE_EXTERNAL_OBJECTS =

STAGE: CMakeFiles/STAGE.dir/main.cpp.o
STAGE: CMakeFiles/STAGE.dir/build.make
STAGE: CMakeFiles/STAGE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mbpro/CLionProjects/STAGE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable STAGE"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/STAGE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/STAGE.dir/build: STAGE

.PHONY : CMakeFiles/STAGE.dir/build

CMakeFiles/STAGE.dir/requires: CMakeFiles/STAGE.dir/main.cpp.o.requires

.PHONY : CMakeFiles/STAGE.dir/requires

CMakeFiles/STAGE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/STAGE.dir/cmake_clean.cmake
.PHONY : CMakeFiles/STAGE.dir/clean

CMakeFiles/STAGE.dir/depend:
	cd /Users/mbpro/CLionProjects/STAGE/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mbpro/CLionProjects/STAGE /Users/mbpro/CLionProjects/STAGE /Users/mbpro/CLionProjects/STAGE/cmake-build-debug /Users/mbpro/CLionProjects/STAGE/cmake-build-debug /Users/mbpro/CLionProjects/STAGE/cmake-build-debug/CMakeFiles/STAGE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/STAGE.dir/depend
