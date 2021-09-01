#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const INF = 10000000000000ll;

#ifndef _debug
int main() {
    int q;
    cin >> q;

    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll acc = 0ll;
    for(int i = 0; i < q; i++) {
        int o;
        cin >> o;
        if(o == 1) {
            ll x;
            cin >> x;
            x -= acc;
            que.push(x);
        } else if(o == 2) {
            ll x;
            cin >> x;
            acc += x;
        } else {
            ll item = que.top();
            cout << item + acc << endl;
            que.pop();
        }
    }
    return 0;
}
#endif