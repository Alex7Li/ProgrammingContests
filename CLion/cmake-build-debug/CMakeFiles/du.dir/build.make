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
include CMakeFiles/du.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/du.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/du.dir/flags.make

CMakeFiles/du.dir/Dungeon.cpp.obj: CMakeFiles/du.dir/flags.make
CMakeFiles/du.dir/Dungeon.cpp.obj: ../Dungeon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/du.dir/Dungeon.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\du.dir\Dungeon.cpp.obj -c "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\Dungeon.cpp"

CMakeFiles/du.dir/Dungeon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/du.dir/Dungeon.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\Dungeon.cpp" > CMakeFiles\du.dir\Dungeon.cpp.i

CMakeFiles/du.dir/Dungeon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/du.dir/Dungeon.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\Dungeon.cpp" -o CMakeFiles\du.dir\Dungeon.cpp.s

CMakeFiles/du.dir/BusyRobot.cpp.obj: CMakeFiles/du.dir/flags.make
CMakeFiles/du.dir/BusyRobot.cpp.obj: ../BusyRobot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/du.dir/BusyRobot.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\du.dir\BusyRobot.cpp.obj -c "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\BusyRobot.cpp"

CMakeFiles/du.dir/BusyRobot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/du.dir/BusyRobot.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\BusyRobot.cpp" > CMakeFiles\du.dir\BusyRobot.cpp.i

CMakeFiles/du.dir/BusyRobot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/du.dir/BusyRobot.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\BusyRobot.cpp" -o CMakeFiles\du.dir\BusyRobot.cpp.s

# Object files for target du
du_OBJECTS = \
"CMakeFiles/du.dir/Dungeon.cpp.obj" \
"CMakeFiles/du.dir/BusyRobot.cpp.obj"

# External object files for target du
du_EXTERNAL_OBJECTS =

du.exe: CMakeFiles/du.dir/Dungeon.cpp.obj
du.exe: CMakeFiles/du.dir/BusyRobot.cpp.obj
du.exe: CMakeFiles/du.dir/build.make
du.exe: CMakeFiles/du.dir/linklibs.rsp
du.exe: CMakeFiles/du.dir/objects1.rsp
du.exe: CMakeFiles/du.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable du.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\du.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/du.dir/build: du.exe

.PHONY : CMakeFiles/du.dir/build

CMakeFiles/du.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\du.dir\cmake_clean.cmake
.PHONY : CMakeFiles/du.dir/clean

CMakeFiles/du.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles\du.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/du.dir/depend

