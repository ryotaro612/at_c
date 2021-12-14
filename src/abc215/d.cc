#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, int> prime_factor(int n) {
    map<int, int> ret;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1)
        ret[n] = 1;
    return ret;
}

set<int> calc_primes(vector<int> &a) {
    set<int> res;

    for(auto aa : a) {
        map<int, int> ps = prime_factor(aa);
        for(auto p : ps)
            res.insert(p.first);
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<bool> b(m + 1, true);
    set<int> primes = calc_primes(a);
    // cout << "doge" << endl;
    for(auto prime : primes) {
        for(int i = prime; i <= m; i += prime) {
            b[i] = false;
        }
    }
    vector<int> ans;
    for(int i = 1; i <= m; i++) {
        if(b[i])
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto e : ans) {
        cout << e << endl;
    }

    return 0;
}
#endif