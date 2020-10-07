#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sub(ll a, ll b){

    if (a == b)
        return 2 * a - 2;

    ll lb = -1, ub = 1LL << 31;

    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;

        if((mid/2 + 1)*(mid-mid/2) > a*b - 1) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    return lb -1;
}

vector<ll> solve(int q, vector<ll> a, vector<ll> b)
{
    vector<ll> res(q);
    for (int i = 0; i < q; i++)
    {
        res[i] = sub(a[i], b[i]);
    }
    return res;
}
/*
int main() {
    int q;
    cin >> q;
    vector<ll> a(q), b(q);
    for(int i=0;i<q;i++) {
        cin >> a[i] >> b[i];
    }
    auto res = solve(q, a, b);
    for(auto aa: res) {
        cout << aa << endl;
    }
}
*/