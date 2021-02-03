#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int r, int c, int k, vector<string> s) {
    vector<vector<int>> sum(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int plus = s[i][j] == 'x' ? 1 : 0;
            sum[i][j] = j == 0 ? plus : sum[i][j - 1] + plus;
        }
    }
    ll res = 0ll;
    for(int x = k - 1; x < r - k + 1; x++) {
        for(int y = k - 1; y < c - k + 1; y++) {
            bool ok = true;
            for(int i = x - k + 1; i < x + k; i++) {
                int span = k - 1 - abs(i - x);
                int from = y - span;
                int to = y + span;
                if(sum[i][to] - (from == 0 ? 0 : sum[i][from - 1]) > 0) {
                    ok = false;
                    break;
                }
            }
            res += ok ? 1 : 0;
        }
    }
    return res;
}
/*
int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> s(r);
    for(int i = 0; i < r; i++) {
        cin >> s[i];
    }
    cout << solve(r, c, k, s) << endl;
}
*/