# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /home/shadowleaf/OpenMP/assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shadowleaf/OpenMP/assignment/build

# Include any dependencies generated for this target.
include CMakeFiles/MatMul.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MatMul.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MatMul.dir/flags.make

CMakeFiles/MatMul.dir/main.cpp.o: CMakeFiles/MatMul.dir/flags.make
CMakeFiles/MatMul.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shadowleaf/OpenMP/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MatMul.dir/main.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MatMul.dir/main.cpp.o -c /home/shadowleaf/OpenMP/assignment/main.cpp

CMakeFiles/MatMul.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MatMul.dir/main.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadowleaf/OpenMP/assignment/main.cpp > CMakeFiles/MatMul.dir/main.cpp.i

CMakeFiles/MatMul.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MatMul.dir/main.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadowleaf/OpenMP/assignment/main.cpp -o CMakeFiles/MatMul.dir/main.cpp.s

CMakeFiles/MatMul.dir/MatMul.cpp.o: CMakeFiles/MatMul.dir/flags.make
CMakeFiles/MatMul.dir/MatMul.cpp.o: ../MatMul.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shadowleaf/OpenMP/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MatMul.dir/MatMul.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MatMul.dir/MatMul.cpp.o -c /home/shadowleaf/OpenMP/assignment/MatMul.cpp

CMakeFiles/MatMul.dir/MatMul.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MatMul.dir/MatMul.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shadowleaf/OpenMP/assignment/MatMul.cpp > CMakeFiles/MatMul.dir/MatMul.cpp.i

CMakeFiles/MatMul.dir/MatMul.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MatMul.dir/MatMul.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shadowleaf/OpenMP/assignment/MatMul.cpp -o CMakeFiles/MatMul.dir/MatMul.cpp.s

# Object files for target MatMul
MatMul_OBJECTS = \
"CMakeFiles/MatMul.dir/main.cpp.o" \
"CMakeFiles/MatMul.dir/MatMul.cpp.o"

# External object files for target MatMul
MatMul_EXTERNAL_OBJECTS =

MatMul: CMakeFiles/MatMul.dir/main.cpp.o
MatMul: CMakeFiles/MatMul.dir/MatMul.cpp.o
MatMul: CMakeFiles/MatMul.dir/build.make
MatMul: CMakeFiles/MatMul.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shadowleaf/OpenMP/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MatMul"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MatMul.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MatMul.dir/build: MatMul

.PHONY : CMakeFiles/MatMul.dir/build

CMakeFiles/MatMul.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MatMul.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MatMul.dir/clean

CMakeFiles/MatMul.dir/depend:
	cd /home/shadowleaf/OpenMP/assignment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shadowleaf/OpenMP/assignment /home/shadowleaf/OpenMP/assignment /home/shadowleaf/OpenMP/assignment/build /home/shadowleaf/OpenMP/assignment/build /home/shadowleaf/OpenMP/assignment/build/CMakeFiles/MatMul.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MatMul.dir/depend

