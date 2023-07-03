#include <cstdint>
uint64_t factorial(uint64_t n) {
  if (n == 0) {
    return 1ULL;
  }
  return n * factorial(n-1);
}

