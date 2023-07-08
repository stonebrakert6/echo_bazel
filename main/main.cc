#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

#include "tcmalloc/malloc_extension.h"
#include "tcmalloc/tcmalloc.h"
#include "utils/utils.h"
void f(char* a) { strcpy(a, "hell"); }

int main() {
  std::cout << "Hello ji" << std::endl;
  std::cout << "Factorinal of 5 = " << factorial(5) << std::endl;
  /* std::cout << io_uring_major_version() << " " << io_uring_minor_version() */
  /*           << std::endl; */
  char* a = reinterpret_cast<char*>(std::malloc(5));
  f(a);
  std::cout << tcmalloc::MallocExtension::GetStats();
  char* x = static_cast<char*>(TCMallocInternalMalloc(5));
  x[2] = 'R';
  std::vector<int> v;
  v.emplace_back(9);
  return 0;
}
