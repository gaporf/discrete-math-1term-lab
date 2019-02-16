#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string str;
vector<int> arr;
vector<vector<ll> > dp;
int n = 0;
ll r = 0;

int stringToInt(string a) {
    int ans = 0;
    reverse(a.begin(), a.end());
    for (int i = 0, j = 1; a[i]; i++, j *= 10) {
        ans += (int) (a[i] - '0') * j;
    }
    return ans;
}

void handle() {
    string num;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '+') {
            arr.push_back(stringToInt(num));
            n += arr.back();
            num = "";
        } else {
            num += str[i];
        }
    }
    arr.push_back(stringToInt(num));
    n += arr.back();
}

void countDP() {
    dp.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(n + 1, 0);
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
    freopen("part2num.in", "r", stdin);
    freopen("part2num.out", "w", stdout);
    cin >> str;
    handle();
    countDP();
    for (int i = 0, cur = 1; i < arr.size(); i++) {
        while (cur < arr[i]) {
            r += dp[n - cur][cur];
            cur++;
        }
        n -= cur;
    }
    cout << r << endl;
    return 0;
}