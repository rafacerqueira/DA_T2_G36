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
CMAKE_COMMAND = /home/rafael/clion-2020.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/rafael/clion-2020.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rafael/2semestre/da/DA_T2_G36

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rafael/2semestre/da/DA_T2_G36/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DA_T2_G36.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DA_T2_G36.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DA_T2_G36.dir/flags.make

CMakeFiles/DA_T2_G36.dir/main.cpp.o: CMakeFiles/DA_T2_G36.dir/flags.make
CMakeFiles/DA_T2_G36.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rafael/2semestre/da/DA_T2_G36/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DA_T2_G36.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DA_T2_G36.dir/main.cpp.o -c /home/rafael/2semestre/da/DA_T2_G36/main.cpp

CMakeFiles/DA_T2_G36.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DA_T2_G36.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rafael/2semestre/da/DA_T2_G36/main.cpp > CMakeFiles/DA_T2_G36.dir/main.cpp.i

CMakeFiles/DA_T2_G36.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DA_T2_G36.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rafael/2semestre/da/DA_T2_G36/main.cpp -o CMakeFiles/DA_T2_G36.dir/main.cpp.s

# Object files for target DA_T2_G36
DA_T2_G36_OBJECTS = \
"CMakeFiles/DA_T2_G36.dir/main.cpp.o"

# External object files for target DA_T2_G36
DA_T2_G36_EXTERNAL_OBJECTS =

DA_T2_G36: CMakeFiles/DA_T2_G36.dir/main.cpp.o
DA_T2_G36: CMakeFiles/DA_T2_G36.dir/build.make
DA_T2_G36: CMakeFiles/DA_T2_G36.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rafael/2semestre/da/DA_T2_G36/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DA_T2_G36"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DA_T2_G36.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DA_T2_G36.dir/build: DA_T2_G36

.PHONY : CMakeFiles/DA_T2_G36.dir/build

CMakeFiles/DA_T2_G36.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DA_T2_G36.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DA_T2_G36.dir/clean

CMakeFiles/DA_T2_G36.dir/depend:
	cd /home/rafael/2semestre/da/DA_T2_G36/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafael/2semestre/da/DA_T2_G36 /home/rafael/2semestre/da/DA_T2_G36 /home/rafael/2semestre/da/DA_T2_G36/cmake-build-debug /home/rafael/2semestre/da/DA_T2_G36/cmake-build-debug /home/rafael/2semestre/da/DA_T2_G36/cmake-build-debug/CMakeFiles/DA_T2_G36.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DA_T2_G36.dir/depend

