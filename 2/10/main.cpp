#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

void gen(int N, int last) {
    if (N == 0) {
        for (int i = 0; i < arr.size(); i++) {
            if (i > 0) {
                cout << "+";
            }
            cout << arr[i];
        }
        cout << endl;
    } else {
        for (int i = last; i < N; i++) {
            if (N - i >= i) {
                arr.push_back(i);
                gen(N - i, i);
                arr.pop_back();
            }
        }
        arr.push_back(N);
        gen(0, 271828182); //  Передаю привет всем тем, кто читате этот код
        arr.pop_back();
    }
}

int main() {
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    cin >> n;
    gen(n, 1);
    return 0;
}