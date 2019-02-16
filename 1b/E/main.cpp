#include <bits/stdc++.h>

using namespace std;

struct element {
    int n, m, value;
    vector<int> child;
    vector<int> table;
};

int myPow(int a) {
    int ans = 1;
    for (int i = 0; i < a; i++) {
        ans *= 2;
    }
    return ans;
}

int n;
vector<element> arr;
vector<int> nums;

int dfs(int num) {
    if (arr[num].n == 0) {
        return arr[num].value;
    } else {
        int y = 0;
        for (int i = 0; i < arr[num].n; i++) {
            y *= 2;
            y += dfs(arr[num].child[i]);
        }
        return arr[num].table[y];
    }
}

void gen(int num) {
    if (num == nums.size()) {
        cout << dfs(static_cast<int>(arr.size() - 1));
    } else {
        arr[nums[num]].value = 0;
        gen(num + 1);
        arr[nums[num]].value = 1;
        gen(num + 1);
    }
}

int findDeep(int num) {
    if (arr[num].n == 0) {
        return 0;
    } else {
        int ans = 0;
        for (int i = 0; i < arr[num].n; i++) {
            ans = max(ans, findDeep(arr[num].child[i]));
        }
        return ans + 1;
    }
}

int main() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].n;
        if (arr[i].n > 0) {
            arr[i].m = myPow(arr[i].n);
            arr[i].child.resize(static_cast<unsigned long>(arr[i].n));
            for (int j = 0; j < arr[i].n; j++) {
                cin >> arr[i].child[j];
                --arr[i].child[j];
            }
            arr[i].table.resize(static_cast<unsigned long>(arr[i].m));
            for (int j = 0; j < arr[i].m; j++) {
                cin >> arr[i].table[j];
            }
        } else {
            nums.push_back(i);
        }
    }
    cout << findDeep(static_cast<int>(arr.size() - 1)) << endl;
    gen(0);

    return 0;
}