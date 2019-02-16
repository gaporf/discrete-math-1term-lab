#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string str;
stack<char> st;
int n;
vector<vector<ll> > dp;
ll k = 0;

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

void getNumber(int num, int depth) {
    if (num < n) {
        if (str[num] == '(') {
            st.push('(');
            getNumber(num + 1, depth + 1);
        } else {
            k += dp[n - num - 1][depth + 1] * myPow((n - num - 1 - (depth + 1)) / 2);
            if (str[num] == ')') {
                st.pop();
                getNumber(num + 1, depth - 1);
            } else {
                if (!st.empty() && st.top() == '(') {
                    k += dp[n - num - 1][depth - 1] * myPow((n - num - 1 - (depth - 1))/2);
                }
                if (str[num] == '[') {
                    st.push('[');
                    getNumber(num + 1, depth + 1);
                } else {
                    st.pop();
                    k += dp[n - num - 1][depth + 1] * myPow((n - num - 1 - (depth + 1))/2);;
                    getNumber(num + 1, depth - 1);
                }
            }
        }
    }
}

int main() {
    freopen("brackets2num2.in", "r", stdin);
    freopen("brackets2num2.out", "w", stdout);
    cin >> str;
    n = (int) str.length();
    countDP();
    getNumber(0, 0);
    cout << k << endl;
    return 0;
}