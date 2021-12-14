#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> a, vector<vector<int>> x, vector<vector<int>> y) {
    int res = 0;
    for(int i = 0; i < (1 << n); i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if((i & (1 << j)) == 0) {
                continue;
            }
            for(int k = 0; k < a[j]; k++) {
                int x_honest = (i & (1 << (x[j][k] - 1)));
                if(y[j][k] == 0) {
                    if(x_honest != 0) {
                        ok = false;
                        break;
                    }
                } else { // 正直者だと主張
                    if(x_honest == 0) {
                        ok = false;
                        break;
                    }
                }
            }
            if(!ok)
                break;
        }
        if(ok) {
            res = max((int)bitset<15>(i).count(), res);
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        x[i] = vector<int>(a[i]);
      y[i] = vector<int>(a[i]);
        for(int j = 0; j < a[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    cout << solve(n, a, x, y) << endl;
}
#endif