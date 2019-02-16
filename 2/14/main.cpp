#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans = 0, a = 1;
int n;
vector<int> arr, per;

int main() {
    //freopen("perm2num.in", "r", stdin);
    //freopen("perm2num.out", "w", stdout);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 1; i < n; i++) {
        a *= (ll) i;
    }
    per.resize(n);
    for (int i = 0; i < n; i++) {
        per[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < per.size(); j++) {
            if (per[j] == arr[i]) {
                ans += a * (ll) j;
                per.erase(per.begin() + j);
                break;
            }
        }
        if (i + 1 != n) {
            a /= (ll) (n - i - 1);
        }
    }
    cout << ans;
    return 0;
}