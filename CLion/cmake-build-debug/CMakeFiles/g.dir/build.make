# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Alex Li\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Alex Li\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/g.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/g.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/g.dir/flags.make

CMakeFiles/g.dir/Global10/G.cpp.obj: CMakeFiles/g.dir/flags.make
CMakeFiles/g.dir/Global10/G.cpp.obj: ../Global10/G.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/g.dir/Global10/G.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\g.dir\Global10\G.cpp.obj -c "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\Global10\G.cpp"

CMakeFiles/g.dir/Global10/G.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/g.dir/Global10/G.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\Global10\G.cpp" > CMakeFiles\g.dir\Global10\G.cpp.i

CMakeFiles/g.dir/Global10/G.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/g.dir/Global10/G.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\Global10\G.cpp" -o CMakeFiles\g.dir\Global10\G.cpp.s

# Object files for target g
g_OBJECTS = \
"CMakeFiles/g.dir/Global10/G.cpp.obj"

# External object files for target g
g_EXTERNAL_OBJECTS =

g.exe: CMakeFiles/g.dir/Global10/G.cpp.obj
g.exe: CMakeFiles/g.dir/build.make
g.exe: CMakeFiles/g.dir/linklibs.rsp
g.exe: CMakeFiles/g.dir/objects1.rsp
g.exe: CMakeFiles/g.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable g.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\g.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/g.dir/build: g.exe

.PHONY : CMakeFiles/g.dir/build

CMakeFiles/g.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\g.dir\cmake_clean.cmake
.PHONY : CMakeFiles/g.dir/clean

CMakeFiles/g.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles\g.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/g.dir/depend

