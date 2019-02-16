#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k, a = 1;
vector<ll> arr;

int main() {
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);
    cin >> n >> k;
    for (ll i = 1; i < n; i++) {
        a *= i;
    }
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    for (int i = n; i >= 1; i--) {
        int num = (int) (k / a);
        k %= a;
        if (i != 1) {
            a /= ll(i - 1);
        }
        cout << arr[num] << " ";
        arr.erase(arr.begin() + num);
    }
    cout << endl;
    return 0;
}