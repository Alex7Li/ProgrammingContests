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
include CMakeFiles/lava.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lava.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lava.dir/flags.make

CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.obj: CMakeFiles/lava.dir/flags.make
CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.obj: ../RegionalsPractice4/Lava.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lava.dir\RegionalsPractice4\Lava.cpp.obj -c "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\RegionalsPractice4\Lava.cpp"

CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\RegionalsPractice4\Lava.cpp" > CMakeFiles\lava.dir\RegionalsPractice4\Lava.cpp.i

CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\RegionalsPractice4\Lava.cpp" -o CMakeFiles\lava.dir\RegionalsPractice4\Lava.cpp.s

CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.obj: CMakeFiles/lava.dir/flags.make
CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.obj: ../RegionalsPractice4/Toys.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lava.dir\RegionalsPractice4\Toys.cpp.obj -c "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\RegionalsPractice4\Toys.cpp"

CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\RegionalsPractice4\Toys.cpp" > CMakeFiles\lava.dir\RegionalsPractice4\Toys.cpp.i

CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\RegionalsPractice4\Toys.cpp" -o CMakeFiles\lava.dir\RegionalsPractice4\Toys.cpp.s

# Object files for target lava
lava_OBJECTS = \
"CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.obj" \
"CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.obj"

# External object files for target lava
lava_EXTERNAL_OBJECTS =

lava.exe: CMakeFiles/lava.dir/RegionalsPractice4/Lava.cpp.obj
lava.exe: CMakeFiles/lava.dir/RegionalsPractice4/Toys.cpp.obj
lava.exe: CMakeFiles/lava.dir/build.make
lava.exe: CMakeFiles/lava.dir/linklibs.rsp
lava.exe: CMakeFiles/lava.dir/objects1.rsp
lava.exe: CMakeFiles/lava.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lava.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lava.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lava.dir/build: lava.exe

.PHONY : CMakeFiles/lava.dir/build

CMakeFiles/lava.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lava.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lava.dir/clean

CMakeFiles/lava.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug" "C:\Users\Alex Li\CLionProjects\ProgrammingContests\CLion\cmake-build-debug\CMakeFiles\lava.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lava.dir/depend

