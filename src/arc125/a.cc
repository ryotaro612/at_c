#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const int INF = 1000000;

bool satisfied(vector<int> &s, vector<int> &t) {
    set<int> ss, st;
    for(auto e : s)
        ss.insert(e);
    for(auto e : t)
        st.insert(e);
    for(auto e : st) {
        if(ss.find(e) == ss.end())
            return false;
    }
    return true;
}

bool is_mono(vector<int> &t) {
    set<int> st;
    for(auto e : t)
        st.insert(e);
    return st.size() == 1;
}

ll solve(int n, int m, vector<int> &s, vector<int> &t) {
    if(!satisfied(s, t))
        return -1ll;
    if(is_mono(t)&& is_mono(s))
        return t.size();

    int left = 0, right = 0;
    for(int i = 0;;) {
        int next_i = (i + 1) % n;
        right++;
        if(s[i] != s[next_i]) {
            break;
        } else
            i = next_i;
    }
    for(int i = 0;;) {
        int prev_i = (n + i - 1) % n;
        left++;
        if(s[i] != s[prev_i]) {
            break;
        } else
            i = prev_i;
    }

    ll ans = 0ll;
    bool moved = false;
    int digit = s[0];
    for(auto e : t) {
        if(digit != e) {
            if(!moved) {
                ans += min(left, right);
                moved = true;
            } else {
                ans++;
            }
            digit = e;
        }
        ans++;
    }
    return ans;
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];
    cout << solve(n, m, s, t) << endl;
    return 0;
}
#endif