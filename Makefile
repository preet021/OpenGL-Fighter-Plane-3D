# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/preet/IIIT/2-2/Graphics/Assignments/2/3D-fighter-plane

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/preet/IIIT/2-2/Graphics/Assignments/2/3D-fighter-plane

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/preet/IIIT/2-2/Graphics/Assignments/2/3D-fighter-plane/CMakeFiles /home/preet/IIIT/2-2/Graphics/Assignments/2/3D-fighter-plane/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/preet/IIIT/2-2/Graphics/Assignments/2/3D-fighter-plane/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named fighter-plane

# Build rule for target.
fighter-plane: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 fighter-plane
.PHONY : fighter-plane

# fast build rule for target.
fighter-plane/fast:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/build
.PHONY : fighter-plane/fast

src/arrow.o: src/arrow.cpp.o

.PHONY : src/arrow.o

# target to build an object file
src/arrow.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/arrow.cpp.o
.PHONY : src/arrow.cpp.o

src/arrow.i: src/arrow.cpp.i

.PHONY : src/arrow.i

# target to preprocess a source file
src/arrow.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/arrow.cpp.i
.PHONY : src/arrow.cpp.i

src/arrow.s: src/arrow.cpp.s

.PHONY : src/arrow.s

# target to generate assembly for a file
src/arrow.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/arrow.cpp.s
.PHONY : src/arrow.cpp.s

src/bomb.o: src/bomb.cpp.o

.PHONY : src/bomb.o

# target to build an object file
src/bomb.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/bomb.cpp.o
.PHONY : src/bomb.cpp.o

src/bomb.i: src/bomb.cpp.i

.PHONY : src/bomb.i

# target to preprocess a source file
src/bomb.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/bomb.cpp.i
.PHONY : src/bomb.cpp.i

src/bomb.s: src/bomb.cpp.s

.PHONY : src/bomb.s

# target to generate assembly for a file
src/bomb.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/bomb.cpp.s
.PHONY : src/bomb.cpp.s

src/color.o: src/color.cpp.o

.PHONY : src/color.o

# target to build an object file
src/color.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/color.cpp.o
.PHONY : src/color.cpp.o

src/color.i: src/color.cpp.i

.PHONY : src/color.i

# target to preprocess a source file
src/color.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/color.cpp.i
.PHONY : src/color.cpp.i

src/color.s: src/color.cpp.s

.PHONY : src/color.s

# target to generate assembly for a file
src/color.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/color.cpp.s
.PHONY : src/color.cpp.s

src/dashboard.o: src/dashboard.cpp.o

.PHONY : src/dashboard.o

# target to build an object file
src/dashboard.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/dashboard.cpp.o
.PHONY : src/dashboard.cpp.o

src/dashboard.i: src/dashboard.cpp.i

.PHONY : src/dashboard.i

# target to preprocess a source file
src/dashboard.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/dashboard.cpp.i
.PHONY : src/dashboard.cpp.i

src/dashboard.s: src/dashboard.cpp.s

.PHONY : src/dashboard.s

# target to generate assembly for a file
src/dashboard.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/dashboard.cpp.s
.PHONY : src/dashboard.cpp.s

src/enemy.o: src/enemy.cpp.o

.PHONY : src/enemy.o

# target to build an object file
src/enemy.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/enemy.cpp.o
.PHONY : src/enemy.cpp.o

src/enemy.i: src/enemy.cpp.i

.PHONY : src/enemy.i

# target to preprocess a source file
src/enemy.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/enemy.cpp.i
.PHONY : src/enemy.cpp.i

src/enemy.s: src/enemy.cpp.s

.PHONY : src/enemy.s

# target to generate assembly for a file
src/enemy.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/enemy.cpp.s
.PHONY : src/enemy.cpp.s

src/fan.o: src/fan.cpp.o

.PHONY : src/fan.o

# target to build an object file
src/fan.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fan.cpp.o
.PHONY : src/fan.cpp.o

src/fan.i: src/fan.cpp.i

.PHONY : src/fan.i

# target to preprocess a source file
src/fan.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fan.cpp.i
.PHONY : src/fan.cpp.i

src/fan.s: src/fan.cpp.s

.PHONY : src/fan.s

# target to generate assembly for a file
src/fan.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fan.cpp.s
.PHONY : src/fan.cpp.s

src/fish.o: src/fish.cpp.o

.PHONY : src/fish.o

# target to build an object file
src/fish.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fish.cpp.o
.PHONY : src/fish.cpp.o

src/fish.i: src/fish.cpp.i

.PHONY : src/fish.i

# target to preprocess a source file
src/fish.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fish.cpp.i
.PHONY : src/fish.cpp.i

src/fish.s: src/fish.cpp.s

.PHONY : src/fish.s

# target to generate assembly for a file
src/fish.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fish.cpp.s
.PHONY : src/fish.cpp.s

src/fuel.o: src/fuel.cpp.o

.PHONY : src/fuel.o

# target to build an object file
src/fuel.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fuel.cpp.o
.PHONY : src/fuel.cpp.o

src/fuel.i: src/fuel.cpp.i

.PHONY : src/fuel.i

# target to preprocess a source file
src/fuel.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fuel.cpp.i
.PHONY : src/fuel.cpp.i

src/fuel.s: src/fuel.cpp.s

.PHONY : src/fuel.s

# target to generate assembly for a file
src/fuel.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/fuel.cpp.s
.PHONY : src/fuel.cpp.s

src/ground.o: src/ground.cpp.o

.PHONY : src/ground.o

# target to build an object file
src/ground.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/ground.cpp.o
.PHONY : src/ground.cpp.o

src/ground.i: src/ground.cpp.i

.PHONY : src/ground.i

# target to preprocess a source file
src/ground.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/ground.cpp.i
.PHONY : src/ground.cpp.i

src/ground.s: src/ground.cpp.s

.PHONY : src/ground.s

# target to generate assembly for a file
src/ground.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/ground.cpp.s
.PHONY : src/ground.cpp.s

src/input.o: src/input.cpp.o

.PHONY : src/input.o

# target to build an object file
src/input.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/input.cpp.o
.PHONY : src/input.cpp.o

src/input.i: src/input.cpp.i

.PHONY : src/input.i

# target to preprocess a source file
src/input.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/input.cpp.i
.PHONY : src/input.cpp.i

src/input.s: src/input.cpp.s

.PHONY : src/input.s

# target to generate assembly for a file
src/input.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/input.cpp.s
.PHONY : src/input.cpp.s

src/island.o: src/island.cpp.o

.PHONY : src/island.o

# target to build an object file
src/island.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/island.cpp.o
.PHONY : src/island.cpp.o

src/island.i: src/island.cpp.i

.PHONY : src/island.i

# target to preprocess a source file
src/island.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/island.cpp.i
.PHONY : src/island.cpp.i

src/island.s: src/island.cpp.s

.PHONY : src/island.s

# target to generate assembly for a file
src/island.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/island.cpp.s
.PHONY : src/island.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/missile.o: src/missile.cpp.o

.PHONY : src/missile.o

# target to build an object file
src/missile.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/missile.cpp.o
.PHONY : src/missile.cpp.o

src/missile.i: src/missile.cpp.i

.PHONY : src/missile.i

# target to preprocess a source file
src/missile.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/missile.cpp.i
.PHONY : src/missile.cpp.i

src/missile.s: src/missile.cpp.s

.PHONY : src/missile.s

# target to generate assembly for a file
src/missile.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/missile.cpp.s
.PHONY : src/missile.cpp.s

src/needle.o: src/needle.cpp.o

.PHONY : src/needle.o

# target to build an object file
src/needle.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/needle.cpp.o
.PHONY : src/needle.cpp.o

src/needle.i: src/needle.cpp.i

.PHONY : src/needle.i

# target to preprocess a source file
src/needle.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/needle.cpp.i
.PHONY : src/needle.cpp.i

src/needle.s: src/needle.cpp.s

.PHONY : src/needle.s

# target to generate assembly for a file
src/needle.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/needle.cpp.s
.PHONY : src/needle.cpp.s

src/nonedit.o: src/nonedit.cpp.o

.PHONY : src/nonedit.o

# target to build an object file
src/nonedit.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/nonedit.cpp.o
.PHONY : src/nonedit.cpp.o

src/nonedit.i: src/nonedit.cpp.i

.PHONY : src/nonedit.i

# target to preprocess a source file
src/nonedit.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/nonedit.cpp.i
.PHONY : src/nonedit.cpp.i

src/nonedit.s: src/nonedit.cpp.s

.PHONY : src/nonedit.s

# target to generate assembly for a file
src/nonedit.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/nonedit.cpp.s
.PHONY : src/nonedit.cpp.s

src/other_handlers.o: src/other_handlers.cpp.o

.PHONY : src/other_handlers.o

# target to build an object file
src/other_handlers.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/other_handlers.cpp.o
.PHONY : src/other_handlers.cpp.o

src/other_handlers.i: src/other_handlers.cpp.i

.PHONY : src/other_handlers.i

# target to preprocess a source file
src/other_handlers.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/other_handlers.cpp.i
.PHONY : src/other_handlers.cpp.i

src/other_handlers.s: src/other_handlers.cpp.s

.PHONY : src/other_handlers.s

# target to generate assembly for a file
src/other_handlers.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/other_handlers.cpp.s
.PHONY : src/other_handlers.cpp.s

src/parachute.o: src/parachute.cpp.o

.PHONY : src/parachute.o

# target to build an object file
src/parachute.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/parachute.cpp.o
.PHONY : src/parachute.cpp.o

src/parachute.i: src/parachute.cpp.i

.PHONY : src/parachute.i

# target to preprocess a source file
src/parachute.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/parachute.cpp.i
.PHONY : src/parachute.cpp.i

src/parachute.s: src/parachute.cpp.s

.PHONY : src/parachute.s

# target to generate assembly for a file
src/parachute.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/parachute.cpp.s
.PHONY : src/parachute.cpp.s

src/plane.o: src/plane.cpp.o

.PHONY : src/plane.o

# target to build an object file
src/plane.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/plane.cpp.o
.PHONY : src/plane.cpp.o

src/plane.i: src/plane.cpp.i

.PHONY : src/plane.i

# target to preprocess a source file
src/plane.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/plane.cpp.i
.PHONY : src/plane.cpp.i

src/plane.s: src/plane.cpp.s

.PHONY : src/plane.s

# target to generate assembly for a file
src/plane.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/plane.cpp.s
.PHONY : src/plane.cpp.s

src/ring.o: src/ring.cpp.o

.PHONY : src/ring.o

# target to build an object file
src/ring.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/ring.cpp.o
.PHONY : src/ring.cpp.o

src/ring.i: src/ring.cpp.i

.PHONY : src/ring.i

# target to preprocess a source file
src/ring.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/ring.cpp.i
.PHONY : src/ring.cpp.i

src/ring.s: src/ring.cpp.s

.PHONY : src/ring.s

# target to generate assembly for a file
src/ring.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/ring.cpp.s
.PHONY : src/ring.cpp.s

src/score.o: src/score.cpp.o

.PHONY : src/score.o

# target to build an object file
src/score.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/score.cpp.o
.PHONY : src/score.cpp.o

src/score.i: src/score.cpp.i

.PHONY : src/score.i

# target to preprocess a source file
src/score.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/score.cpp.i
.PHONY : src/score.cpp.i

src/score.s: src/score.cpp.s

.PHONY : src/score.s

# target to generate assembly for a file
src/score.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/score.cpp.s
.PHONY : src/score.cpp.s

src/timer.o: src/timer.cpp.o

.PHONY : src/timer.o

# target to build an object file
src/timer.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/timer.cpp.o
.PHONY : src/timer.cpp.o

src/timer.i: src/timer.cpp.i

.PHONY : src/timer.i

# target to preprocess a source file
src/timer.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/timer.cpp.i
.PHONY : src/timer.cpp.i

src/timer.s: src/timer.cpp.s

.PHONY : src/timer.s

# target to generate assembly for a file
src/timer.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/timer.cpp.s
.PHONY : src/timer.cpp.s

src/volcano.o: src/volcano.cpp.o

.PHONY : src/volcano.o

# target to build an object file
src/volcano.cpp.o:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/volcano.cpp.o
.PHONY : src/volcano.cpp.o

src/volcano.i: src/volcano.cpp.i

.PHONY : src/volcano.i

# target to preprocess a source file
src/volcano.cpp.i:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/volcano.cpp.i
.PHONY : src/volcano.cpp.i

src/volcano.s: src/volcano.cpp.s

.PHONY : src/volcano.s

# target to generate assembly for a file
src/volcano.cpp.s:
	$(MAKE) -f CMakeFiles/fighter-plane.dir/build.make CMakeFiles/fighter-plane.dir/src/volcano.cpp.s
.PHONY : src/volcano.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... fighter-plane"
	@echo "... rebuild_cache"
	@echo "... src/arrow.o"
	@echo "... src/arrow.i"
	@echo "... src/arrow.s"
	@echo "... src/bomb.o"
	@echo "... src/bomb.i"
	@echo "... src/bomb.s"
	@echo "... src/color.o"
	@echo "... src/color.i"
	@echo "... src/color.s"
	@echo "... src/dashboard.o"
	@echo "... src/dashboard.i"
	@echo "... src/dashboard.s"
	@echo "... src/enemy.o"
	@echo "... src/enemy.i"
	@echo "... src/enemy.s"
	@echo "... src/fan.o"
	@echo "... src/fan.i"
	@echo "... src/fan.s"
	@echo "... src/fish.o"
	@echo "... src/fish.i"
	@echo "... src/fish.s"
	@echo "... src/fuel.o"
	@echo "... src/fuel.i"
	@echo "... src/fuel.s"
	@echo "... src/ground.o"
	@echo "... src/ground.i"
	@echo "... src/ground.s"
	@echo "... src/input.o"
	@echo "... src/input.i"
	@echo "... src/input.s"
	@echo "... src/island.o"
	@echo "... src/island.i"
	@echo "... src/island.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/missile.o"
	@echo "... src/missile.i"
	@echo "... src/missile.s"
	@echo "... src/needle.o"
	@echo "... src/needle.i"
	@echo "... src/needle.s"
	@echo "... src/nonedit.o"
	@echo "... src/nonedit.i"
	@echo "... src/nonedit.s"
	@echo "... src/other_handlers.o"
	@echo "... src/other_handlers.i"
	@echo "... src/other_handlers.s"
	@echo "... src/parachute.o"
	@echo "... src/parachute.i"
	@echo "... src/parachute.s"
	@echo "... src/plane.o"
	@echo "... src/plane.i"
	@echo "... src/plane.s"
	@echo "... src/ring.o"
	@echo "... src/ring.i"
	@echo "... src/ring.s"
	@echo "... src/score.o"
	@echo "... src/score.i"
	@echo "... src/score.s"
	@echo "... src/timer.o"
	@echo "... src/timer.i"
	@echo "... src/timer.s"
	@echo "... src/volcano.o"
	@echo "... src/volcano.i"
	@echo "... src/volcano.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

