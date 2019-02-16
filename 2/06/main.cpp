#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<vector<int> > ans;

void gen(int num) {
    if (num == n) {
        ans.push_back(a);
    } else {
        if (num == 0) {
            a[num] = 0;
            gen(num + 1);
            a[num] = 1;
            gen(num + 1);
        } else {
            a[num] = 0;
            gen(num + 1);
            if (a[num - 1] != 1) {
                a[num] = 1;
                gen(num + 1);
            }
        }
    }
}
int main() {
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    cin >> n;
    a.resize(n);
    gen(0);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}