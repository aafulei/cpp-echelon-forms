// 22/06/10 = Fri

// Enumerate different types of echelon forms of a m-by-n matrix

// For example, a 2-by-2 matrix can have 4 different types of echelon forms:
//
// [ 1  * ]  [ 1  * ]  [ 0  1 ]  [ 0  0 ]
// [ 0  1 ]  [ 0  0 ]  [ 0  * ]  [ 0  0 ]
//
// where 1 for leading entries, 0 for forced zeros, * for arbitrary values.

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

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

void print(const vector<vector<int>> &matrix) {
  for (const auto &row : matrix) {
    bool star = false;
    for (int x : row) {
      if (star) {
        std::cout << "*";
      } else if (x) {
        std::cout << "1";
        star = true;
      } else {
        std::cout << "0";
      }
    }
    std::cout << "\n";
  }
}

void usage() {
  std::cout
      << "\nEnumerate different types of echelon forms of a m-by-n matrix.\n"
      << std::endl;
}

int main() {
  usage();
  while (true) {
    std::cout << "Please enter m, n (press Q to quit): ";
    int m, n;
    std::cin >> m >> n;
    if (!(std::cin && 0 < m && m <= 10 && 0 < n && n <= 10)) {
      break;
    }
    vector<vector<vector<int>>> res = fill(m, n);
    for (const auto &mat : res) {
      print(mat);
      std::cout << std::endl;
    }
    std::cout << "There are " << res.size()
              << " different types of echelon forms for a " << m << "x" << n
              << " matrix.\n"
              << std::endl;
  }
  return 0;
}
