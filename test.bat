mkdir build_test;
cd build_test && cmake .. -Dtest_build=TRUE -G"MinGW Makefiles" && ctest -V;
timeout 1 > NUL
cd Testing/Temporary
start LastTest.log
pause;