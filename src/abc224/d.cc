#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string encode(vector<int> p) {
    string s;
    for(auto e : p)
        s.push_back(e + '0');
    return s;
}

int find_vacant(vector<int> p) {
    vector<bool> v(9, true);
    rep(i, 8) { v[p[i]] = false; }
    rep(i, v.size()) {
        if(v[i])
            return i;
    }
    assert(false);
}
/*
pに含まれない文字のノードが空いている
*/
int get_vacant(string p) {
    vector<bool> v(9, true);
    rep(i, 8) { v[p[i] - '0'] = false; }
    rep(i, v.size()) {
        if(v[i])
            return i;
    }
    assert(false);
}

int solve(int m, vector<int> &u, vector<int> &v, vector<int> &p) {
    vector<vector<int>> g(9);
    rep(i, m) {
        g[u[i] - 1].push_back(v[i] - 1);
        g[v[i] - 1].push_back(u[i] - 1);
    }
    rep(i, 8) p[i]--;

    priority_queue<pair<int, string>, vector<pair<int, string>>,
                   greater<pair<int, string>>>
        que;
    unordered_map<string, int> d;
    d[encode(p)] = 0;
    que.push({0, encode(p)});
    while(!que.empty()) {
        pair<int, string> p = que.top();
        que.pop();
        string v = p.second;
        if(d.find(v) != d.end() && d[v] < p.first)
            continue;
        int vacant = get_vacant(v);
        rep(i, g[vacant].size()) {
            char neighbor = g[vacant][i] + '0';
            string next_p = string(v);
            rep(i, 8) {
                if(neighbor == v[i]) {
                    next_p[i] = vacant + '0';
                    break;
                }
            }
            //cout << v << " -> " << next_p << " vacant: " << vacant << endl;
            if(d.find(next_p) == d.end() || d[next_p] > d[v] + 1) {
                d[next_p] = d[v] + 1;
                que.push({d[next_p], next_p});
            }
        }
    }
    if(d.find("01234567") == d.end())
        return -1;
    return d["01234567"];
}

#ifdef ONLINE_JUDGE
int main() {
    int m;
    cin >> m;
    vector<int> u(m), v(m);
    rep(i, m) cin >> u[i] >> v[i];
    vector<int> p(8);
    rep(i, 8) cin >> p[i];
    cout << solve(m, u, v, p) << endl;
    return 0;
}
#endif