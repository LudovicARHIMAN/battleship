# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = /home/kali/Desktop/battleship/bnv3.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kali/Desktop/battleship/bnv3.1

# Include any dependencies generated for this target.
include src/CMakeFiles/SERVEUR.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/SERVEUR.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/SERVEUR.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/SERVEUR.dir/flags.make

src/CMakeFiles/SERVEUR.dir/serveur.c.o: src/CMakeFiles/SERVEUR.dir/flags.make
src/CMakeFiles/SERVEUR.dir/serveur.c.o: src/serveur.c
src/CMakeFiles/SERVEUR.dir/serveur.c.o: src/CMakeFiles/SERVEUR.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kali/Desktop/battleship/bnv3.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/SERVEUR.dir/serveur.c.o"
	cd /home/kali/Desktop/battleship/bnv3.1/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/SERVEUR.dir/serveur.c.o -MF CMakeFiles/SERVEUR.dir/serveur.c.o.d -o CMakeFiles/SERVEUR.dir/serveur.c.o -c /home/kali/Desktop/battleship/bnv3.1/src/serveur.c

src/CMakeFiles/SERVEUR.dir/serveur.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SERVEUR.dir/serveur.c.i"
	cd /home/kali/Desktop/battleship/bnv3.1/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kali/Desktop/battleship/bnv3.1/src/serveur.c > CMakeFiles/SERVEUR.dir/serveur.c.i

src/CMakeFiles/SERVEUR.dir/serveur.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SERVEUR.dir/serveur.c.s"
	cd /home/kali/Desktop/battleship/bnv3.1/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kali/Desktop/battleship/bnv3.1/src/serveur.c -o CMakeFiles/SERVEUR.dir/serveur.c.s

# Object files for target SERVEUR
SERVEUR_OBJECTS = \
"CMakeFiles/SERVEUR.dir/serveur.c.o"

# External object files for target SERVEUR
SERVEUR_EXTERNAL_OBJECTS =

exe/SERVEUR: src/CMakeFiles/SERVEUR.dir/serveur.c.o
exe/SERVEUR: src/CMakeFiles/SERVEUR.dir/build.make
exe/SERVEUR: library/libmylib.a
exe/SERVEUR: src/CMakeFiles/SERVEUR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kali/Desktop/battleship/bnv3.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../exe/SERVEUR"
	cd /home/kali/Desktop/battleship/bnv3.1/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SERVEUR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/SERVEUR.dir/build: exe/SERVEUR
.PHONY : src/CMakeFiles/SERVEUR.dir/build

src/CMakeFiles/SERVEUR.dir/clean:
	cd /home/kali/Desktop/battleship/bnv3.1/src && $(CMAKE_COMMAND) -P CMakeFiles/SERVEUR.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/SERVEUR.dir/clean

src/CMakeFiles/SERVEUR.dir/depend:
	cd /home/kali/Desktop/battleship/bnv3.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kali/Desktop/battleship/bnv3.1 /home/kali/Desktop/battleship/bnv3.1/src /home/kali/Desktop/battleship/bnv3.1 /home/kali/Desktop/battleship/bnv3.1/src /home/kali/Desktop/battleship/bnv3.1/src/CMakeFiles/SERVEUR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/SERVEUR.dir/depend

