#include <iostream>

long long lcm(int a, int b) {
  for (long l = a; l <= (long long) a * b; l+=a)
    if (l % b == 0)
      return l;

  return (long long) a * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
