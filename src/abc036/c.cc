#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(int n, vector<ll> a) {
    set<ll> a_set;
    for(auto aa : a) {
        a_set.insert(aa);
    }
    vector<ll> order;
    for(auto aa : a_set) {
        order.push_back(aa);
    }
    map<ll, ll> d;
    for(int i = 0; i < (int)order.size(); i++) {
        d[order[i]] = i;
    }
    vector<ll> res(n);
    for(int i = 0; i < n; i++) {
        res[i] = d[a[i]];
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> res = solve(n, a);
    for(int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
}
#endif