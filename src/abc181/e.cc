#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll calc_diff(ll v, vector<ll> &w) {
    auto iter = lower_bound(w.begin(), w.end(), v);
    int i = distance(w.begin(), iter);
    vector<ll> cands;
    if(i == (int)w.size())
        cands.push_back(w[i - 1]);
    else {
        cands.push_back(w[i]);
        if(i != 0)
            cands.push_back(w[i - 1]);
    }
    ll diff = 100000000000ll;
    for(auto c : cands)
        diff = min(diff, abs(v - c));
    return diff;
}

ll solve(int n, int m, vector<ll> h, vector<ll> w) {
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());
    ll teacher_diff = calc_diff(h[0], w);
    ll res = teacher_diff, temp;
    for(int i = 1; i < n - 1; i += 2)
        res += abs(h[i] - h[i + 1]);
    temp = res;

    for(int i = 1; i < n - 1; i += 2) {
        temp -= (teacher_diff + abs(h[i] - h[i + 1]));
        teacher_diff = calc_diff(h[i], w);
        temp += (teacher_diff + abs(h[i - 1] - h[i + 1]));
        res = min(temp, res);

        temp -= (teacher_diff + abs(h[i - 1] - h[i + 1]));
        teacher_diff = calc_diff(h[i + 1], w);
        temp += (teacher_diff + abs(h[i - 1] - h[i]));
        res = min(temp, res);
    }
    return res;
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n), w(m);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < m; i++)
        cin >> w[i];
    cout << solve(n, m, h, w) << endl;
}
#endif