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
CMAKE_COMMAND = /snap/clion/114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/114/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/extremer/Projects/fh/bes/VehicleTestGrid

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/extremer/Projects/fh/bes/VehicleTestGrid

# Include any dependencies generated for this target.
include CMakeFiles/vehicleclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vehicleclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vehicleclient.dir/flags.make

CMakeFiles/vehicleclient.dir/client/main.cpp.o: CMakeFiles/vehicleclient.dir/flags.make
CMakeFiles/vehicleclient.dir/client/main.cpp.o: client/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/extremer/Projects/fh/bes/VehicleTestGrid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vehicleclient.dir/client/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vehicleclient.dir/client/main.cpp.o -c /home/extremer/Projects/fh/bes/VehicleTestGrid/client/main.cpp

CMakeFiles/vehicleclient.dir/client/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vehicleclient.dir/client/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/extremer/Projects/fh/bes/VehicleTestGrid/client/main.cpp > CMakeFiles/vehicleclient.dir/client/main.cpp.i

CMakeFiles/vehicleclient.dir/client/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vehicleclient.dir/client/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/extremer/Projects/fh/bes/VehicleTestGrid/client/main.cpp -o CMakeFiles/vehicleclient.dir/client/main.cpp.s

# Object files for target vehicleclient
vehicleclient_OBJECTS = \
"CMakeFiles/vehicleclient.dir/client/main.cpp.o"

# External object files for target vehicleclient
vehicleclient_EXTERNAL_OBJECTS =

vehicleclient: CMakeFiles/vehicleclient.dir/client/main.cpp.o
vehicleclient: CMakeFiles/vehicleclient.dir/build.make
vehicleclient: CMakeFiles/vehicleclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/extremer/Projects/fh/bes/VehicleTestGrid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vehicleclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vehicleclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vehicleclient.dir/build: vehicleclient

.PHONY : CMakeFiles/vehicleclient.dir/build

CMakeFiles/vehicleclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vehicleclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vehicleclient.dir/clean

CMakeFiles/vehicleclient.dir/depend:
	cd /home/extremer/Projects/fh/bes/VehicleTestGrid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/extremer/Projects/fh/bes/VehicleTestGrid /home/extremer/Projects/fh/bes/VehicleTestGrid /home/extremer/Projects/fh/bes/VehicleTestGrid /home/extremer/Projects/fh/bes/VehicleTestGrid /home/extremer/Projects/fh/bes/VehicleTestGrid/CMakeFiles/vehicleclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vehicleclient.dir/depend

