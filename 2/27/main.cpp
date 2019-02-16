#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string str;
int n;
vector<int> balance;

void dfs(int num, int balance) {
    if (num < n) {
        if (n - num - 1 >= balance + 1) {
            str[num] = '(';
            dfs(num + 1, balance + 1);
        } else {
            str[num] = ')';
            dfs(num + 1, balance - 1);
        }
    }
}

void check() {
    for (int i = 0; i < n; i += 2) {
        if (str[i] == ')' || str[i + 1] == '(') {
            return;
        }
    }
    cout << "-" << endl;
    exit(0);
}

void gen(int num) {
    if (str[num] == '(' && balance[num - 1] > 0) {
        str[num] = ')';
        balance[num] = balance[num - 1] - 1;
        dfs(num + 1, balance[num]);
        return;
    } else {
        gen(num - 1);
    }
}

int main() {
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    cin >> str;
    n = (int) str.length();
    check();
    balance.resize(n);
    for (int i = 0, b = 0; i < n; i++) {
        if (str[i] == '(') {
            b++;
        } else {
            b--;
        }
        balance[i] = b;
    }
    gen(n - 1);
    cout << str << endl;
    return 0;
}