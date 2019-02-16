#include <bits/stdc++.h>

using namespace std;

map<vector<int>, bool> mp;
vector<int> arr;
int n;

void gen(int num) {
    if (num == n) {
        if (mp[arr]) {
            return;
        }
        mp[arr] = true;
        for (int i = 0; i < n; i++) {
            if (arr[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    } else {
        gen(n);
        arr[num] = 1;
        gen(num + 1);
        arr[num] = 0;
        gen(num + 1);
    }
}

int main() {
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    cin >> n;
    arr.resize(n, 0);
    gen(0);
    return 0;
}