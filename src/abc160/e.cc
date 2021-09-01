#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int x, int y, int a, int b, int c, vector<ll> p, vector<ll> q,
         vector<ll> r) {
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());
    priority_queue<pair<ll, bool>, vector<pair<ll, bool>>,
                   greater<pair<ll, bool>>>
        que;
    for(int i = 0; i < x; i++)
        que.push(make_pair(p[i], true));
    for(int i = 0; i < y; i++)
        que.push(make_pair(q[i], false));

    while(true) {
        if((int)r.size() == 0)
            break;
        pair<ll, bool> item = que.top();
        if(r[0] > item.first) {
            que.pop();
            que.push(make_pair(r[0], item.second));
            r.erase(r.begin());
        } else
            break;
    }
    ll res = 0ll;
    while(!que.empty()) {
        res += que.top().first;
        que.pop();
    }
    return res;
}

#ifndef _debug
int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    for(int i = 0; i < a; i++)
        cin >> p[i];
    for(int i = 0; i < b; i++)
        cin >> q[i];
    for(int i = 0; i < c; i++)
        cin >> r[i];
    cout << solve(x, y, a, b, c, p, q, r) << endl;
}
#endif