#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(int row, int n, int k, vector<int> &selected, vector<vector<int>> &t) {
    if(row == n) {
        int temp = 0;
        for(int i = 0; i < n; i++) {
            temp = temp ^ selected[i];
        }
        return temp == 0;
    }
    for(int i = 0; i < k; i++) {
        selected.push_back(t[row][i]);
        if(dfs(row + 1, n, k, selected, t))
            return true;
        selected.pop_back();
    }
    return false;
}

string solve(int n, int k, vector<vector<int>> t) {
    vector<int> selected;
    return dfs(0, n, k, selected, t) ? "Found" : "Nothing";
}
/*
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(k));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> t[i][j];
        }
    }
    cout << solve(n, k, t) << endl;
}
*/