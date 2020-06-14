# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /snap/cmake/372/bin/cmake

# The command to remove a file.
RM = /snap/cmake/372/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/extremer/Projects/fh/SS, 2020/bes/VehicleTestGrid"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/extremer/Projects/fh/SS, 2020/bes/VehicleTestGrid"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/snap/cmake/372/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/cmake/372/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/extremer/Projects/fh/SS, 2020/bes/VehicleTestGrid/CMakeFiles" "/home/extremer/Projects/fh/SS, 2020/bes/VehicleTestGrid/CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/extremer/Projects/fh/SS, 2020/bes/VehicleTestGrid/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named griddisplay

# Build rule for target.
griddisplay: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 griddisplay
.PHONY : griddisplay

# fast build rule for target.
griddisplay/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/griddisplay.dir/build.make CMakeFiles/griddisplay.dir/build
.PHONY : griddisplay/fast

#=============================================================================
# Target rules for targets named gridserver

# Build rule for target.
gridserver: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gridserver
.PHONY : gridserver

# fast build rule for target.
gridserver/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/build
.PHONY : gridserver/fast

#=============================================================================
# Target rules for targets named vehicleclient

# Build rule for target.
vehicleclient: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 vehicleclient
.PHONY : vehicleclient

# fast build rule for target.
vehicleclient/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/vehicleclient.dir/build.make CMakeFiles/vehicleclient.dir/build
.PHONY : vehicleclient/fast

client/main.o: client/main.cpp.o

.PHONY : client/main.o

# target to build an object file
client/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/vehicleclient.dir/build.make CMakeFiles/vehicleclient.dir/client/main.cpp.o
.PHONY : client/main.cpp.o

client/main.i: client/main.cpp.i

.PHONY : client/main.i

# target to preprocess a source file
client/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/vehicleclient.dir/build.make CMakeFiles/vehicleclient.dir/client/main.cpp.i
.PHONY : client/main.cpp.i

client/main.s: client/main.cpp.s

.PHONY : client/main.s

# target to generate assembly for a file
client/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/vehicleclient.dir/build.make CMakeFiles/vehicleclient.dir/client/main.cpp.s
.PHONY : client/main.cpp.s

display/display_main.o: display/display_main.cpp.o

.PHONY : display/display_main.o

# target to build an object file
display/display_main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/griddisplay.dir/build.make CMakeFiles/griddisplay.dir/display/display_main.cpp.o
.PHONY : display/display_main.cpp.o

display/display_main.i: display/display_main.cpp.i

.PHONY : display/display_main.i

# target to preprocess a source file
display/display_main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/griddisplay.dir/build.make CMakeFiles/griddisplay.dir/display/display_main.cpp.i
.PHONY : display/display_main.cpp.i

display/display_main.s: display/display_main.cpp.s

.PHONY : display/display_main.s

# target to generate assembly for a file
display/display_main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/griddisplay.dir/build.make CMakeFiles/griddisplay.dir/display/display_main.cpp.s
.PHONY : display/display_main.cpp.s

server/RaceField.o: server/RaceField.cpp.o

.PHONY : server/RaceField.o

# target to build an object file
server/RaceField.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/RaceField.cpp.o
.PHONY : server/RaceField.cpp.o

server/RaceField.i: server/RaceField.cpp.i

.PHONY : server/RaceField.i

# target to preprocess a source file
server/RaceField.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/RaceField.cpp.i
.PHONY : server/RaceField.cpp.i

server/RaceField.s: server/RaceField.cpp.s

.PHONY : server/RaceField.s

# target to generate assembly for a file
server/RaceField.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/RaceField.cpp.s
.PHONY : server/RaceField.cpp.s

server/Server.o: server/Server.cpp.o

.PHONY : server/Server.o

# target to build an object file
server/Server.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/Server.cpp.o
.PHONY : server/Server.cpp.o

server/Server.i: server/Server.cpp.i

.PHONY : server/Server.i

# target to preprocess a source file
server/Server.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/Server.cpp.i
.PHONY : server/Server.cpp.i

server/Server.s: server/Server.cpp.s

.PHONY : server/Server.s

# target to generate assembly for a file
server/Server.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/Server.cpp.s
.PHONY : server/Server.cpp.s

server/StringUtil.o: server/StringUtil.cpp.o

.PHONY : server/StringUtil.o

# target to build an object file
server/StringUtil.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/StringUtil.cpp.o
.PHONY : server/StringUtil.cpp.o

server/StringUtil.i: server/StringUtil.cpp.i

.PHONY : server/StringUtil.i

# target to preprocess a source file
server/StringUtil.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/StringUtil.cpp.i
.PHONY : server/StringUtil.cpp.i

server/StringUtil.s: server/StringUtil.cpp.s

.PHONY : server/StringUtil.s

# target to generate assembly for a file
server/StringUtil.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/StringUtil.cpp.s
.PHONY : server/StringUtil.cpp.s

server/main.o: server/main.cpp.o

.PHONY : server/main.o

# target to build an object file
server/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/main.cpp.o
.PHONY : server/main.cpp.o

server/main.i: server/main.cpp.i

.PHONY : server/main.i

# target to preprocess a source file
server/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/main.cpp.i
.PHONY : server/main.cpp.i

server/main.s: server/main.cpp.s

.PHONY : server/main.s

# target to generate assembly for a file
server/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/gridserver.dir/build.make CMakeFiles/gridserver.dir/server/main.cpp.s
.PHONY : server/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... griddisplay"
	@echo "... gridserver"
	@echo "... vehicleclient"
	@echo "... client/main.o"
	@echo "... client/main.i"
	@echo "... client/main.s"
	@echo "... display/display_main.o"
	@echo "... display/display_main.i"
	@echo "... display/display_main.s"
	@echo "... server/RaceField.o"
	@echo "... server/RaceField.i"
	@echo "... server/RaceField.s"
	@echo "... server/Server.o"
	@echo "... server/Server.i"
	@echo "... server/Server.s"
	@echo "... server/StringUtil.o"
	@echo "... server/StringUtil.i"
	@echo "... server/StringUtil.s"
	@echo "... server/main.o"
	@echo "... server/main.i"
	@echo "... server/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

