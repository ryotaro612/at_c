#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(string &s, int k) {
    int res = 0, from = 0, to = 0, n = s.size(), n_x = 0, n_k = 0;

    while(true) {
        // cout << "from: " << from << " to: " << to << " n_x: " << n_x
        //      << " n_k: " << n_k << endl;
        // toをすすめられない条件は
        if(to == n) {
            if(n_k <= k) {
                break;
            } else { // k < n_k
                assert(false);
            }
        } else {
            if(s[to] == '.') {
                if(n_k == k) {
                    if(s[from] == '.') {
                        from++;
                        if(n_k > 0) {
                            n_x--;
                            n_k--;
                        } else { // n_k <= 0
                        }
                        to = max(from, to);
                    } else { // s[from] == '#'
                        from++;
                        n_x--;
                        to = max(from, to);
                    }
                } else { // n_k < k
                    to++;
                    n_k++;
                    n_x++;
                    res = max(n_x, res);
                }
            } else { // s[to] == '#'
                to++;
                n_x++;
                res = max(n_x, res);
            }
        }
    }
    return res;
}

#ifndef _debug
int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << solve(s, k) << endl;
    return 0;
}
#endif