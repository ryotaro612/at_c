#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<vector<ll>> a) {
    vector<vector<ll>> b(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            b[i][j] = a[i][j];
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] > b[i][j]) {
                return -1;
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool flag = true;
            for(int k = 0; k < n; k++) {
                if(i != k && j != k && a[i][j] == a[i][k] + a[k][j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res += a[i][j];
            }
        }
    }

    return res / 2;
}
/*
int main() {
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << solve(n, a);
}
*/