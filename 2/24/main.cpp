#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

bool zero() {
    for (int i = 0; i + 1 < n; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool one() {
    for (int i = 0; i + 1 < n; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool cmp(int a, int b) {
    return a > b;
}

void getLast() {
    vector<int> newArr = arr;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            int maxIndex = i + 1;
            for (int j = i + 2; j < n; j++) {
                if (newArr[j] < arr[i]) {
                    maxIndex = j;
                }
            }
            swap(newArr[i], newArr[maxIndex]);
            sort(newArr.begin() + i + 1, newArr.end(), cmp);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;
}

void getNext() {
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
}

int main() {
    freopen("nextperm.in", "r", stdin);
    freopen("nextperm.out", "w", stdout);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (zero()) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
    } else {
        getLast();
    }
    if (one()) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
    } else {
        getNext();
    }
    return 0;
}