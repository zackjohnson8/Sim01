# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/zack/git-repos/Sim01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zack/git-repos/Sim01

# Include any dependencies generated for this target.
include CMakeFiles/sim01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sim01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sim01.dir/flags.make

CMakeFiles/sim01.dir/main.cpp.o: CMakeFiles/sim01.dir/flags.make
CMakeFiles/sim01.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zack/git-repos/Sim01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sim01.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim01.dir/main.cpp.o -c /home/zack/git-repos/Sim01/main.cpp

CMakeFiles/sim01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim01.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zack/git-repos/Sim01/main.cpp > CMakeFiles/sim01.dir/main.cpp.i

CMakeFiles/sim01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim01.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zack/git-repos/Sim01/main.cpp -o CMakeFiles/sim01.dir/main.cpp.s

CMakeFiles/sim01.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/sim01.dir/main.cpp.o.requires

CMakeFiles/sim01.dir/main.cpp.o.provides: CMakeFiles/sim01.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sim01.dir/build.make CMakeFiles/sim01.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/sim01.dir/main.cpp.o.provides

CMakeFiles/sim01.dir/main.cpp.o.provides.build: CMakeFiles/sim01.dir/main.cpp.o


CMakeFiles/sim01.dir/MetaDataFile.cpp.o: CMakeFiles/sim01.dir/flags.make
CMakeFiles/sim01.dir/MetaDataFile.cpp.o: MetaDataFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zack/git-repos/Sim01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sim01.dir/MetaDataFile.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim01.dir/MetaDataFile.cpp.o -c /home/zack/git-repos/Sim01/MetaDataFile.cpp

CMakeFiles/sim01.dir/MetaDataFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim01.dir/MetaDataFile.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zack/git-repos/Sim01/MetaDataFile.cpp > CMakeFiles/sim01.dir/MetaDataFile.cpp.i

CMakeFiles/sim01.dir/MetaDataFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim01.dir/MetaDataFile.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zack/git-repos/Sim01/MetaDataFile.cpp -o CMakeFiles/sim01.dir/MetaDataFile.cpp.s

CMakeFiles/sim01.dir/MetaDataFile.cpp.o.requires:

.PHONY : CMakeFiles/sim01.dir/MetaDataFile.cpp.o.requires

CMakeFiles/sim01.dir/MetaDataFile.cpp.o.provides: CMakeFiles/sim01.dir/MetaDataFile.cpp.o.requires
	$(MAKE) -f CMakeFiles/sim01.dir/build.make CMakeFiles/sim01.dir/MetaDataFile.cpp.o.provides.build
.PHONY : CMakeFiles/sim01.dir/MetaDataFile.cpp.o.provides

CMakeFiles/sim01.dir/MetaDataFile.cpp.o.provides.build: CMakeFiles/sim01.dir/MetaDataFile.cpp.o


CMakeFiles/sim01.dir/ConfigFile.cpp.o: CMakeFiles/sim01.dir/flags.make
CMakeFiles/sim01.dir/ConfigFile.cpp.o: ConfigFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zack/git-repos/Sim01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sim01.dir/ConfigFile.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim01.dir/ConfigFile.cpp.o -c /home/zack/git-repos/Sim01/ConfigFile.cpp

CMakeFiles/sim01.dir/ConfigFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim01.dir/ConfigFile.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zack/git-repos/Sim01/ConfigFile.cpp > CMakeFiles/sim01.dir/ConfigFile.cpp.i

CMakeFiles/sim01.dir/ConfigFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim01.dir/ConfigFile.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zack/git-repos/Sim01/ConfigFile.cpp -o CMakeFiles/sim01.dir/ConfigFile.cpp.s

CMakeFiles/sim01.dir/ConfigFile.cpp.o.requires:

.PHONY : CMakeFiles/sim01.dir/ConfigFile.cpp.o.requires

CMakeFiles/sim01.dir/ConfigFile.cpp.o.provides: CMakeFiles/sim01.dir/ConfigFile.cpp.o.requires
	$(MAKE) -f CMakeFiles/sim01.dir/build.make CMakeFiles/sim01.dir/ConfigFile.cpp.o.provides.build
.PHONY : CMakeFiles/sim01.dir/ConfigFile.cpp.o.provides

CMakeFiles/sim01.dir/ConfigFile.cpp.o.provides.build: CMakeFiles/sim01.dir/ConfigFile.cpp.o


CMakeFiles/sim01.dir/FileHandler.cpp.o: CMakeFiles/sim01.dir/flags.make
CMakeFiles/sim01.dir/FileHandler.cpp.o: FileHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zack/git-repos/Sim01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sim01.dir/FileHandler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sim01.dir/FileHandler.cpp.o -c /home/zack/git-repos/Sim01/FileHandler.cpp

CMakeFiles/sim01.dir/FileHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sim01.dir/FileHandler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zack/git-repos/Sim01/FileHandler.cpp > CMakeFiles/sim01.dir/FileHandler.cpp.i

CMakeFiles/sim01.dir/FileHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sim01.dir/FileHandler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zack/git-repos/Sim01/FileHandler.cpp -o CMakeFiles/sim01.dir/FileHandler.cpp.s

CMakeFiles/sim01.dir/FileHandler.cpp.o.requires:

.PHONY : CMakeFiles/sim01.dir/FileHandler.cpp.o.requires

CMakeFiles/sim01.dir/FileHandler.cpp.o.provides: CMakeFiles/sim01.dir/FileHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/sim01.dir/build.make CMakeFiles/sim01.dir/FileHandler.cpp.o.provides.build
.PHONY : CMakeFiles/sim01.dir/FileHandler.cpp.o.provides

CMakeFiles/sim01.dir/FileHandler.cpp.o.provides.build: CMakeFiles/sim01.dir/FileHandler.cpp.o


# Object files for target sim01
sim01_OBJECTS = \
"CMakeFiles/sim01.dir/main.cpp.o" \
"CMakeFiles/sim01.dir/MetaDataFile.cpp.o" \
"CMakeFiles/sim01.dir/ConfigFile.cpp.o" \
"CMakeFiles/sim01.dir/FileHandler.cpp.o"

# External object files for target sim01
sim01_EXTERNAL_OBJECTS =

sim01: CMakeFiles/sim01.dir/main.cpp.o
sim01: CMakeFiles/sim01.dir/MetaDataFile.cpp.o
sim01: CMakeFiles/sim01.dir/ConfigFile.cpp.o
sim01: CMakeFiles/sim01.dir/FileHandler.cpp.o
sim01: CMakeFiles/sim01.dir/build.make
sim01: CMakeFiles/sim01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zack/git-repos/Sim01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sim01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sim01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sim01.dir/build: sim01

.PHONY : CMakeFiles/sim01.dir/build

CMakeFiles/sim01.dir/requires: CMakeFiles/sim01.dir/main.cpp.o.requires
CMakeFiles/sim01.dir/requires: CMakeFiles/sim01.dir/MetaDataFile.cpp.o.requires
CMakeFiles/sim01.dir/requires: CMakeFiles/sim01.dir/ConfigFile.cpp.o.requires
CMakeFiles/sim01.dir/requires: CMakeFiles/sim01.dir/FileHandler.cpp.o.requires

.PHONY : CMakeFiles/sim01.dir/requires

CMakeFiles/sim01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sim01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sim01.dir/clean

CMakeFiles/sim01.dir/depend:
	cd /home/zack/git-repos/Sim01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zack/git-repos/Sim01 /home/zack/git-repos/Sim01 /home/zack/git-repos/Sim01 /home/zack/git-repos/Sim01 /home/zack/git-repos/Sim01/CMakeFiles/sim01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sim01.dir/depend

