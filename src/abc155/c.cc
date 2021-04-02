#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> solve(int n, vector<string> s) {
    vector<string> res;
    map<string, ll> count;
    for(auto ss : s)
        count[ss]++;
    ll mx = 0;
    for(auto p : count)
        mx = max(mx, p.second);
    for(auto p : count)
        if(p.second == mx)
            res.push_back(p.first);

    sort(res.begin(), res.end());
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    vector<string> res = solve(n, s);
    for(auto r : res)
        cout << r << endl;
}
#endif