#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

void gen(int num) {
    if (num == n) {
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < n; i++) {
                cout << (a[i] + j) % 3;
            }
            cout << endl;
        }
    } else {
        a[num] = 0;
        gen(num + 1);
        if (num == 0) {
            return;
        }
        a[num] = 1;
        gen(num + 1);
        a[num] = 2;
        gen(num + 1);
    }
}

int main() {
    freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);
    cin >> n;
    a.resize(n);
    gen(0);
    return 0;
}