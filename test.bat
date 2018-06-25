mkdir build_test;
cd src
ren pwm_controller.cpp pwm_controller.backup
ren pwm_controller_mock.cpp pwm_controller.cpp
cd ..
timeout 1 > NUL
cd build_test && cmake .. -Dtest_build=TRUE -G"MinGW Makefiles" && ctest -V;
timeout 1 > NUL
cd ..
cd src
ren pwm_controller.cpp pwm_controller_mock.cpp
ren pwm_controller.backup pwm_controller.cpp
cd ..
cd build_test/Testing/Temporary
start LastTest.log
pause;