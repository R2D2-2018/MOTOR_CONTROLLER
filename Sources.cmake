# Libraries:

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/controller.cpp
    src/dc_interface.cpp
    src/stepper_interface.cpp
    src/servo_interface.cpp
)
