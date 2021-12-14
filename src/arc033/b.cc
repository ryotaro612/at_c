#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

double solve(int a, int b, vector<int> &av, vector<int> &bv) {

    // unordered_set<int> as(av.begin(), av.end());
    // unordered_set<int> bs(bv.begin(), bv.end());
    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());
    unordered_set<int> inter, uni;
    set_intersection(av.begin(), av.end(), bv.begin(), bv.end(),
                     inserter(inter, inter.end()));
    set_union(av.begin(), av.end(), bv.begin(), bv.end(),
              inserter(uni, uni.end()));
    // cout << inter.size() << endl;
    // cout << uni.size() << endl;
    return (double)inter.size() / (double)uni.size();
}

#ifdef ONLINE_JUDGE
int main() {
    int a, b;
    cin >> a >> b;
    vector<int> av(a), bv(b);
    rep(i, a) cin >> av[i];
    rep(i, b) cin >> bv[i];
    cout << fixed << setprecision(12) << solve(a, b, av, bv) << endl;
}
#endif