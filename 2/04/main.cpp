#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> vek;
map<vector<int>, bool> mp;

void print() {
    for (int i = 0; i < n; i++) {
        cout << vek[i];
    }
    cout << endl;
}

int main() {
    freopen("chaincode.in", "r", stdin);
    freopen("chaincode.out", "w", stdout);
    cin >> n;
    vek.resize(static_cast<unsigned long>(n));
    for (int i = 0; i < n; i++) {
        vek[i] = 0;
    }
    print();
    mp[vek] = true;
    while (true) {
        vector<int> newVek(n);
        for (int i = 1; i < n; i++) {
            newVek[i - 1] = vek[i];
        }
        newVek[n - 1] = 1;
        if (!mp[newVek]) {
            vek = newVek;
            mp[vek] = true;
            print();
        } else {
            newVek[n - 1] = 0;
            if (!mp[newVek]) {
                vek = newVek;
                mp[vek] = true;
                print();
            } else {
                break;
            }
        }
    }
    return 0;
}