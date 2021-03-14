#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> solve(int n, int m, int q, vector<int> w, vector<int> v,
                  vector<int> x, vector<pair<int, int>> qv) {
    vector<int> res(q);
    vector<pair<int, int>> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = make_pair(v[i], w[i]);
    }
    sort(b.begin(), b.end(), greater<pair<int, int>>());
    for(int i = 0; i < q; i++) {
        #ifdef _LOCAL
        cout << "i: " << i << endl;
        #endif
        vector<int> xx;
        for(int j = 0; j < m; j++) {
            if(j < qv[i].first - 1 || qv[i].second - 1 < j)
                xx.push_back(x[j]);
        }
        sort(xx.begin(), xx.end());
#ifdef _LOCAL
        cout << "begin available" << endl;
        for(auto xxx : xx) {
            cout << xxx << endl;
        }
        cout << "end available" << endl;
#endif
        int value = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < (int)xx.size(); k++) {
                if(b[j].second <= xx[k]) {
                    value += b[j].first;
                    xx.erase(xx.begin() + k);
                    break;
                }
            }
        }
        res[i] = value;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n), v(n), x(m);
    vector<pair<int, int>> qv(q);
    for(int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    for(int i = 0; i < m; i++)
        cin >> x[i];
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qv[i] = make_pair(l, r);
    }
    vector<int> res = solve(n, m, q, w, v, x, qv);
    for(auto r : res)
        cout << r << endl;
    return 0;
}
#endif