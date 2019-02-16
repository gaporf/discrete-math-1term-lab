#include <bits/stdc++.h>

using namespace std;

int n, k, K;
vector<vector<int> > arr;

void write() {
    for (int i = 0; i < k; i++) {
        if (arr[i].empty()) {
            return;
        }
        if (i + 1 < k) {
            if (arr[i].size() > arr[i + 1].size()) {
                return;
            } else if (arr[i].size() == arr[i + 1].size() && !arr[i + 1].empty() && arr[i][0] > arr[i + 1][0]) {
                return;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void gen(int num) {
    if (num == n + 1) {
        write();
    } else {
        for (int i = 0; i < k; i++) {
            arr[i].push_back(num);
            if (arr[i].size() == 1) {
                K--;
            }
            if (n - num >= K) {
                gen(num + 1);
            }
            arr[i].pop_back();
            if (arr[i].size() == 0) {
                K++;
            }
        }
    }
}
int main() {
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    K = k;
    arr.resize(k);
    gen(1);

    return 0;
}