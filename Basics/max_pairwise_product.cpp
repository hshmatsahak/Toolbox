#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int max1 = -1;
    for (int i=0; i<n; i++){
        if (numbers[i] > max1)
            max1 = numbers[i];
    }

    int max2 = -1;
    bool firsttime = true;
    for (int i=0; i<n; i++){
        if (numbers[i] > max2 && (numbers[i]!=max1 || !firsttime))
            max2 = numbers[i];
        if (firsttime && numbers[i] == max1)
            firsttime = false;
    }

    return (long long)(max1)*max2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
