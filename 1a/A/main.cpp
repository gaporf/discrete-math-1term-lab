#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct code {
    ll p;
    vector<pair<ll, ll> > num;
};

ll ans = 0, e = -1;
int n;
vector<code> arr;

bool cmp(const code &a, const code &b) {
    if (a.p != b.p) {
        return a.p < b.p;
    } else {
        return a.num.size() < b.num.size();
    }
}

code unite(code a, code b) {
    code ans;
    ans.p = a.p + b.p;
    ans.num = a.num;
    ans.num.emplace_back(e, e);
    e--;
    for (int i = 0; i < b.num.size(); i++) {
        ans.num.push_back(b.num[i]);
    }
    return ans;
}

void dfs(code a, ll len = 0) {
    if (a.num.size() == 1) {
        ans += (ll) a.p * len;
    } else {
        ll min_e = -1;
        for (int i = 0; i < a.num.size(); i++) {
            min_e = min(min_e, a.num[i].first);
        }
        code A, B;
        A.p = 0;
        B.p = 0;
        for (int i = 0; i < a.num.size(); i++) {
            if (a.num[i].first == min_e) {
                for (int j = 0; j < i; j++) {
                    A.num.push_back(a.num[j]);
                    if (A.num.back().second > 0) {
                        A.p += A.num.back().second;
                    }
                }
                for (int j = i + 1; j < a.num.size(); j++) {
                    B.num.push_back(a.num[j]);
                    if (B.num.back().second > 0) {
                        B.p += B.num.back().second;
                    }
                }
                break;
            }
        }
        dfs(A, len + 1);
        dfs(B, len + 1);
    }
}

int main() {
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].p;
        arr[i].num.emplace_back(i, arr[i].p);
    }
    while (arr.size() > 1) {
        sort(arr.begin(), arr.end(), cmp);
        code a = arr[0],
                b = arr[1];
        arr.erase(arr.begin());
        arr.erase(arr.begin());
        arr.push_back(unite(a, b));
    }
    dfs(arr[0]);
    cout << ans;
    return 0;
}