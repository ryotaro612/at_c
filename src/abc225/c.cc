#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(int n, int m, vector<vector<ll>> &b) {

    rep(left_j, 8 - m) {
        int prev_a_i;
		bool ok = true;
        rep(i, n) {
            int a_i;
            for(int j = left_j; j < left_j + m; j++) {
                int v = b[i][j - left_j] + 7ll - (ll)(j + 1);
                if(v % 7ll == 0ll) {
                    if(j == left_j)
                        a_i = v / 7ll;
                    else {
                        if(a_i != v / 7ll) {
							ok = false;
							break;
						}
                    }
                } else {
					ok = false;
					break;
                }
            }
			if(!ok)
				break;
            if(i == 0)
                prev_a_i = a_i;
            else if(prev_a_i + 1 == a_i)
                prev_a_i = a_i;
            else
				break;
        }
		if(ok)
	        return "Yes";
    }
    return "No";
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> b(n, vector<ll>(m));
    rep(i, n) { rep(j, m) cin >> b[i][j]; }

    cout << solve(n, m, b) << endl;
    return 0;
}
#endif