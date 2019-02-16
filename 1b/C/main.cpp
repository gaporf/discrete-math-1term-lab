#include <bits/stdc++.h>

using namespace std;

bool zero = true,
        one = true,
        self_dual = true,
        monoton = true,
        linear = true;

int n, k;
string value;
vector<int> a;
vector<char> b;
vector<vector<int> > A;

bool notPow(int a) {
    return (a & (a - 1)) != 0;
}

void buildPolynom() {
    vector<vector<char> > B;
    B.resize(b.size());
    for (int i = 0; i < b.size(); i++) {
        B[i].resize(b.size());
    }
    for (int i = 0; i < b.size(); i++) {
        B[0][i] = b[i];
    }
    for (int i = 1; i < B.size(); i++) {
        for (int j = 0; j < B.size() - i; j++) {
            B[i][j] = B[i - 1][j] ^ B[i - 1][j + 1];
        }
        if (notPow(i) && B[i][0]) {
            linear = false;
        }
    }
    B.clear();
}

void checkFunction() {
    if (b[0]) {
        zero = false;
    }
    if (!b.back()) {
        one = false;
    }
    for (int i = 0; i < b.size(); i++) {
        int new_num = 0;
        for (int j = 1, k = n - 1; k >= 0; k--, j *= 2) {
            if (!A[i][k]) {
                new_num += j;
            }
        }
        if (b[new_num] == b[i]) {
            self_dual = false;
        }
        for (int j = i + 1; j < b.size(); j++) {
            bool yes = true;
            for (int k = 0; k < n; k++) {
                if (A[i][k] && !A[j][k]) {
                    yes = false;
                    break;
                }
            }
            if (yes && b[i] && !b[j]) {
                monoton = false;
            }
        }
    }
    buildPolynom();
}

void gen(int num) {
    if (num < n) {
        a[num] = 0;
        gen(num + 1);
        a[num] = 1;
        gen(num + 1);
    } else {
        b.push_back(value[k++] == '1');
        A.push_back(a);
    }
}

void check() {
    k = 0;
    cin >> n;
    cin >> value;
    a.resize(n);
    gen(0);
    checkFunction();
    b.clear();
    a.clear();
    A.clear();
}

bool complete() {
    return !zero && !one && !self_dual && !monoton && !linear;
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        check();
    }
    (complete()) ? cout << "YES" : cout << "NO";

    return 0;
}