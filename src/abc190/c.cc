#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int m, vector<int> a, vector<int> b, int k, vector<int> c,
          vector<int> d) {
    int res = 0;
    for(int i = 0; i < (1 << k); i++) {
        vector<bool> filled(n, false);
        for(int j = 0; j < k; j++) {
            if(i & (1 << j)) {
                filled[c[j] - 1] = true;
            } else {
                filled[d[j] - 1] = true;
            }
        }
        int temp = 0;
        for(int j = 0; j < m; j++) {
            if(filled[a[j] - 1] && filled[b[j] - 1]) {
                temp++;
            }
        }
        res = max(temp, res);
    }
    return res;
}
/*
int main() {
    int n, m, k;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    vector<int> c(k), d(k);
    for(int i = 0; i < k; i++) {
        cin >> c[i] >> d[i];
    }
    cout << solve(n, m, a, b, k, c, d) << endl;
}
*/