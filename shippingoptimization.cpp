#include <iostream>
using namespace std;

struct P {
    int id;
    double w, v, d;
};

void sortParcels(P arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].d < arr[j].d || (arr[i].d == arr[j].d && arr[i].id > arr[j].id)) {
                P temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    P* arr = new P[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].w >> arr[i].v;
        arr[i].d = arr[i].w / arr[i].v;
    }
    sortParcels(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i].id << " " << arr[i].w << ".00 " << arr[i].v << ".00 " << arr[i].d << ".00 " << endl;
    }
    return 0;
}
