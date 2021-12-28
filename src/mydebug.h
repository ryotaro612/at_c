#include<iostream>
#define print_mono(arg) mydbg_print_mono(#arg, arg)

template<typename T> void mydbg_print_mono(std::string_view name, T arg);
