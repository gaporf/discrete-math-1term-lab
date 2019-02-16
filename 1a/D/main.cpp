#include <bits/stdc++.h>

using namespace std;

vector<string> code;
string str;

int findCode(string a) {
    for (int i = 0; i < code.size(); i++) {
        if (code[i] == a) {
            return i;
        }
    }
    return -1;
}

void setCode(string a) {
    code.push_back(a);
}

int main() {
    freopen("lzw.in", "r", stdin);
    freopen("lzw.out", "w", stdout);
    for (char a = 'a'; a <= 'z'; a++) {
        string str;
        str += a;
        code.push_back(str);
    }
    cin >> str;
    string cur;
    cur += str[0];
    for (int i = 1; str[i]; i++) {
        string newCur = cur + str[i];
        int a = findCode(newCur);
        if (a != -1) {
            cur = newCur;
        } else {
            cout << findCode(cur) << " ";
            setCode(newCur);
            cur = "";
            cur += str[i];
        }
    }
    cout << findCode(cur);

    return 0;
}