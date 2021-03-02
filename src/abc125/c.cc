#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
  if(a%b == 0ll){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ll solve(int n, vector<ll> a) {
    vector<ll> left(n), right(n);
    left[0] = a[0];
    right[0] = a[n - 1];
    for(int i = 1; i < n; i++) {
        left[i] = gcd(a[i], left[i - 1]);
        right[i] = gcd(a[n - 1 - i], right[i - 1]);
    }
    ll res = left[n - 1];
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            res = max(right[n - 2], res);
        } else if(i == n - 1) {
            res = max(left[n - 2], res);
        } else {
            res = max(res, gcd(left[i - 1], right[n - (i + 1) - 1]));
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
    return 0;
}
#endif