#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull w = 4294967295;

int n;
vector<ull> arr;
ull s;
vector<char> used;

void check() {
    vector<ull> cur;
    int m = 1;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            cur.push_back(i);
            m *= 2;
        }
    }
    vector<ull> qr(m, 2);
    if (cur.size() == 0) {
        return;
    }
    for (ull i = 0, j = 1; i < 40; i++, j *= 2) {
        ull y = 0;
        for (ull k = 0, l = 1; k < cur.size(); k++, l *= 2) {
            y += ((arr[cur[k]] & j) != 0) * l;
        }
        if (qr[y] == 2) {
            qr[y] = ((s & j) != 0);
        } else {
            if (qr[y] != ((s & j) != 0)) {
                return;
            }
        }
    }
    bool yes = false;
    for (ull i = 0, j = 1; i < 40; i++, j *= 2) {
        ull y = 0;
        for (ull k = 0, l = 1; k < cur.size(); k++, l *= 2) {
            y += ((arr[cur[k]] & j) != 0) * l;
        }
        if (qr[y] == 1) {
            if (yes) {
                cout << "|";
            }
            yes = true;
            cout << "(";
            for (ull k = 0; k < cur.size(); k++) {
                if (k != 0) {
                    cout << "&";
                }
                if ((arr[cur[k]] & j) == 0) {
                    cout << "~" << cur[k] + 1;
                } else {
                    cout << cur[k] + 1;
                }
            }
            cout << ")";
        }
    }
    exit(0);
}

void gen(int num) {
    if (num == n) {
        check();
    } else {
        used[num] = false;
        gen(num + 1);
        used[num] = true;
        gen(num + 1);
    }
}

int main() {
    cin >> n;
    arr.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long S;
    cin >> S;
    if (S < 0 || S > w) {
        cout << "Impossible";
        return 0;
    }
    s = (ull) S;
    if (s == 0) {
        cout << "1&~1";
        return 0;
    }
    gen(0);
    cout << "Impossible";

    return 0;
}