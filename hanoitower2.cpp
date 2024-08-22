#include <iostream>
#include <vector>
using namespace std;

// Rods to hold disks
vector<int> rodA, rodB, rodC;
int iterationCount = 0, targetIteration;

// Recursive function for Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
if (n == 0) return;

// Move n-1 disks from source to auxiliary, using destination as auxiliary
towerOfHanoi(n - 1, source, auxiliary, destination);

// Move the nth disk from source to destination
iterationCount++;

int disk;
if (source == 'A') {
disk = rodA.back();
rodA.pop_back();
} else if (source == 'B') {
disk = rodB.back();
rodB.pop_back();
} else {
disk = rodC.back();
rodC.pop_back();
}

if (destination == 'A') {
rodA.push_back(disk);
} else if (destination == 'B') {
rodB.push_back(disk);
} else {
rodC.push_back(disk);
}

// Print status at target iteration
if (iterationCount == targetIteration) {
cout << "Status after iteration " << targetIteration << ":" << endl;
cout << "Rod A: "; for (int i = 0; i < rodA.size(); i++) cout << rodA[i] << " "; cout << endl;
cout << "Rod B: "; for (int i = 0; i < rodB.size(); i++) cout << rodB[i] << " "; cout << endl;
cout << "Rod C: "; for (int i = 0; i < rodC.size(); i++) cout << rodC[i] << " "; cout << endl;
}

// Move n-1 disks from auxiliary to destination, using source as auxiliary
towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
int n;
cout << "Enter the number of disks: ";
cin >> n;
cout << "Enter the target iteration: ";
cin >> targetIteration;

// Initialize rodA with disks
for (int i = n; i >= 1; i--) {
rodA.push_back(i);
}

// Print initial status
cout << "Initial Status:" << endl;
cout << "Rod A: "; for (int i = 0; i < rodA.size(); i++) cout << rodA[i] << " "; cout << endl;
cout << "Rod B: " << endl;
cout << "Rod C: " << endl;

// Calculate total moves required
int totalMoves = (1 << n) - 1;  // Total moves for Tower of Hanoi is 2^n - 1

// Perform the Tower of Hanoi operation
towerOfHanoi(n, 'A', 'C', 'B');

// Check if the iteration exceeds the total moves
if (targetIteration > totalMoves) {
cout << "The target iteration exceeds the total number of moves required" << endl;
}

return 0;
}
