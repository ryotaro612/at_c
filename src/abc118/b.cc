#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, int m, vector<int> k, vector<vector<int>> av) {

    vector<int> mp(m, 0);
    rep(i, n) {
        rep(j, k[i]) { mp[av[i][j] - 1]++; }
    }
    int res = 0;
    rep(i, m) if(mp[i] == n) res++;
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<vector<int>> av(n);
    rep(i, n) {
        cin >> k[i];
        av[i] = vector<int>(k[i]);
        rep(j, k[i]) { cin >> av[i][j]; }
    }
    cout << solve(n, m, k, av) << endl;
    return 0;
}
#endif