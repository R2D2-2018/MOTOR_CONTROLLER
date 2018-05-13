// Pretend that we have a cstdlib to please kvasir-toolchain.
extern "C" void __libc_init_array();
// cppcheck-suppress unusedFunction
extern "C" void __libc_init_array() {
}
