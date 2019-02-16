#include <bits/stdc++.h>

using namespace std;

int n;
vector<char> arr;

void gen(int num, int balance) {
    if (num == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i];
        }
        cout << endl;
    } else {
        if (n - num - 1 >= balance + 1) {
            arr[num] = '(';
            gen(num + 1, balance + 1);
        }
        if (balance > 0) {
            arr[num] = ')';
            gen(num + 1, balance - 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("brackets.in", "r", stdin);
    //freopen("brackets.out", "w", stdout);
    cin >> n;
    n *= 2;
    arr.resize(n);
    gen(0, 0);
    return 0;
}