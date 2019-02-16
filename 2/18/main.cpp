#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string str;
int n;
ll k = 0;
vector<vector<ll> > dp;

ll get(int i, int j) {
    if (j < 0 || i < j) {
        return 0;
    } else {
        return dp[i][j];
    }
}

void countDP() {
    dp.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(n + 1, 0);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = get(i - 1, j - 1) + get(i - 1, j + 1);
        }
    }
}

void gen(int num, int depth) {
    if (num < n) {
        if (str[num] == ')') {
            k += dp[n - num - 1][depth + 1];
            gen(num + 1, depth - 1);
        } else {
            gen(num + 1, depth + 1);
        }
    }
}

int main() {
    freopen("brackets2num.in", "r", stdin);
    freopen("brackets2num.out", "w", stdout);
    cin >> str;
    n = (int) str.length();
    countDP();
    gen(0, 0);
    cout << k << endl;

    return 0;
}