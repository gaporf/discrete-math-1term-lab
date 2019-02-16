#include <bits/stdc++.h>

using namespace std;

int n;

int myPow(int a) {
    int ans = 1;
    for (int i = 0; i < a; i++) {
        ans *= 2;
    }
    return ans;
}

string getNumber(int a) {
    string ans;
    for (int i = 1, j = 1; i <= n; i++, j *= 2) {
        ans += std::to_string((a & j) != 0);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    freopen("gray.in", "r", stdin);
    freopen("gray.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < myPow(n); i++) {
        cout << getNumber(i ^ (i / 2)) << endl;
    }
    return 0;
}