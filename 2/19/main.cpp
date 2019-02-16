#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll> > dp;
vector<char> ans;
stack<char> st;
int n;
ll k;

ll myPow(ll a) {
    ll ans = 1;
    for (int i = 0; i < a; i++) {
        ans *= 2;
    }
    return ans;
}

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
        dp[i].resize(n + 1);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = (get(i - 1, j - 1) + get(i - 1, j + 1));
        }
    }
}

void gen(int num, int depth) {
    if (num == n) {
        cout << endl;
    } else {
        if (dp[n - num - 1][depth + 1] > 0 && k < dp[n - num - 1][depth + 1] * myPow((n - num - 1 - (depth + 1))/2)) {
            cout << "(";
            st.push('(');
            gen(num + 1, depth + 1);
        } else {
            k -= dp[n - num - 1][depth + 1] * myPow((n - num - 1 - (depth + 1))/2);
            if (!st.empty() && st.top() == '(' && depth >= 1 && k < dp[n - num - 1][depth - 1] * myPow((n - num - 1 - (depth - 1))/2)) {
                cout << ")";
                st.pop();
                gen(num + 1, depth - 1);
            } else {
                if (!st.empty() && st.top() == '(') {
                    k -= dp[n - num - 1][depth - 1] * myPow((n - num - 1 - (depth - 1))/2);
                }
                if (dp[n - num - 1][depth + 1] > 0 && k < dp[n - num - 1][depth + 1] * myPow((n - num - 1 - (depth + 1))/2)) {
                    cout << "[";
                    st.push('[');
                    gen(num + 1, depth + 1);
                } else {
                    k -= dp[n - num - 1][depth + 1] * myPow((n - num - 1 - (depth + 1))/2);
                    cout << ']';
                    st.pop();
                    gen(num + 1, depth - 1);
                }
            }
        }
    }
}

int main() {
    freopen("num2brackets2.in", "r", stdin);
    freopen("num2brackets2.out", "w", stdout);
    cin >> n >> k;
    n *= 2;
    countDP();
    gen(0, 0);
    return 0;
}