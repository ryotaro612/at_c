#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

struct SegmentTree {
    SegmentTree(int n) {
        int i = 0;
        while((1 << i) < n)
            i++;
        // 2^i >= n
        nodes.resize((1 << (i + 1)) - 1);
        rep(i, nodes.size()) nodes[i] = {INF, -1};
    }
    void update(int i, int v) {
        int node = as_leaf(i);
        while(true) {
            if(nodes[node].first == INF) {
                nodes[node] = {v, i};
            } else {
                if(nodes[node].first == v) {
                    nodes[node] = {v, min(i, nodes[node].second)};
                } else if(v < nodes[node].first) {
                    nodes[node] = {v, i};
                }
            }
            if(node == 0)
                break;
            node = (node - 1) / 2;
        }
    }
    pair<int, int> query(int from, int to) {
        return query(from, to, 0, 0, ((int)nodes.size() + 1) / 2);
    }
    bool is_inf(int index) { return query(index, index + 1).first == INF; }
    void debug() {
        rep(i, nodes.size()) {
            cout << i << "->(" << nodes[i].first << "," << nodes[i].second
                 << "), " << endl;
        }
    }

  private:
    vector<pair<int, int>> nodes;
    int INF = 1000000;
    int as_leaf(int i) {
        int n = nodes.size();
        return (n + 1) / 2 - 1 + i;
    }
    pair<int, int> query(int from, int to, int branch, int left, int right) {
        // cout << "query: " << from << " " << to << " " << branch << " " <<
        // left << " " << right << endl;
        if(right <= from || to <= left)
            return {INF, -1};
        if(from <= left && right <= to) {
            return nodes[branch];
        }
        pair<int, int> left_v =
            query(from, to, branch * 2 + 1, left, (left + right) / 2);
        pair<int, int> right_v =
            query(from, to, branch * 2 + 2, (left + right) / 2, right);
        if(left_v.first <= right_v.first)
            return left_v;
        return right_v;
    }
};

vector<int> solve(int n, int m, string &s) {
    SegmentTree tree(n + 1);
    tree.update(0, 0);
    // tree.debug();
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0') {
            // cout << i << endl;
            // cout << "## query " << i << endl;
            pair<int, int> before = tree.query(max(0, i - m), i);
            // cout << i << "->" << before.first << " " << before.second <<
            // endl;
            tree.update(i, before.first + 1);
        }
    }
    if(tree.is_inf(n))
        return {-1};
    vector<int> res;
    for(int i = n; i > 0;) {
        pair<int, int> cursor = tree.query(i, i + 1);
        pair<int, int> prev =
            tree.query(max(0, cursor.second - m), cursor.second);
        res.push_back(cursor.second - prev.second);
        i = prev.second;
    }
    reverse(res.begin(), res.end());
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> res = solve(n, m, s);
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