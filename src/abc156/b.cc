#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(ll n, int k) {
    string res;

    while(n != 0) {
        char digit = (char)(((int)n % k) + '0');
        res.push_back(digit);
        n /= k;
    }
    return (int)res.size();
}

#ifndef _LOCAL
int main() {
    ll n;
    int k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
#endif