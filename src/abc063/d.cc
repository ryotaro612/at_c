#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool enough(int n, ll a, ll b, vector<ll> &h, ll time) {
    vector<ll> x(n);
    copy(h.begin(), h.end(), x.begin());

    for(int i = 0; i < n; i++) {
        x[i] -= time * b;
    }
    ll required = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] <= 0) {
            continue;
        }
        if(x[i] % (a - b) == 0) {
            required += x[i] / (a - b);
        } else {
            required += (x[i] / (a - b)) + 1;
        }
    }

    return required <= time;
}

int solve(int n, ll a, ll b, vector<ll> h) {
    ll mx = 0;
    for(int i = 0; i < n; i++) {
        mx = max(h[i] / b + 1, mx);
    }
    ll lb = -1, ub = mx + 1;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if(enough(n, a, b, h, mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    return ub;
}
/*
int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    cout << solve(n, a, b, h);
}
*/