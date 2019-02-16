/* 0 - a && b
 * 1 - ~a && b
 * 2 - a && ~b
 * 3 - ~a && ~b
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<vector<char> > > val;
vector<char> a;

void check() {
    bool one = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] && a[j] && val[3][i][j]) {
                one = false;
            } else if (!a[i] && a[j] && val[2][i][j]) {
                one = false;
            } else if (a[i] && !a[j] && val[1][i][j]) {
                one = false;
            } else if (!a[i] && !a[j] && val[0][i][j]) {
                one = false;
            }
        }
    }
    if (one) {
        cout << "NO";
        exit(0);
    }
}

void gen(int num) {
    if (num < n) {
        a[num] = false;
        gen(num + 1);
        a[num] = true;
        gen(num + 1);
    } else {
        check();
    }
}

int main() {
    cin >> n >> m;
    a.resize(n);
    val.resize(4);
    for (int i = 0; i < 4; i++) {
        val[i].resize(n);
        for (int j = 0; j < n; j++) {
            val[i][j].resize(n, false);
        }
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a > 0 && b > 0) {
            a--;
            b--;
            val[0][a][b] = val[0][b][a] = true;
        } else if (a < 0 && b > 0) {
            a = -a;
            a--;
            b--;
            val[1][a][b] = val[2][b][a] = true;
        } else if (a > 0 && b < 0) {
            a--;
            b = -b;
            b--;
            val[2][a][b] = val[1][b][a] = true;
        } else if (a < 0 && b < 0) {
            a = -a;
            b = -b;
            a--;
            b--;
            val[3][a][b] = val[3][b][a] = true;
        }
    }
    gen(0);
    cout << "YES";

    return 0;
}