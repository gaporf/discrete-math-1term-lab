#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll> > dp;
vector<char> ans;
int n;
ll k;

ll get(int i, int j) {
    if (j < 0) {
        return 0;
    } else {
        return dp[i][j];
    }
}

void countDP() {
    dp.resize(static_cast<unsigned long>(2 * n + 1));
    for (int i = 0; i <= 2 * n; i++) {
        dp[i].resize(static_cast<unsigned long>(2 * n + 1), 0);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = get(i - 1, j - 1) + get(i - 1, j + 1);
        }
    }
}

void gen(int num, int depth) {
    if (num < 2 * n) {
        if (depth == 0) {
            ans[num] = '(';
            gen(num + 1, depth + 1);
        } else {
            if (dp[2 * n - num - 1][depth + 1] > 0 && k < dp[2 * n - num - 1][depth + 1]) {
                ans[num] = '(';
                gen(num + 1, depth + 1);
            } else {
                k -= dp[2 * n - num - 1][depth + 1];
                ans[num] = ')';
                gen(num + 1, depth - 1);
            }
        }
    }
}

int main() {
    //freopen("num2brackets.in", "r", stdin);
    //freopen("num2brackets.out", "w", stdout);
    cin >> n >> k;
    countDP();
    ans.resize(static_cast<unsigned long>(2 * n));
    gen(0, 0);
    for (int i = 0; i < 2 * n; i++) {
        cout << ans[i];
    }
    return 0;
}