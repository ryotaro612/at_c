#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, int k, vector<ll> a) {
    vector<vector<bool>> left(n + 1, vector<bool>(k + 1, false)),
        right(n + 1, vector<bool>(k + 1, false));
    left[0][0] = right[0][0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(left[i - 1][j]) {
                left[i][j] = left[i - 1][j];
                if(j + a[i - 1] <= k) {
                    left[i][j + a[i - 1]] = true;
                }
            }
            if(right[i - 1][j]) {
                right[i][j] = right[i - 1][j];
                if(j + a[n - i] <= k) {
                    right[i][j + a[n - i]] = true;
                }
            }
        }
    }

    ll res = 0;
    for(int i = 0; i < n; i++) {
        vector<int> sum(k + 1, 0);
        if(right[n - i - 1][0]) {
            sum[0] = 1;
        }
        for(int j = 1; j <= k; j++) {
            sum[j] += sum[j - 1] + right[n - 1 - i][j];
        }
        bool ok = true;
        for(int j = 0; j < k; j++) {
            if(left[i][j]) {
                if(k - a[i] - j <= 0) {
                    ok = false;
                } else if(sum[k - j - 1] - sum[max(0LL, k - a[i] - j - 1)] >
                          0) {
                    ok = false;
                }
            }
        }
        if(ok) {
            res++;
        }
    }
    return res;
}
/*
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, k, a);
}
*/