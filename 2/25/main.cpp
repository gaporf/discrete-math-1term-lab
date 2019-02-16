#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> arr;

void check() {
    for (int i = 0; i < k; i++) {
        if (arr[i] != n - k + i + 1) {
            return;
        }
    }
    cout << -1 << endl;
    exit(0);
}

int main() {
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    cin >> n >> k;
    arr.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    check();
    for (int i = k - 1; i >= 0; i--) {
        if (arr[i] != n - k + i + 1) {
            arr[i]++;
            for (int j = i + 1; j < k; j++) {
                arr[j] = arr[j - 1] + 1;
            }
            break;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}