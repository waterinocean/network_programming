# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leo/code/cplus/01_network_programming/linux/01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leo/code/cplus/01_network_programming/linux/01/build

# Include any dependencies generated for this target.
include CMakeFiles/c_copy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/c_copy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/c_copy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c_copy.dir/flags.make

CMakeFiles/c_copy.dir/c_copy.cpp.o: CMakeFiles/c_copy.dir/flags.make
CMakeFiles/c_copy.dir/c_copy.cpp.o: ../c_copy.cpp
CMakeFiles/c_copy.dir/c_copy.cpp.o: CMakeFiles/c_copy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/code/cplus/01_network_programming/linux/01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c_copy.dir/c_copy.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/c_copy.dir/c_copy.cpp.o -MF CMakeFiles/c_copy.dir/c_copy.cpp.o.d -o CMakeFiles/c_copy.dir/c_copy.cpp.o -c /home/leo/code/cplus/01_network_programming/linux/01/c_copy.cpp

CMakeFiles/c_copy.dir/c_copy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c_copy.dir/c_copy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/code/cplus/01_network_programming/linux/01/c_copy.cpp > CMakeFiles/c_copy.dir/c_copy.cpp.i

CMakeFiles/c_copy.dir/c_copy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c_copy.dir/c_copy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/code/cplus/01_network_programming/linux/01/c_copy.cpp -o CMakeFiles/c_copy.dir/c_copy.cpp.s

# Object files for target c_copy
c_copy_OBJECTS = \
"CMakeFiles/c_copy.dir/c_copy.cpp.o"

# External object files for target c_copy
c_copy_EXTERNAL_OBJECTS =

../bin/c_copy: CMakeFiles/c_copy.dir/c_copy.cpp.o
../bin/c_copy: CMakeFiles/c_copy.dir/build.make
../bin/c_copy: CMakeFiles/c_copy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leo/code/cplus/01_network_programming/linux/01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/c_copy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c_copy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c_copy.dir/build: ../bin/c_copy
.PHONY : CMakeFiles/c_copy.dir/build

CMakeFiles/c_copy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c_copy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c_copy.dir/clean

CMakeFiles/c_copy.dir/depend:
	cd /home/leo/code/cplus/01_network_programming/linux/01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leo/code/cplus/01_network_programming/linux/01 /home/leo/code/cplus/01_network_programming/linux/01 /home/leo/code/cplus/01_network_programming/linux/01/build /home/leo/code/cplus/01_network_programming/linux/01/build /home/leo/code/cplus/01_network_programming/linux/01/build/CMakeFiles/c_copy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c_copy.dir/depend
