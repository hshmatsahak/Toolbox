#include <iostream>

long long get_pisano_idx(long long n, long long m) {
    long long prev = 0;
    long long current = 1;
    for (long i=1; i<n; i++){
        long long tmp = prev;
        prev = current; 
        current = (current + tmp)%m;
        if (prev==0 && current==1)
            return i;
    }
    return n+1;
}

long long get_fibonacci_huge(long long n, long long m) {
    // array not space efficient
    // there is somehting called the pisano period 
    long long prev = 0;
    long long current = 1;
    long long idx = n % get_pisano_idx(n,m);
    if (idx == 0) return 0; if (idx==1) return 1; 
    for (long i=1; i<idx; i++){
        long long tmp = prev;
        prev = current;
        current = (current + tmp)%m;
    }
    return current;
}

int fibonacci_sum_naive(long long n) {
    return (get_fibonacci_huge(n, 10)+get_fibonacci_huge(n+1, 10)-1)%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
