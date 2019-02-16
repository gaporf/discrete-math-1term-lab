#include <bits/stdc++.h>

using namespace std;

string str;
int n;

bool zero() {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '1') {
            return false;
        }
    }
    return true;
}

bool one() {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '0') {
            return false;
        }
    }
    return true;
}

string getLast() {
    string ans = str;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '1') {
            ans[i] = '0';
            for (int j = i + 1; j < n; j++) {
                ans[j] = '1';
            }
            break;
        }
    }
    return ans;
}

string getNext() {
    string ans = str;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '0') {
            ans[i] = '1';
            for (int j = i + 1; j < n; j++) {
                ans[j] = '0';
            }
            break;
        }
    }
    return ans;
}

int main() {
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> str;
    n = (int) str.length();
    if (zero()) {
        cout << "-" << endl;
    } else {
        cout << getLast() << endl;
    }
    if (one()) {
        cout << "-" << endl;
    } else {
        cout << getNext() << endl;
    }
    return 0;
}