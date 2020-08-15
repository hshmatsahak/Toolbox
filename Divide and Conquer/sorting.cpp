#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r, int &m) {
  int x = a[l];
  int j = l;
  m = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      m++;
      swap(a[i], a[j]);
      if (a[i]==x)
        swap(a[i], a[m]);
    }
    else if (a[i] == x){
      m++;
      swap(a[i], a[m]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m;
  int j = partition2(a, l, r, m);

  randomized_quick_sort(a, l, j-1);
  randomized_quick_sort(a, m+1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}