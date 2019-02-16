#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<char> used;

void gen(int num) {
    if (num == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] + 1 << " ";
        }
        cout << endl;
    } else {
        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                a[num] = j;
                used[j] = true;
                gen(num + 1);
                used[j] = false;
            }
        }
    }
}

int main() {
    freopen("permutations.in", "r", stdin);
    freopen("permutations.out", "w", stdout);
    cin >> n;
    a.resize(n);
    used.resize(n, false);
    gen(0);
    return 0;
}