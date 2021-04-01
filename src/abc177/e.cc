#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

vector<int> calc_primes(int n) {
    vector<int> res;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            res.push_back(i);
        while(n % i == 0)
            n /= i;
    }
    if(n != 1)
        res.push_back(n);
    return res;
}

bool is_pairwise(int n, vector<int> &a) {
    set<int> primes;
    for(int i = 0; i < n; i++) {
        vector<int> ps = calc_primes(a[i]);
        for(int j = 0; j < (int)ps.size(); j++) {
            if(primes.find(ps[j]) != primes.end())
                return false;
            primes.insert(ps[j]);
        }
    }
    return true;
}

string solve(int n, vector<int> a) {
    if(n == 1)
        return "pairwise";
    if(is_pairwise(n, a))
        return "pairwise";
    int g = a[0];
    for(int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
        if(g == 1)
            return "setwise";
    }
    return "not";
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << " coprime" << endl;
}
#endif