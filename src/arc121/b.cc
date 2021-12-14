#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
static const ll MX = 10000000000000000ll;

ll calc(vector<ll> a, vector<ll> b) {
    ll ans = MX;
    for(auto aa : a) {
        auto it = lower_bound(b.begin(), b.end(), aa);
        if(it != b.end()) {
            ans = min(ans, abs(*it - aa));
        }
        if(it != b.begin())
            ans = min(ans, abs(aa - *prev(it)));
    }
    assert(ans != MX);
    return ans;
}

ll calc2(vector<ll> odd, vector<ll> odd2, vector<ll> even) {
    ll ans = MX;
    if(even.size() == 0) {
        return ans;
    }
    ll ans2 = MX;
    for(auto o : odd2) {
        auto it = lower_bound(even.begin(), even.end(), o);
        if(it != even.end()) {
            ans2 = min(ans2, abs(*it - o));
        }
        if(it != even.begin())
            ans2 = min(ans2, abs(o - *prev(it)));
    }
    // assert(ans2 != MX);
    for(auto o : odd) {
        auto it = lower_bound(even.begin(), even.end(), o);
        if(it != even.end()) {
            ans = min(ans, abs(o - *it));
        }
        if(it != even.begin())
            ans = min(ans, abs(o - *prev(it)));
    }
    assert(ans != MX);
    return ans + ans2;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<char> c(2 * n);
    vector<ll> a(2 * n), r, g, b;
    for(int i = 0; i < 2 * n; i++)
        cin >> a[i] >> c[i];

    for(int i = 0; i < 2 * n; i++) {
        switch(c[i]) {
        case 'R':
            r.push_back(a[i]);
            break;
        case 'G':
            g.push_back(a[i]);
            break;
        case 'B':
            b.push_back(a[i]);
            break;
        }
    }
    if(r.size() % 2 == 0 && g.size() % 2 == 0 && b.size() % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    ll ans;
    if(r.size() % 2 == 1 && g.size() % 2 == 1) {
        ans = min(calc(r, g), min(calc2(r, g, b), calc2(g, r, b)));
    } else if(r.size() % 2 == 1 && b.size() % 2 == 1) {
        ans = min(calc(r, b), min(calc2(r, b, g), calc2(b, r, g)));
    } else {
        ans = min(calc(g, b), min(calc2(g, b, r), calc2(b, g, r)));
    }
    cout << ans << endl;
    return 0;
}
#endif