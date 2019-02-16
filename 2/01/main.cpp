#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

void gen(int num) {
    if (num == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
    } else {
        a[num] = 0;
        gen(num + 1);
        a[num] = 1;
        gen(num + 1);
    }
}
int main() {
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    cin >> n;
    a.resize(n);
    gen(0);

    return 0;
}