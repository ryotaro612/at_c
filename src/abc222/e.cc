#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
ll const MOD = 998244353ll;

struct Node {
    int parent;
    unordered_set<int> children;
};

struct Tree {
    Tree(vector<int> &u, vector<int> &v) {
        int n = (int)u.size() + 1;
        nodes.resize(n);
        rep(i, n - 1) {
            nodes[u[i]].children.insert(v[i]);
            nodes[v[i]].children.insert(u[i]);
        }
        define_parent(-1, 0);
    }

    vector<int> paths(int a, int b) {
        vector<int> path_a = path_to_root(a);
        vector<int> path_b = path_to_root(b);

        unordered_set<int> b_set(path_b.begin(), path_b.end());
        int nearest;
        vector<int> res;
        rep(i, path_a.size()) {
            res.push_back(path_a[i]);
            if(b_set.find(path_a[i]) != b_set.end()) {
                nearest = path_a[i];
                break;
            }
        }
        vector<int> after;
        rep(i, path_b.size()) {
            if(path_b[i] == nearest)
                break;
            after.push_back(path_b[i]);
        }
        reverse(after.begin(), after.end());
        res.insert(res.end(), after.begin(), after.end());
        return res;
    }

    vector<int> path_to_root(int index) {
        vector<int> res;
        rec_path_to_root(index, res);
        return res;
    }

  private:
    vector<Node> nodes;
    void define_parent(int parent, int index) {
        nodes[index].parent = parent;
        nodes[index].children.erase(parent);
        for(auto child : nodes[index].children) {
            define_parent(index, child);
        }
    }
    void rec_path_to_root(int index, vector<int> &res) {
        res.push_back(index);
        if(index == 0)
            return;
        rec_path_to_root(nodes[index].parent, res);
    }
};

ll solve(int n, int m, int k, vector<int> &a, vector<int> &u, vector<int> &v) {
    rep(i, m) a[i]--;
    rep(i, n - 1) {
        u[i]--;
        v[i]--;
    }
    Tree tree(u, v);
    unordered_map<int, unordered_map<int, ll>> counter;
    rep(i, m - 1) {
        vector<int> paths = tree.paths(a[i], a[i + 1]);
        rep(i, paths.size() - 1) {
            counter[min(paths[i], paths[i + 1])][max(paths[i], paths[i + 1])]++;
        }
    }
    vector<ll> b(n - 1);
    rep(i, n - 1) { b[i] = counter[min(u[i], v[i])][max(u[i], v[i])]; }
    int all = 0;
    rep(i, b.size()) all += b[i];
    if((all + k) % 2 != 0 || all + k < 0)
        return 0ll;
    int red = (all + k) / 2;
    vector<vector<ll>> dp(b.size() + 1, vector<ll>(red + 1, 0));
    dp[0][0] = 1ll;
    for(int i = 0; i < (int)b.size(); i++) {
        for(int j = 0; j <= red; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
            if(j >= b[i])
                dp[i + 1][j] += dp[i][j - b[i]];
            dp[i + 1][j] %= MOD;
        }
    }
    return dp[b.size()][red];
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    vector<int> u(n - 1), v(n - 1);
    rep(i, n - 1) cin >> u[i] >> v[i];
    cout << solve(n, m, k, a, u, v) << endl;
    return 0;
}
#endif