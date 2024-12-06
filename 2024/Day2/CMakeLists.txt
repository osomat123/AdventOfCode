# Add executables for Day1

# Set the output directory for executables to the current directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(puzzle Puzzle.cpp)

# Set the working directory for the executables
set_target_properties(puzzle PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Set the working directory for the executables
set_target_properties(puzzle PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
