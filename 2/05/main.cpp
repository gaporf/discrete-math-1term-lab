#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<int>> arr;

void gen(int num) {
    if (num == n) {
        for (auto &i : arr) {
            for (int j : i) {
                cout << j;
            }
            cout << endl;
        }
    } else {
        if (num == 0) {
            vector<int> a;
            for (int i = 0; i < k; i++) {
                a.push_back(i);
                arr.push_back(a);
                a.clear();
            }
            gen(num + 1);
        } else {
            vector<vector<int> > newArr;
            for (int i = 0; i < k; i++) {
                if (i % 2 == 0) {
                    for (auto y : arr) {
                        y.push_back(i);
                        newArr.push_back(y);
                    }
                } else {
                    for (int j = static_cast<int>(arr.size() - 1); j >= 0; j--) {
                        vector<int> y = arr[j];
                        y.push_back(i);
                        newArr.push_back(y);
                    }
                }
            }
            arr = newArr;
            gen(num + 1);
        }
    }
}

int main() {
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    cin >> n >> k;
    gen(0);

    return 0;
}