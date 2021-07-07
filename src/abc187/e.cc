#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void calc_depth(int node, int height, vector<vector<int>> &tree,
                vector<int> &depth) {
    depth[node] = height;

    for(int i = 0; i < (int)tree[node].size(); i++) {
        if(depth[tree[node][i]] < depth[node])
            continue;
        calc_depth(tree[node][i], height + 1, tree, depth);
    }
}

void expand(int node, vector<vector<int>> &tree, vector<ll> &acc,
            vector<int> &depth) {
    for(int i = 0; i < (int)tree[node].size(); i++) {
        int child = tree[node][i];
        if(depth[child] < depth[node])
            continue;
        acc[child] += acc[node];
        expand(child, tree, acc, depth);
    }
}

vector<ll> solve(int n, vector<int> a, vector<int> b, int q, vector<int> t,
                 vector<int> e, vector<ll> x) {
    vector<vector<int>> tree(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        a[i]--;
        b[i]--;
    }
    for(int i = 0; i < q; i++)
        e[i]--;

    for(int i = 0; i < n - 1; i++) {
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    vector<int> depth(n, 200010);
    calc_depth(0, 0, tree, depth);
    vector<ll> acc(n, 0ll);
    for(int i = 0; i < q; i++) {
        if(t[i] == 1) {
            if(depth[a[e[i]]] < depth[b[e[i]]]) {
                acc[0] += x[i];
                acc[b[e[i]]] -= x[i];
            } else {
                acc[a[e[i]]] += x[i];
            }
        } else {
            if(depth[a[e[i]]] < depth[b[e[i]]]) {
                acc[b[e[i]]] += x[i];
            } else {
                acc[0] += x[i];
                acc[a[e[i]]] -= x[i];
            }
        }
    }
    expand(0, tree, acc, depth);
    return acc;
}

#ifndef _LOCAL
int main() {
    int n, q;
    cin >> n;
    vector<int> a(n - 1), b(n - 1);
    for(int i = 0; i < n - 1; i++)
        cin >> a[i] >> b[i];
    cin >> q;
    vector<int> t(q), e(q);
    vector<ll> x(q);
    for(int i = 0; i < q; i++)
        cin >> t[i] >> e[i] >> x[i];

    vector<ll> ans = solve(n, a, b, q, t, e, x);
    for(auto c : ans)
        cout << c << endl;
    return 0;
}
#endif