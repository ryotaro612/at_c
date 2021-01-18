#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll d, ll g, vector<ll> p, vector<ll> c) {
    ll res = numeric_limits<ll>::max();

    for(int i = 0; i < (1 << d); i++) {
        ll temp = 0, count = 0;
        for(int j = 0; j < d; j++) {
            if(i & (1 << j)) {
                temp += (j + 1) * 100 * p[j] + c[j];
                count += p[j];
            }
        }
        if(temp >= g) {
            res = min(count, res);
            continue;
        }
        for(int j = d - 1; j >= 0; j--) {
            if((i & (1 << j)) == 0) {
                ll max_plus = (j + 1) * 100 * (p[j] - 1);
                if(temp + max_plus < g) {
                    temp += max_plus;
                    count += p[j] - 1;
                } else {
                    count += (g - temp) / (100 * (j + 1));
                    if((g - temp) % (100 * (j + 1)) != 0) {
                        count++;
                    }
                    res = min(count, res);
                    break;
                }
            }
        }
    }
    return res;
}
/*
int main() {
    ll d, g;
    cin >> d >> g;
    vector<ll> p(d), c(d);
    for(ll i = 0; i < d; i++) {
        cin >> p[i] >> c[i];
    }
    cout << solve(d, g, p, c) << endl;
}
*/