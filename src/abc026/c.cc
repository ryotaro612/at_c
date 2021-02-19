#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int dfs(int num, vector<vector<int>> &tree) {

    if((int)tree[num].size() == 0)
        return 1;
    int max_s = -1, min_s = 10000000;
    for(int i = 0; i < (int)tree[num].size(); i++) {
        max_s = max(dfs(tree[num][i], tree), max_s);
        min_s = min(dfs(tree[num][i], tree), min_s);
    }
    return max_s + min_s + 1;
}

int solve(int n, vector<int> b) {
    vector<vector<int>> tree(n);
    for(int i = 0; i < n - 1; i++) {
        tree[b[i] - 1].push_back(i + 1);
    }

    return dfs(0, tree);
}
/*
int main() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    cout << solve(n, b) << endl;
}
*/