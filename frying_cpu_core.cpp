#include <iostream>
#include <cmath>

int main() {
    long long i = 2;  // Start from the first prime number

    while (true) {
        bool isPrime = true;

        // Check divisibility up to the square root of i for efficiency
        for (long long j = 2; j <= std::sqrt(i); j++) {     
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            std::cout << i << " ";
        }

        i++;
    }

    return 0;
}
