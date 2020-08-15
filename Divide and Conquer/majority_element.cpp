#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  //base case
  if (left == right)
    return a[left];
  int mid = (left + right)/2;
  int max1 = get_majority_element(a, left, mid);
  int max2 = get_majority_element(a, mid+1, right);
  if (max1 == -1 && max2 == -1)
    return -1;
  else if (max1 == -1 && max2 != -1){
    int count = 0;
    for (int i = left; i <= right; i++){
      if (a[i] == max2)
        count++;
    }
    if (count > (right-left+1)/2)
      return max2;
  }
  else if (max2 == -1 && max1 != -1){
    int count = 0;
    for (int i = left; i <= right; i++){
      if (a[i] == max1)
        count++;
    }
    if (count > (right-left+1)/2)
      return max1;
  }
  else{
    int count = 0;
    for (int i = left; i <= right; i++){
      if (a[i] == max2)
        count++;
    }
    if (count > (right-left+1)/2)
      return max2;
    count = 0;
    for (int i = left; i <= right; i++){
      if (a[i] == max1)
        count++;
    }
    if (count > (right-left+1)/2)
      return max1;
    return -1;
  }
  return -1;
}

int get_majority_element_wrapper(vector<int> &a, int left, int right){
  if (get_majority_element(a, left, right) == -1)
    return 0;
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element_wrapper(a, 0, a.size()-1)) << '\n';
}