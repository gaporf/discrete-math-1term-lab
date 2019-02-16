#include <bits/stdc++.h>

using namespace std;

vector<char> arr;
string str;

int getPosition(char a) {
    for (int i = 0; i < 26; i++) {
        if (arr[i] == a) {
            arr.erase(arr.begin() + i);
            arr.insert(arr.begin(), a);
            return i + 1;
        }
    }
}

int main() {
    freopen("mtf.in", "r", stdin);
    freopen("mtf.out", "w", stdout);
    cin >> str;
    for (char c = 'a'; c <= 'z'; c++) {
        arr.push_back(c);
    }
    for (int i = 0; str[i]; i++) {
        cout << getPosition(str[i]) << " ";
    }

    return 0;
}