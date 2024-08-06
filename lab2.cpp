#include <iostream>

int main() {
    int n = 21;

    for (int i = 1; i <= n; i += 2) {
        if (i == 5 || i == 7 || i == 11 || i == 13) {
            continue; // Skip these numbers
        }
        std::cout << i << " ";
    }

    return 0;
}
