#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    priority_queue<pair<ll, int>> que;
    for(int i = 0; i < n; i++) {
        que.push(make_pair(a[i] + b[i], i));
    }
    ll ans = 0ll;
    bool turn = true;
    ll takahashi = 0ll, aoki = 0ll;
    while(!que.empty()) {
        auto p = que.top();
        if(turn) {
            takahashi += a[p.second];
        } else {
            aoki += b[p.second];
        }
        turn = !turn;
        que.pop();
    }
    cout << takahashi - aoki << endl;
    return 0;
}
#endif