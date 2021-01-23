#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(ll index, vector<string> &s) {
    if(index == 0) {
        return 1;
    }
    if(s[index - 1] == "AND")
        return dfs(index - 1, s);
    return (ll)pow(2ll, index) + dfs(index - 1, s);
}
ll solve(ll n, vector<string> s) { return dfs(n, s); }
/*
int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    for(ll i = 0; i < n; i++) {
        cin >> s[i];
    }
    cout << solve(n, s) << endl;
}
*/