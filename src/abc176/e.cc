// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int h, int w, int m, vector<int> hv, vector<int> wv) {
    for(int i = 0; i < m; i++)
        wv[i]--;
    for(int i = 0; i < m; i++)
        hv[i]--;

    vector<pair<int, int>> c_w(w), c_h(h);
    for(int i = 0; i < w; i++)
        c_w[i] = {0, i};
    for(int i = 0; i < h; i++)
        c_h[i] = {0, i};
    for(ll i = 0; i < m; i++) {
        c_w[wv[i]] = {c_w[wv[i]].first + 1, c_w[wv[i]].second};
        c_h[hv[i]] = {c_h[hv[i]].first + 1, c_h[hv[i]].second};
    }
    sort(c_w.begin(), c_w.end());
    sort(c_h.begin(), c_h.end());

    int mx_w = c_w[w - 1].first, count_w;
    vector<bool> cand_w(w, false);
    for(int i = w - 1; i >= 0; i--) {
        if(c_w[i].first == mx_w) {
            cand_w[c_w[i].second] = true;
            count_w++;
        } else
            break;
    }
    vector<int> count(h, 0);
    for(int i = 0; i < m; i++)
        if(cand_w[wv[i]])
            count[hv[i]]++;
    for(int i = h - 1; i >= 0; i--) {
        if(c_h[i].first == c_h[h - 1].first) {
            if(count[c_h[i].second] < count_w)
                return mx_w + c_h[h - 1].first;
        } else
            break;
    }
    return mx_w + c_h[h - 1].first - 1;
}

#ifndef _debug
int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> hv(m), wv(m);
    for(int i = 0; i < m; i++) {
        cin >> hv[i] >> wv[i];
    }
    cout << solve(h, w, m, hv, wv) << endl;

    return 0;
}
#endif