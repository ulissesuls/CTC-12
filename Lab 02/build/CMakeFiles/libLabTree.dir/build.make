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
CMAKE_SOURCE_DIR = "/home/ulissesuls/Projects/CTC-12/Lab 02"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ulissesuls/Projects/CTC-12/Lab 02/build"

# Include any dependencies generated for this target.
include CMakeFiles/libLabTree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libLabTree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libLabTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libLabTree.dir/flags.make

CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o: CMakeFiles/libLabTree.dir/flags.make
CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o: ../lib/IndexFactory.cpp
CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o: CMakeFiles/libLabTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ulissesuls/Projects/CTC-12/Lab 02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o -MF CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o.d -o CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o -c "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/IndexFactory.cpp"

CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/IndexFactory.cpp" > CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.i

CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/IndexFactory.cpp" -o CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.s

CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o: CMakeFiles/libLabTree.dir/flags.make
CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o: ../lib/IndexPointsStlMultimap.cpp
CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o: CMakeFiles/libLabTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ulissesuls/Projects/CTC-12/Lab 02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o -MF CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o.d -o CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o -c "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/IndexPointsStlMultimap.cpp"

CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/IndexPointsStlMultimap.cpp" > CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.i

CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/IndexPointsStlMultimap.cpp" -o CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.s

CMakeFiles/libLabTree.dir/lib/Point3.cpp.o: CMakeFiles/libLabTree.dir/flags.make
CMakeFiles/libLabTree.dir/lib/Point3.cpp.o: ../lib/Point3.cpp
CMakeFiles/libLabTree.dir/lib/Point3.cpp.o: CMakeFiles/libLabTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ulissesuls/Projects/CTC-12/Lab 02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libLabTree.dir/lib/Point3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libLabTree.dir/lib/Point3.cpp.o -MF CMakeFiles/libLabTree.dir/lib/Point3.cpp.o.d -o CMakeFiles/libLabTree.dir/lib/Point3.cpp.o -c "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/Point3.cpp"

CMakeFiles/libLabTree.dir/lib/Point3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libLabTree.dir/lib/Point3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/Point3.cpp" > CMakeFiles/libLabTree.dir/lib/Point3.cpp.i

CMakeFiles/libLabTree.dir/lib/Point3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libLabTree.dir/lib/Point3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/Point3.cpp" -o CMakeFiles/libLabTree.dir/lib/Point3.cpp.s

CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o: CMakeFiles/libLabTree.dir/flags.make
CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o: ../lib/PointReader.cpp
CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o: CMakeFiles/libLabTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ulissesuls/Projects/CTC-12/Lab 02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o -MF CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o.d -o CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o -c "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/PointReader.cpp"

CMakeFiles/libLabTree.dir/lib/PointReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libLabTree.dir/lib/PointReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/PointReader.cpp" > CMakeFiles/libLabTree.dir/lib/PointReader.cpp.i

CMakeFiles/libLabTree.dir/lib/PointReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libLabTree.dir/lib/PointReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/PointReader.cpp" -o CMakeFiles/libLabTree.dir/lib/PointReader.cpp.s

CMakeFiles/libLabTree.dir/lib/Tick.cpp.o: CMakeFiles/libLabTree.dir/flags.make
CMakeFiles/libLabTree.dir/lib/Tick.cpp.o: ../lib/Tick.cpp
CMakeFiles/libLabTree.dir/lib/Tick.cpp.o: CMakeFiles/libLabTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ulissesuls/Projects/CTC-12/Lab 02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libLabTree.dir/lib/Tick.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libLabTree.dir/lib/Tick.cpp.o -MF CMakeFiles/libLabTree.dir/lib/Tick.cpp.o.d -o CMakeFiles/libLabTree.dir/lib/Tick.cpp.o -c "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/Tick.cpp"

CMakeFiles/libLabTree.dir/lib/Tick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libLabTree.dir/lib/Tick.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/Tick.cpp" > CMakeFiles/libLabTree.dir/lib/Tick.cpp.i

CMakeFiles/libLabTree.dir/lib/Tick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libLabTree.dir/lib/Tick.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ulissesuls/Projects/CTC-12/Lab 02/lib/Tick.cpp" -o CMakeFiles/libLabTree.dir/lib/Tick.cpp.s

# Object files for target libLabTree
libLabTree_OBJECTS = \
"CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o" \
"CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o" \
"CMakeFiles/libLabTree.dir/lib/Point3.cpp.o" \
"CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o" \
"CMakeFiles/libLabTree.dir/lib/Tick.cpp.o"

# External object files for target libLabTree
libLabTree_EXTERNAL_OBJECTS =

liblibLabTree.a: CMakeFiles/libLabTree.dir/lib/IndexFactory.cpp.o
liblibLabTree.a: CMakeFiles/libLabTree.dir/lib/IndexPointsStlMultimap.cpp.o
liblibLabTree.a: CMakeFiles/libLabTree.dir/lib/Point3.cpp.o
liblibLabTree.a: CMakeFiles/libLabTree.dir/lib/PointReader.cpp.o
liblibLabTree.a: CMakeFiles/libLabTree.dir/lib/Tick.cpp.o
liblibLabTree.a: CMakeFiles/libLabTree.dir/build.make
liblibLabTree.a: CMakeFiles/libLabTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ulissesuls/Projects/CTC-12/Lab 02/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library liblibLabTree.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libLabTree.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libLabTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libLabTree.dir/build: liblibLabTree.a
.PHONY : CMakeFiles/libLabTree.dir/build

CMakeFiles/libLabTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libLabTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libLabTree.dir/clean

CMakeFiles/libLabTree.dir/depend:
	cd "/home/ulissesuls/Projects/CTC-12/Lab 02/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ulissesuls/Projects/CTC-12/Lab 02" "/home/ulissesuls/Projects/CTC-12/Lab 02" "/home/ulissesuls/Projects/CTC-12/Lab 02/build" "/home/ulissesuls/Projects/CTC-12/Lab 02/build" "/home/ulissesuls/Projects/CTC-12/Lab 02/build/CMakeFiles/libLabTree.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/libLabTree.dir/depend

