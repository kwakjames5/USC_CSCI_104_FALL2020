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
CMAKE_SOURCE_DIR = /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests

# Include any dependencies generated for this target.
include user_tests/CMakeFiles/user_tests.dir/depend.make

# Include the progress variables for this target.
include user_tests/CMakeFiles/user_tests.dir/progress.make

# Include the compile flags for this target's objects.
include user_tests/CMakeFiles/user_tests.dir/flags.make

user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o: user_tests/CMakeFiles/user_tests.dir/flags.make
user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o: user_tests/constructor_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user_tests.dir/constructor_tests.cpp.o -c /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/constructor_tests.cpp

user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_tests.dir/constructor_tests.cpp.i"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/constructor_tests.cpp > CMakeFiles/user_tests.dir/constructor_tests.cpp.i

user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_tests.dir/constructor_tests.cpp.s"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/constructor_tests.cpp -o CMakeFiles/user_tests.dir/constructor_tests.cpp.s

user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o.requires:

.PHONY : user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o.requires

user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o.provides: user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o.requires
	$(MAKE) -f user_tests/CMakeFiles/user_tests.dir/build.make user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o.provides.build
.PHONY : user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o.provides

user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o.provides.build: user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o


user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o: user_tests/CMakeFiles/user_tests.dir/flags.make
user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o: user_tests/feed_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user_tests.dir/feed_tests.cpp.o -c /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/feed_tests.cpp

user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_tests.dir/feed_tests.cpp.i"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/feed_tests.cpp > CMakeFiles/user_tests.dir/feed_tests.cpp.i

user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_tests.dir/feed_tests.cpp.s"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/feed_tests.cpp -o CMakeFiles/user_tests.dir/feed_tests.cpp.s

user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o.requires:

.PHONY : user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o.requires

user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o.provides: user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o.requires
	$(MAKE) -f user_tests/CMakeFiles/user_tests.dir/build.make user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o.provides.build
.PHONY : user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o.provides

user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o.provides.build: user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o


user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o: user_tests/CMakeFiles/user_tests.dir/flags.make
user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o: user_tests/follower_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user_tests.dir/follower_tests.cpp.o -c /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/follower_tests.cpp

user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_tests.dir/follower_tests.cpp.i"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/follower_tests.cpp > CMakeFiles/user_tests.dir/follower_tests.cpp.i

user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_tests.dir/follower_tests.cpp.s"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/follower_tests.cpp -o CMakeFiles/user_tests.dir/follower_tests.cpp.s

user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o.requires:

.PHONY : user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o.requires

user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o.provides: user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o.requires
	$(MAKE) -f user_tests/CMakeFiles/user_tests.dir/build.make user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o.provides.build
.PHONY : user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o.provides

user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o.provides.build: user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o


user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o: user_tests/CMakeFiles/user_tests.dir/flags.make
user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o: user_tests/following_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user_tests.dir/following_tests.cpp.o -c /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/following_tests.cpp

user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_tests.dir/following_tests.cpp.i"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/following_tests.cpp > CMakeFiles/user_tests.dir/following_tests.cpp.i

user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_tests.dir/following_tests.cpp.s"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/following_tests.cpp -o CMakeFiles/user_tests.dir/following_tests.cpp.s

user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o.requires:

.PHONY : user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o.requires

user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o.provides: user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o.requires
	$(MAKE) -f user_tests/CMakeFiles/user_tests.dir/build.make user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o.provides.build
.PHONY : user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o.provides

user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o.provides.build: user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o


user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o: user_tests/CMakeFiles/user_tests.dir/flags.make
user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o: user_tests/tweets_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user_tests.dir/tweets_tests.cpp.o -c /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/tweets_tests.cpp

user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user_tests.dir/tweets_tests.cpp.i"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/tweets_tests.cpp > CMakeFiles/user_tests.dir/tweets_tests.cpp.i

user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user_tests.dir/tweets_tests.cpp.s"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/tweets_tests.cpp -o CMakeFiles/user_tests.dir/tweets_tests.cpp.s

user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o.requires:

.PHONY : user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o.requires

user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o.provides: user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o.requires
	$(MAKE) -f user_tests/CMakeFiles/user_tests.dir/build.make user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o.provides.build
.PHONY : user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o.provides

user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o.provides.build: user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o


# Object files for target user_tests
user_tests_OBJECTS = \
"CMakeFiles/user_tests.dir/constructor_tests.cpp.o" \
"CMakeFiles/user_tests.dir/feed_tests.cpp.o" \
"CMakeFiles/user_tests.dir/follower_tests.cpp.o" \
"CMakeFiles/user_tests.dir/following_tests.cpp.o" \
"CMakeFiles/user_tests.dir/tweets_tests.cpp.o"

# External object files for target user_tests
user_tests_EXTERNAL_OBJECTS =

user_tests/user_tests: user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o
user_tests/user_tests: user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o
user_tests/user_tests: user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o
user_tests/user_tests: user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o
user_tests/user_tests: user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o
user_tests/user_tests: user_tests/CMakeFiles/user_tests.dir/build.make
user_tests/user_tests: user_tests/libhw3_user.a
user_tests/user_tests: testing_utils/libtesting_utils.a
user_tests/user_tests: /usr/lib/libgtest_main.a
user_tests/user_tests: /usr/lib/libgtest.a
user_tests/user_tests: testing_utils/kwsys/libkwsys.a
user_tests/user_tests: testing_utils/libperf/libperf.a
user_tests/user_tests: user_tests/CMakeFiles/user_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable user_tests"
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/user_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
user_tests/CMakeFiles/user_tests.dir/build: user_tests/user_tests

.PHONY : user_tests/CMakeFiles/user_tests.dir/build

user_tests/CMakeFiles/user_tests.dir/requires: user_tests/CMakeFiles/user_tests.dir/constructor_tests.cpp.o.requires
user_tests/CMakeFiles/user_tests.dir/requires: user_tests/CMakeFiles/user_tests.dir/feed_tests.cpp.o.requires
user_tests/CMakeFiles/user_tests.dir/requires: user_tests/CMakeFiles/user_tests.dir/follower_tests.cpp.o.requires
user_tests/CMakeFiles/user_tests.dir/requires: user_tests/CMakeFiles/user_tests.dir/following_tests.cpp.o.requires
user_tests/CMakeFiles/user_tests.dir/requires: user_tests/CMakeFiles/user_tests.dir/tweets_tests.cpp.o.requires

.PHONY : user_tests/CMakeFiles/user_tests.dir/requires

user_tests/CMakeFiles/user_tests.dir/clean:
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests && $(CMAKE_COMMAND) -P CMakeFiles/user_tests.dir/cmake_clean.cmake
.PHONY : user_tests/CMakeFiles/user_tests.dir/clean

user_tests/CMakeFiles/user_tests.dir/depend:
	cd /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests /home/cs104/Repositories/hw-kwakjame/hw3/hw3_tests/user_tests/CMakeFiles/user_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : user_tests/CMakeFiles/user_tests.dir/depend

