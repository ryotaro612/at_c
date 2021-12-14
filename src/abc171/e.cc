#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> solve(int n, vector<ll> a) {
    ll sum = 0ll;
    for(auto aa : a)
        sum ^= aa;
    vector<ll> res(n);
    for(int i = 0; i < n; i++)
        res[i] = a[i] ^ sum;
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> res = solve(n, a);
    for(int i = 0; i < n; i++) {
        cout << res[i];
        if(i != n - 1)
            cout << " ";
    }
    cout << endl;
}
#endif