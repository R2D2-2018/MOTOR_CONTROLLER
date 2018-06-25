mkdir build_test
cd src
mv pwm_controller_mock.cpp pwm_controller.cpp
cd ..
pwd
cd build_test
cmake .. -Dtest_build=TRUE
ctest -V
