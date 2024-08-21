#include <iostream>
#include <vector>

using namespace std;

void deleteAndCompare(vector<int>& nums, int pos, int& comparisons) {
if (pos < 1 || pos > nums.size()) {
cout << "Invalid Position" << endl;
return;
}

nums.erase(nums.begin() + pos - 1);
comparisons = pos;

for (int num : nums) {
cout << num << endl;
}
}

int main() {
vector<int> nums;
int comparisons = 0;
int size;

cin >> size;

for (int i = 0; i < size; i++) {
int num;
cin >> num;
nums.push_back(num);
}

for (int num : nums) {
cout << num << " ";
}
cout << endl;

int pos;
cout << "Enter position of element to delete: ";
cin >> pos;

deleteAndCompare(nums, pos, comparisons);
cout << "Comparisons: " << comparisons << endl;

return 0;
}
