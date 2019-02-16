#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

int main() {
    freopen("bwt.in", "r", stdin);
    freopen("bwt.out", "w", stdout);
    string str;
    cin >> str;
    int n = static_cast<int>(str.length());
    for (int i = 0; i < n; i++) {
        string newStr;
        for (int j = i; newStr.length() != n; j++, j %= n) {
            newStr += str[j];
        }
        arr.push_back(newStr);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i].back();
    }

    return 0;
}