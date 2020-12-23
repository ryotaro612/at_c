#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long com[51][51];

pair<double, ll> solve(int n, int a, int b, vector<ll> v) {
    com[0][0] = 1;
    for(int i = 1; i < 51; ++i) {
        for(int j = 0; j <= i; ++j) {
            com[i][j] += com[i - 1][j];
            if(j > 0)
                com[i][j] += com[i - 1][j - 1];
        }
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll sum = 0;
    for(int i = 0; i < a; i++) {
        sum += v[i];
    }
    double ave = (double)sum / a;

    int num = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] == v[a - 1]) {
            num++;
        }
    }
    if(v[0] == v[a - 1]) {
        ll pattern = 0;
        for(int i = a; i <= b; i++) {
            // cout << n << " ni " << i << endl;
            pattern += com[num][i];
        }
        return make_pair(ave, pattern);
    }

    ll all_a = 0;
    for(int i = 0; i < n; i++) {
        if(v[a - 1] == v[i]) {
            all_a++;
        }
    }
    ll count_a = 0;
    for(int i = 0; i < a; i++) {
        if(v[a - 1] == v[i]) {
            count_a++;
        }
    }
    pair<double, ll> res = make_pair(ave, com[all_a][count_a]);
    // cout << res.first << " " << res.second << endl;
    return res;
}
/*
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto res = solve(n, a, b, v);
    cout << fixed << setprecision(10) << res.first << endl;
    cout << res.second << endl;
}
*/