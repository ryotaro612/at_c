#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int m, vector<int> x, vector<int> y) {
    int res = 1;
    vector<vector<int>> buddies(n);
    for(int i = 0; i < m; i++) {
        buddies[x[i] - 1].push_back(y[i] - 1);
        buddies[y[i] - 1].push_back(x[i] - 1);
    }
    for(int i = 1; i < 1 << n; i++) {
    }

    return res;
}
/*
int main() {
    int n, m;
    cin >> n, m;
    vector<int> x(m), y(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, m, x, y) << endl;
}
*/