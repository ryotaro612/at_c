#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const int INF = 1000001;

int solve(int n, int m, vector<int> &a, vector<int> &b) {
    vector<pair<int, int>> ab(m);
    rep(i, m) ab[i] = {a[i], b[i]};

    sort(ab.begin(), ab.end(),
         [](const pair<int, int> x, const pair<int, int> y) {
             if(x.first != y.first)
                 return x.first < y.first;
             return x.second > y.second;
         });

    vector<int> dp(m, INF), sorted_b(m);
    rep(i, m) sorted_b[i] = ab[i].second;
    rep(i, m) { *lower_bound(dp.begin(), dp.end(), sorted_b[i]) = sorted_b[i]; }
    int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();

    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    cout << solve(n, m, a, b) << endl;
    return 0;
}
#endif