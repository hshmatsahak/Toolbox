#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x, int left, int right) {
  if (left > right)
    return -1;
  int mid = (left + right)/2;
  if (a[mid] == x)
    return mid;
  if (x > a[mid])
    return binary_search(a, x, mid+1, right);
  return binary_search(a, x, 0, mid-1);
}

int binary_search_wrapper(const vector<int> &a, int x){
  return binary_search(a, x, 0, (int)a.size()-1);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search_wrapper(a, b[i]) << ' ';
  }
}
