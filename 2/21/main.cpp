#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll r;
vector<vector<ll> > dp;

void countDP() {
    dp.resize(static_cast<unsigned long>(n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i].resize(static_cast<unsigned long>(n + 1), 0);
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = i; k >= j; k--) {
                dp[i][j] += dp[i - k][k];
            }
        }
    }
}

int main() {
    freopen("num2part.in", "r", stdin);
    freopen("num2part.out", "w", stdout);
    cin >> n >> r;
    countDP();
    bool plus = false;
    for (int i = 1; n > 0; ) {
        if (dp[n - i][i] > r) {
            if (plus) {
                cout << "+";
            }
            cout << i;
            n -= i;
            plus = true;
        } else {
            r -= dp[n - i][i];
            i++;
        }
    }
    cout << endl;
    return 0;
}