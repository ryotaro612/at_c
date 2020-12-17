#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> acc[4];
ll w_t[4];

vector<ll> to_acc(vector<ll> &a) {
    vector<ll> sum(a.size() + 1, 0);
    for(int i = 1; i <= (int)a.size(); i++) {
        sum[i] = sum[i - 1] + a[i - 1];
    }
    return sum;
}

ll rec(int index, ll w) {
    ll res = 0;
    for(int i = 0; i < (int)acc[index].size(); i++) {
        ll used_weight = w_t[index] * i;
        if(used_weight <= w) {
            if(index == 3) {
                res = max(res, acc[index][i]);
            } else {
                res = max(acc[index][i] + rec(index + 1, w - used_weight), res);
            }
        }
    }
    return res;
}

ll solve(int n, ll ww, vector<ll> w, vector<ll> v) {
    vector<ll> v_v[4];
    for(int i = 0; i < n; i++) {
        if(w[i] == w[0]) {
            w_t[0] = w[0];
            v_v[0].push_back(v[i]);
        } else if(w[i] == w[0] + 1) {
            w_t[1] = w[i];
            v_v[1].push_back(v[i]);
        } else if(w[i] == w[0] + 2) {
            w_t[2] = w[i];
            v_v[2].push_back(v[i]);
        } else if(w[i] == w[0] + 3) {
            w_t[3] = w[i];
            v_v[3].push_back(v[i]);
        }
    }
    for(int i = 0; i < 4; i++) {
        sort(v_v[i].begin(), v_v[i].end(), greater<ll>());
        acc[i] = to_acc(v_v[i]);
    }
    return rec(0, ww);
}
/*
int main() {
    int n;
    ll ww;
    cin >> n >> ww;
    vector<ll> w(n), v(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << solve(n, ww, w, v);
}
*/