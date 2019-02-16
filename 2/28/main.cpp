#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

void check() {
    for (int i = n - 1; i > 0; i--) {
        if (arr[i - 1] < arr[i]) {
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << 0 << " ";
    }
    cout << endl;
    exit(0);
}

int main() {
    freopen("nextmultiperm.in", "r", stdin);
    freopen("nextmultiperm.out", "w", stdout);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    check();
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            int minIndex = i + 1;
            for (int j = i + 2; j < n; j++) {
                if (arr[j] > arr[i]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
            sort(arr.begin() + i + 1, arr.end());
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}