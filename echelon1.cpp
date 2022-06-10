// 22/06/10 = Fri

// Count different types of echelon forms of a m-by-n matrix

// For example, a 2-by-2 matrix can have 4 different types of echelon forms:
//
// [ 1  * ]  [ 1  * ]  [ 0  1 ]  [ 0  0 ]
// [ 0  1 ]  [ 0  0 ]  [ 0  * ]  [ 0  0 ]
//
// where 1 for leading entries, 0 for forced zeros, * for arbitrary values.

// N(m, n) = (k choose 0) + (k choose 1) + ... + (k choose k) for k in min(m, n)

#include <algorithm>
#include <iostream>

unsigned long long n_choose_k(unsigned n, unsigned k) {
  k = std::min(k, n - k);
  if (k == 0) {
    return 1;
  }
  if (k == 1) {
    return n;
  }
  unsigned long long res = n;
  for (unsigned i = 2; i <= k; ++i) {
    res *= n - i + 1;
    res /= i;
  }
  return res;
}

unsigned long long count(unsigned m, unsigned n) {
  unsigned long long res = 0;
  for (unsigned k = 0; k <= std::min(m, n); ++k) {
    res += n_choose_k(n, k);
  }
  return res;
}

void usage() {
  std::cout << "\nCount different types of echelon forms of a m-by-n matrix.\n"
            << std::endl;
}

int main() {
  usage();
  while (true) {
    std::cout << "Please enter m, n (press Q to quit): ";
    unsigned m, n;
    std::cin >> m >> n;
    if (!std::cin || m <= 0 || n <= 0) {
      break;
    }
    unsigned long long res = count(m, n);
    std::cout << "There are " << res
              << " different types of echelon forms for a " << m << "x" << n
              << " matrix.\n\n";
  }
  return 0;
}
