#include <bits/stdc++.h>

using namespace std;

int n, m;

int myPow(int a) {
    int ans = 1;
    for (int i = 0; i < a; i++) {
        ans *= 2;
    }
    return ans;
}

vector<int> value;
vector<string> strings;

int main() {
    cin >> n;
    m = myPow(n);
    value.resize(m);
    strings.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> strings[i] >> value[i];
    }
    for (int i = 0; i < m; i++) {
        cout << strings[i] << " " << value[0] << endl;
        vector<int> new_value(value.size() - 1);
        for (int i = 0; i + 1 < value.size(); i++) {
            new_value[i] = value[i] ^ value[i + 1];
        }
        value = new_value;
    }

    return 0;
}