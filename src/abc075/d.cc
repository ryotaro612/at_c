#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MX = pow(10, 9) + 1;

ll res = -1;

void dfs(int pointer, int n, int k, int comb, vector<ll> &x, vector<ll> &y,
         vector<int> &a) {
    if((int)a.size() == comb) {
        ll ax, bx, ay, by;
        ax = ay = -1 * MX;
        bx = by = MX;
        for(int i = 0; i < (int)a.size(); i++) {
            ax = max(x[a[i]], ax);
            bx = min(x[a[i]], bx);
            ay = max(y[a[i]], ay);
            by = min(y[a[i]], by);
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(ax >= x[i] && x[i] >= bx && ay >= y[i] && y[i] >= by) {
                count++;
            }
        }
        if(count >= k) {
            ll temp = (ax - bx) * (ay - by);
            if(res == -1) {
                res = temp;
            } else {
                res = min(res, temp);
            }
        }
        return;
    }
    if(pointer >= n) {
        return;
    }

    a.push_back(pointer);
    dfs(pointer + 1, n, k, comb, x, y, a);
    a.pop_back();
    dfs(pointer + 1, n, k, comb, x, y, a);
}

ll solve(int n, int k, vector<ll> x, vector<ll> y) {
    vector<int> a;
    dfs(0, n, k, min(k, 4), x, y, a);
    return res;
}
/*
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    cout << solve(n, k, x, y);
}
*/