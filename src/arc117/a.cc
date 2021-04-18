#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> solve(ll a, ll b) {

    vector<ll> av(a, 1000), bv(b, 1000);
    if(a >= b) {
        for(int i = 1; i <= a; i++)
            av[i - 1] = i;
        for(int i = 0; i < b - 1; i++) {
            bv[i] = -(i + 1);
        }
        ll sum = 0ll;
        for(int i = b - 1; i < a; i++) {
            sum += av[i];
        }
        bv[b - 1] = -sum;
    } else { //  a < b
        for(int i = 1; i <= b; i++) {
            bv[i - 1] = -i;
        }
        for(int i = 0; i < a - 1; i++) {
            av[i] = i + 1;
        }
        ll sum = 0ll;
        for(int i = a - 1; i < b; i++) {
            sum += bv[i];
        }
        /*
        for(auto bb : bv)
            cout << bb << endl;
            */
        av[a - 1] = -sum;
    }
    vector<ll> res(a + b, 1000);
    for(int i = 0; i < a; i++) {
        res[i] = av[i];
    }
    for(int i = 0; i < b; i++) {
        res[i + a] = bv[i];
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll a, b;
    cin >> a >> b;
    vector<ll> res = solve(a, b);
    for(int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if(i != (int)res.size() - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}
#endif