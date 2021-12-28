#include "mydebug.h"

template<typename T> void mydbg_print_mono(std::string_view name, T arg) {
  std::cout << name << ": " << arg << std::endl;
}
