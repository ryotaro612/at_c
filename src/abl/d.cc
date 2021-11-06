#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const int N_INF = -1;

struct SegmentTree {
    SegmentTree(int n) {
        int i = 1;
        while(i < n) {
            i *= 2;
        }
        nodes = vector<int>(i * 2 - 1, N_INF);
    }
    void update(int index, int v) {
        int node_index = as_tree_node_index(index);
        nodes[node_index] = v;
        while(node_index > 0) {
            node_index = (node_index - 1) / 2;
            nodes[node_index] =
                max(nodes[node_index * 2 + 1], nodes[node_index * 2 + 2]);
        }
    }
    int query(int from, int to) {
        return query(from, to, 0, 0, (nodes.size() + 1) / 2);
    }

  private:
    vector<int> nodes;
    int as_tree_node_index(int index) {
        return index + (((int)nodes.size() + 1) / 2 - 1);
    }
    int query(int from, int to, int node, int left, int right) {
        if(right <= from || to <= left)
            return N_INF;
        if(from <= left && right <= to)
            return nodes[node];
        int left_v = query(from, to, node * 2 + 1, left, (left + right) / 2);
        int right_v = query(from, to, node * 2 + 2, (left + right) / 2, right);
        return max(left_v, right_v);
    }
};

int solve(int n, int k, vector<int> &a) {
    int max_v = *max_element(a.begin(), a.end());
    int res = 0;
    SegmentTree tree(max_v + 1);
    for(int i = n - 1; i >= 0; i--) {
        //int v = a[i];
        int found = tree.query(max(a[i] - k, 0), min(a[i] + k + 1, max_v+1));
        if(found == N_INF) {
            tree.update(a[i], 1);
            res = max(res, 1);
        } else {
            tree.update(a[i], found + 1);
            res = max(res, found + 1);
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cout << solve(n, k, a) << endl;
    return 0;
}
#endif