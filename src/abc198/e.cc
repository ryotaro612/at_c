#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

void dfs(int index, vector<int> &res, vector<int> &c, map<int, int> &count,
         vector<vector<int>> &g, vector<bool> &pass) {
    pass[index] = true;
    if(count[c[index]] == 0) {
        res.push_back(index + 1);
    }
    count[c[index]]++;
    for(int i = 0; i < g[index].size(); i++) {
        if(!pass[g[index][i]]) {
            dfs(g[index][i], res, c, count, g, pass);
        }
    }
    count[c[index]]--;
}

vector<int> solve(int n, vector<int> c, vector<int> a, vector<int> b) {
    vector<vector<int>> g(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        g[a[i] - 1].push_back(b[i] - 1);
        g[b[i] - 1].push_back(a[i] - 1);
    }
    vector<bool> pass(n, false);
    vector<int> res;
    map<int, int> count;
    dfs(0, res, c, count, g, pass);
    sort(res.begin(), res.end());
    return res;
}
#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> a(n - 1), b(n - 1);
    for(int i = 0; i < n - 1; i++)
        cin >> a[i] >> b[i];

    vector<int> res = solve(n, c, a, b);
    for(auto r : res)
        cout << r << endl;

    return 0;
}
#endif