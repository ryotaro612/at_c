#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long double ld;
typedef long long ll;

vector<int> solve(int n, int k, vector<int> &p) {
    set<int> st;
    // cout << "foobar" << endl;
    rep(i, k) {
        // cout << p[i] << endl;
        st.insert(p[i]);
    }
    // cout << "doge" << endl;
    vector<int> res;
    res.push_back(*st.begin());
    for(int i = k; i < n; i++) {
        st.insert(p[i]);
        st.erase(st.begin());
        res.push_back(*st.begin());
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> res = solve(n, k, p);
    for(auto &e : res)
        cout << e << endl;
    return 0;
}
#endif