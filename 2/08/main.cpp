#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;

void gen(int num, int c) {
    if (num == k) {
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for (int K = c; K <= n; K++) {
            a[num] = K;
            gen(num + 1, K + 1);
        }
    }
}

int main() {
    //freopen("choose.in", "r", stdin);
    //freopen("choose.out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    gen(0, 1);

    return 0;
}