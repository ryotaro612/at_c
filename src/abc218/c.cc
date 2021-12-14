#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<string> rotate_grid(int n, vector<string> s) {
    vector<string> res(n, string(n, ' '));

    rep(i, n) {
        rep(j, n) { res[i][j] = s[j][n - 1 - i]; }
    }
    return res;
}

vector<pair<int, int>> rorate_sharps(int n, vector<pair<int, int>> sharps) {

    rep(i, sharps.size()) {
        auto p = sharps[i];
        sharps[i] = {p.second, n - 1 - p.first};
    }
    return sharps;
}

string solve(int n, vector<string> &s, vector<string> &t) {

    vector<pair<int, int>> sharps;
    rep(i, n) {
        rep(j, n) {
            if(s[i][j] == '#')
                sharps.push_back({i, j});
        }
    }
    pair<int, int> origin = sharps[0];
    rep(i, sharps.size()) {
        auto p = sharps[i];
        sharps[i] = {p.first - origin.first, p.second - origin.second};
    }

    vector<pair<int, int>> t_sharps;
    rep(k, 4) {
        rep(i, n) {
            rep(j, n) {
                if(t[i][j] == '#')
                    t_sharps.push_back({i, j});
            }
        }
        origin = t_sharps[0];
        rep(i, t_sharps.size()) {
            auto p = t_sharps[i];
            t_sharps[i] = {p.first - origin.first, p.second - origin.second};
        }
        if(sharps == t_sharps)
            return "Yes";
		t = rotate_grid(n, t);
		t_sharps = vector<pair<int, int>>();
    }

    return "No";
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    cout << solve(n, s, t) << endl;
}
#endif