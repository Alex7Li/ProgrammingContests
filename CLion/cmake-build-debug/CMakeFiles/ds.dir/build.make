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
CMAKE_COMMAND = "C:\Users\Alex Li\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Alex Li\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ds.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ds.dir/flags.make

CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.obj: CMakeFiles/ds.dir/flags.make
CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.obj: ../DangerOfMadSnakes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ds.dir\DangerOfMadSnakes.cpp.obj -c "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\DangerOfMadSnakes.cpp"

CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\DangerOfMadSnakes.cpp" > CMakeFiles\ds.dir\DangerOfMadSnakes.cpp.i

CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\DangerOfMadSnakes.cpp" -o CMakeFiles\ds.dir\DangerOfMadSnakes.cpp.s

# Object files for target ds
ds_OBJECTS = \
"CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.obj"

# External object files for target ds
ds_EXTERNAL_OBJECTS =

ds.exe: CMakeFiles/ds.dir/DangerOfMadSnakes.cpp.obj
ds.exe: CMakeFiles/ds.dir/build.make
ds.exe: CMakeFiles/ds.dir/linklibs.rsp
ds.exe: CMakeFiles/ds.dir/objects1.rsp
ds.exe: CMakeFiles/ds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ds.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ds.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ds.dir/build: ds.exe

.PHONY : CMakeFiles/ds.dir/build

CMakeFiles/ds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ds.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ds.dir/clean

CMakeFiles/ds.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles\ds.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ds.dir/depend

