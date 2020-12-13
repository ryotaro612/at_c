#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a) {

    priority_queue<ll, vector<ll>, greater<ll>> que;
    vector<ll> former(n + 1, 0);
    for(int i = 0; i < n; i++) {
        que.push(a[i]);
        former[0] += a[i];
    }
    for(int i = 0; i < n; i++) {
        former[i + 1] = former[i];
        ll diff = a[n + i] - que.top();
        if(diff > 0) {
            former[i + 1] += diff;
            que.pop();
            que.push(a[n + i]);
        } else {
        }
    }

    priority_queue<ll> l_que;
    vector<ll> latter(n + 1, 0);
    for(int i = 2 * n; i < n * 3; i++) {
        l_que.push(a[i]);
        latter[0] += a[i];
    }
    for(int i = 0; i < n; i++) {
        latter[i + 1] = latter[i];
        ll diff = a[2 * n - 1 - i] - l_que.top();
        if(diff < 0) {
            latter[i + 1] += diff;
            l_que.pop();
            l_que.push(a[2 * n - 1 - i]);
        } else {
        }
    }
    ll res = former[0] - latter[n];
    for(int i = 0; i < n; i++) {
        res = max(former[i + 1] - latter[n - 1 - i], res);
    }

    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<ll> a(3 * n);
    for(int i = 0; i < 3 * n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a);
}
*/