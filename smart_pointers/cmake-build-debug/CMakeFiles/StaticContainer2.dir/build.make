# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\pawel\AppData\Local\Programs\CLion Nova\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\pawel\AppData\Local\Programs\CLion Nova\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StaticContainer2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/StaticContainer2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/StaticContainer2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StaticContainer2.dir/flags.make

CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.obj: CMakeFiles/StaticContainer2.dir/flags.make
CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.obj: C:/Users/pawel/Documents/studia/6semestr/CPP/emcpp-assignments/smart_pointers/Ex2_StaticContainer2.cpp
CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.obj: CMakeFiles/StaticContainer2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.obj"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.obj -MF CMakeFiles\StaticContainer2.dir\Ex2_StaticContainer2.cpp.obj.d -o CMakeFiles\StaticContainer2.dir\Ex2_StaticContainer2.cpp.obj -c C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\Ex2_StaticContainer2.cpp

CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.i"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\Ex2_StaticContainer2.cpp > CMakeFiles\StaticContainer2.dir\Ex2_StaticContainer2.cpp.i

CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.s"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\Ex2_StaticContainer2.cpp -o CMakeFiles\StaticContainer2.dir\Ex2_StaticContainer2.cpp.s

# Object files for target StaticContainer2
StaticContainer2_OBJECTS = \
"CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.obj"

# External object files for target StaticContainer2
StaticContainer2_EXTERNAL_OBJECTS =

StaticContainer2.exe: CMakeFiles/StaticContainer2.dir/Ex2_StaticContainer2.cpp.obj
StaticContainer2.exe: CMakeFiles/StaticContainer2.dir/build.make
StaticContainer2.exe: CMakeFiles/StaticContainer2.dir/linkLibs.rsp
StaticContainer2.exe: CMakeFiles/StaticContainer2.dir/objects1.rsp
StaticContainer2.exe: CMakeFiles/StaticContainer2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StaticContainer2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StaticContainer2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StaticContainer2.dir/build: StaticContainer2.exe
.PHONY : CMakeFiles/StaticContainer2.dir/build

CMakeFiles/StaticContainer2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StaticContainer2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StaticContainer2.dir/clean

CMakeFiles/StaticContainer2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\cmake-build-debug C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\cmake-build-debug C:\Users\pawel\Documents\studia\6semestr\CPP\emcpp-assignments\smart_pointers\cmake-build-debug\CMakeFiles\StaticContainer2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/StaticContainer2.dir/depend

