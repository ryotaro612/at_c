#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct P {
    ll index, b1, b2, diff1, diff2;
};

#ifdef ONLINE_JUDGE
int main() {
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    vector<P> v(k);
    for(int i = 0; i < k; i++) {
        ll ma = a[i] * m, b1, b2;
        if(ma % n == 0ll) {
            b1 = b2 = ma / n;
        } else {
            b1 = ma / n;
            b2 = b1 + 1ll;
        }
        ll diff1 = abs(ma - n * b1), diff2 = abs(ma - n * b2);
        v[i] = {i, b1, b2, diff1, diff2};
    }
    sort(v.begin(), v.end(),
         [](P p1, P p2) { return p2.diff1 - p2.diff2 < p1.diff1 - p1.diff2; });

    ll sum = 0ll;
    vector<ll> b(k);
    for(int i = 0; i < k; i++) {
        sum += v[i].b1;
        b[v[i].index] = v[i].b1;
    }
    for(int i = 0; i < k; i++) {
        if(sum == m)
            break;
        b[v[i].index] = v[i].b2;
        sum -= v[i].b1;
        sum += v[i].b2;
    }
    for(int i = 0; i < k; i++) {
        cout << b[i];
        if(i != k - 1)
            cout << " ";
        else
            cout << endl;
    }
}
#endif