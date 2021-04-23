#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(int n, vector<ll> x) {
    vector<pair<ll, int>> v(n);
    for(int i = 0; i < n; i++)
        v[i] = make_pair(x[i], i);
    sort(v.begin(), v.end());
    vector<ll> temp(n);
    for(int i = 0; i < n / 2; i++) {
        temp[v[i].second] = v[n / 2].first;
    }
    for(int i = n / 2; i < n; i++) {
        temp[v[i].second] = v[n / 2 - 1].first;
    }
    return temp;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];
    auto res = solve(n, x);
    for(auto r : res)
        cout << r << endl;
    return 0;
}
#endif