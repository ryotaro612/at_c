#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, int k, int a) {
    int res;
    for(int i = 0; i < k; i++) {
		//cout <<  " i: " << i << endl;
		if(i == 0) {
			res = a;
			continue;
		}
        if(res < n) {
            res++;
			continue;
		}
        if(res == n) {
            res = 1;
			continue;
		}
    }
	return res;
}
#ifndef _debug
int main() {
    int n, k, a;
    cin >> n >> k >> a;
    cout << solve(n, k, a) << endl;
    return 0;
}
#endif