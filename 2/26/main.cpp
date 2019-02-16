#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<int> > arr;
bool EXIT = false;
set<int> elements;
vector<int> mx;

int strToNum(string str) {
    int ans = 0;
    reverse(str.begin(), str.end());
    for (int i = 0, j = 1; str[i]; i++, j *= 10) {
        ans += (str[i] - '0') * j;
    }
    return ans;
}

void get(vector<int> &v) {
    string str;
    getline(cin, str);
    string num;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            v.push_back(strToNum(num));
            num = "";
        } else {
            num += str[i];
        }
    }
    v.push_back(strToNum(num));
}

void add() {
    while (!elements.empty()) {
        int u = *elements.begin();
        elements.erase(elements.begin());
        vector<int> v;
        v.push_back(u);
        arr.push_back(v);
    }
}

void dfs(int n, int k) {
    if (n == -1) {
        add();
        return;
    }
    if (elements.upper_bound(mx[n]) != elements.end()) {
        int u = *elements.upper_bound(mx[n]);
        elements.erase(elements.find(u));
        arr[n].push_back(u);
        add();
        return;
    }
    int v = arr[n][k];
    mx[n] = arr[n][k];
    arr[n].erase(arr[n].begin() + k);
    if (k > 0 && elements.upper_bound(v) != elements.end()) {
        int u = *elements.upper_bound(v);
        elements.erase(elements.find(u));
        arr[n].push_back(u);
        elements.insert(v);
        add();
        return;
    }
    elements.insert(v);
    if (k == 0) {
        arr.erase(arr.begin() + arr.size());
        dfs(n - 1, static_cast<int>(arr[n - 1].size() - 1));
    } else {
        dfs(n, k - 1);
    }
}

void solve() {
    cin >> n >> k;
    string str;
    getline(cin, str);
    if (n == 0 && k == 0) {
        EXIT = true;
        return;
    }
    arr.resize(static_cast<unsigned int>(k));
    mx.resize(static_cast<unsigned long>(k));
    for (int i = 0; i < k; i++) {
        get(arr[i]);
        mx[i] = arr[i].back();
    }
    dfs(k - 1, static_cast<int>(arr[k - 1].size() - 1));
    cout << n << " " << arr.size() << endl;
    for (auto &i : arr) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    arr.clear();
    mx.clear();
}

int main() {
    freopen("nextsetpartition.in", "r", stdin);
    freopen("nextsetpartition.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    while (true) {
        solve();
        if (EXIT) {
            break;
        }
    }
    return 0;
}