#include <bits/stdc++.h>

using namespace std;

int n, m;

struct dez {
    vector<int> val, x;
    int undefinedValue;
    bool truth;
};

vector<dez> eq;

int main() {
    cin >> n >> m;
    eq.resize(m);
    for (int i = 0; i < m; i++) {
        eq[i].val.resize(static_cast<unsigned long>(n), -1);
        eq[i].x.resize(static_cast<unsigned long>(n));
        eq[i].undefinedValue = 0;
        eq[i].truth = false;
        for (int j = 0; j < n; j++) {
            cin >> eq[i].x[j];
            if (eq[i].x[j] != -1) {
                eq[i].undefinedValue++;
            }
        }
    }
    while (true) {
        int num = -1;
        for (int i = 0; i < m; i++) {
            if (eq[i].undefinedValue == 1 && !eq[i].truth) {
                num = i;
                break;
            }
        }
        if (num == -1) {
            break;
        }
        for (int j = 0; j < n; j++) {
            if (eq[num].val[j] == -1 && eq[num].x[j] != -1) {
                if (eq[num].x[j] == 1) {
                    for (int k = 0; k < m; k++) {
                        if (eq[k].x[j] != -1) {
                            eq[k].undefinedValue--;
                            eq[k].val[j] = 1;
                            if (eq[k].val[j] == eq[k].x[j]) {
                                eq[k].truth = true;
                            }
                        }
                    }
                } else {
                    for (int k = 0; k < m; k++) {
                        if (eq[k].x[j] != -1) {
                            eq[k].undefinedValue--;
                            eq[k].val[j] = 0;
                            if (eq[k].val[j] == eq[k].x[j]) {
                                eq[k].truth = true;
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (eq[i].x[j] != -1 && eq[i].val[j] == -1) {
                eq[i].val[j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        bool truth = false,
            find = false;
        for (int j = 0; j < n; j++) {
            if (eq[i].x[j] != -1) {
                find = true;
                if (eq[i].val[j] == eq[i].x[j]) {
                    truth = true;
                }
            }
        }
        if (!truth && find) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}