#include <iostream>
#include <vector>
#include <numeric>

int main() {
int n;
std::cout << "Enter the number of distinct id (n): ";
std::cin >> n;

std::vector<int> ids(n);
std::cout << "Enter the " << n << " distinct ids (ranging from 1 to " << n+1 << "): " << std::endl;
for(int i = 0; i < n; ++i) {
std::cin >> ids[i];
}

int expected_sum = (n + 1) * (n + 2) / 2;
int actual_sum = std::accumulate(ids.begin(), ids.end(), 0);

int missing_id = expected_sum - actual_sum;
std::cout << "The missing id is: " << missing_id << std::endl;

return 0;
}
