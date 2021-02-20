#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, int m, ll x, ll y, vector<ll> a, vector<ll> b) {
    int peek_a = 0, peek_b = 0;
    ll time = a[peek_a], res = 0;
    while(true) {
        if(time > a[peek_a]) {
            while(peek_a < n && time > a[peek_a]) {
                peek_a++;
            }
            if(peek_a == n) {
                return res / 2;
            }
        }
        time = a[peek_a];
        // cout << "a -> b: time: " << time << " a_index: " << peek_a << endl;
        time += x;
        res++;
        if(time > b[peek_b]) {
            while(peek_b < m && time > b[peek_b]) {
                peek_b++;
            }
            if(peek_b == m) {
                return res / 2;
            }
        }
        time = b[peek_b];
        time += y;
        res++;
    }
    return res;
}
/*
int main() {
    int n, m;
    ll x, y;
    cin >> n >> m >> x >> y;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    cout << solve(n, m, x, y, a, b) << endl;
}
*/