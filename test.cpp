// 22/06/10 = Fri

// Test that echelon2 agrees with echelon1

// echelon1 - count different types of echelon forms of a m-by-n matrix
// echelon2 - enumerate different types of echelon forms of a m-by-n matrix

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::vector;

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

void bt(vector<vector<int>> &res, vector<int> &out, int beg, int n, int k) {
  if (out.size() == k) {
    res.push_back(out);
    return;
  }
  for (int i = beg; i <= n; ++i) {
    out.push_back(i);
    bt(res, out, i + 1, n, k);
    out.pop_back();
  }
}

vector<vector<int>> n_enumerate_k(int n, int k) {
  vector<vector<int>> res;
  vector<int> out;
  bt(res, out, 1, n, k);
  return res;
}

vector<vector<vector<int>>> fill(int m, int n) {
  vector<vector<vector<int>>> res;
  for (int k = 0; k <= std::min(m, n); ++k) {
    vector<vector<int>> options = n_enumerate_k(n, k);
    for (const auto &opt : options) {
      vector<vector<int>> matrix(m, vector<int>(n));
      for (int i = 0; i != k; ++i) {
        matrix[i][opt[i] - 1] = 1;
      }
      res.push_back(matrix);
    }
  }
  return res;
}

void test(int max_sum) {
  for (int sum = 2; sum <= max_sum; ++sum) {
    for (int m = 1; m < sum; ++m) {
      int n = sum - m;
      unsigned long long res1 = count(m, n);
      unsigned long long res2 = fill(m, n).size();
      std::cout << "test sum=" << sum << ", m=" << m << ", n=" << n
                << ": res1=" << res1 << ", res2=" << res2 << std::endl;
      assert(res1 == res2);
    }
  }
}

int main() {
  test(30);
  return 0;
}
