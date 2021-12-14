#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> solve(int n, int m, vector<ll> a, vector<ll> b, vector<ll> c,
                  vector<ll> d) {
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        ll diff = 1000000000000000ll;
        for(int j = 0; j < m; j++) {
            ll temp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(diff > temp) {
                res[i] = j + 1;
                diff = temp;
            }
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(int i = 0; i < m; i++)
        cin >> c[i] >> d[i];
    vector<int> res = solve(n, m, a, b, c, d);
    for(auto r : res)
        cout << r << endl;
}
#endif