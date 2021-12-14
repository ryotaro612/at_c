#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<ll> solve(ll h, ll w, ll c, ll q, vector<ll> &t, vector<ll> &n,
                 vector<ll> &cv) {
    //行か列 ->(色, 番号)
    unordered_map<ll, pair<ll, ll>> rows, cols;
    rep(i, q) {
        cv[i]--;
        if(t[i] == 1) { // 行
            rows[n[i]] = {cv[i], i};
        } else { // 列
            cols[n[i]] = {cv[i], i};
        }
    }
    // 行の番号
    vector<ll> row_index, col_index;
    for(auto e : rows)
        row_index.push_back(e.second.second);
    sort(row_index.begin(), row_index.end());
    for(auto e : cols)
        col_index.push_back(e.second.second);
    sort(col_index.begin(), col_index.end());
    vector<ll> res(c, 0);
    for(auto row : rows) {
        ll color = row.second.first;
        ll index = row.second.second;
        // cout << "row_index: " << row.first << " color: " << color
        //      << " index: " << index << endl;
        ll overwritten_num =
            col_index.end() -
            upper_bound(col_index.begin(), col_index.end(), index);
        res[color] += (w - overwritten_num);
    }
    for(auto col : cols) {
        ll color = col.second.first;
        ll index = col.second.second;
        // cout << "col_index: " << col.first << " color: " << color
        //      << " index: " << index << endl;
        ll overwritten_num =
            row_index.end() -
            upper_bound(row_index.begin(), row_index.end(), index);
        res[color] += (h - overwritten_num);
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    ll h, w, c, q;
    cin >> h >> w >> c >> q;
    vector<ll> t(q), n(q), cv(q);
    rep(i, q) cin >> t[i] >> n[i] >> cv[i];
    vector<ll> res = solve(h, w, c, q, t, n, cv);
    rep(i, res.size()) {
        cout << res[i];
        if(i == (int)res.size() - 1)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}

#endif