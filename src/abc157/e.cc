#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Query {
    int type, index, from, to;
    char a;
};

const int N = 1 << 20;

int node[N][26];
int node_n;

void init(int n) {
    node_n = 1;
    while(node_n < n) {
        node_n *= 2;
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 26; j++)
            node[i][j] = 0;
}

void update(int i, char c, int diff) {
    i += node_n - 1;
    node[i][c - 'a'] += diff;
    while(i > 0) {
        i = (i - 1) / 2;
        node[i][c - 'a'] += diff;
    }
}

vector<int> query(int a, int b, int k, int l, int r) {
    vector<int> res(26, 0);
    if(b <= l || r <= a)
        return res;
    if(a <= l && r <= b) {
        for(int i = 0; i < 26; i++)
            res[i] = node[k][i];
        return res;
    }
    vector<int> res1 = query(a, b, 2 * k + 1, l, (l + r) / 2),
                res2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
    for(int i = 0; i < 26; i++)
        res[i] = res1[i] + res2[i];
    return res;
}

vector<int> solve(int n, string s, int q, vector<Query> queries) {
    init(n);
    for(int i = 0; i < n; i++)
        update(i, s[i], 1);
    vector<int> ans;
    for(int i = 0; i < q; i++) {
        Query qu = queries[i];
        if(qu.type == 1) {
            vector<int> res = query(qu.index - 1, qu.index, 0, 0, node_n);
            for(int i = 0; i < 26; i++) {
                if(res[i] > 0) {
                    update(qu.index - 1, i + 'a', -1);
                }
            }
            update(qu.index - 1, qu.a, 1);
        } else {
            vector<int> res = query(qu.from - 1, qu.to, 0, 0, node_n);
            int count = 0;
            for(int i = 0; i < 26; i++)
                if(res[i] > 0)
                    count++;
            ans.push_back(count);
        }
    }

    return ans;
}

#ifndef _LOCAL
int main() {
    int n, q;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;
    vector<Query> queries(q);
    for(int i = 0; i < q; i++) {
        int type, index, from, to;
        char a;
        cin >> type;
        if(type == 1) {
            cin >> index >> a;
        } else {
            cin >> from >> to;
        }
        queries[i] = {type, index, from, to, a};
    }
    vector<int> ans = solve(n, s, q, queries);
    for(auto a : ans)
        cout << a << endl;
    return 0;
}
#endif