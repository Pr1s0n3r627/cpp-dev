#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int findLastOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> target;

    int first = findFirstOccurrence(arr, target);
    int last = findLastOccurrence(arr, target);

    if (first == -1 || last == -1) {
        cout << "-1 -1" << endl;
    } else {
        cout << first << " " << last << endl;
    }

    return 0;
}
