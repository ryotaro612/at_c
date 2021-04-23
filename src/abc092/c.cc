#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(int n, vector<ll> a) {
    vector<ll> sum(n + 2, 0ll);
    sum[1] = abs(a[0]);
    for(int i = 2; i < n + 1; i++)
        sum[i] = sum[i - 1] + abs(a[i - 1] - a[i - 2]);
    sum[n + 1] = abs(a[n - 1]) + sum[n];

    vector<ll> res(n);
    for(int i = 0; i < n; i++) {
        res[i] = sum[i];
        if(i == 0)
            res[i] += abs(a[i + 1]);
        else if(i == n - 1) {
            res[i] += abs(a[i - 1]);
        } else
            res[i] += abs(a[i + 1] - a[i - 1]);
        res[i] += sum[n + 1] - sum[i + 2];
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

    auto res = solve(n, a);
    for(auto r : res)
        cout << r << endl;
    return 0;
}
#endif