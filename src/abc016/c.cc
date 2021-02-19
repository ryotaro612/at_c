#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static int INF = 100000;
vector<int> solve(int n, int m, vector<int> a, vector<int> b) {
    vector<vector<int>> d(n, vector<int>(n, INF));
    for(int i=0;i<n;i++) {
        d[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        a[i]--;
        b[i]--;
        d[a[i]][b[i]] = d[b[i]][a[i]] = 1;
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(d[i][j] == 2)
                res[i]++;
        }
    }
    return res;
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> res = solve(n, m, a, b);
    for(int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
}
*/