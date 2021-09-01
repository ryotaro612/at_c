#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll MX = 30000ll;
vector<ll> primes;
vector<bool> is_prime(MX + 1, true);

vector<ll> solve(ll n) {
    // 6 15, 10
    set<ll> s;
    for(ll i = 0; i < n + 1; i++) {
        s.insert(12ll + 6ll * i);
        s.insert(30ll + 15ll * i);
        s.insert(20ll + 10ll * i);
    }
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for(auto ss : s) {
        que.push(ss);
    }
    vector<ll> ans(n);
    ans[0] = 6ll;
    ans[1] = 10ll;
    ans[2] = 15ll;
    for(int i = 3; i < n; i++) {
        ans[i] = que.top();
        que.pop();
    }
    return ans;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    vector<ll> ans = solve(n);
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i];
        if(i < (int)ans.size() - 1)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}
#endif