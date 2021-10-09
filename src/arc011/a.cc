#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int m, int n, int N) {
    int res = 0;
    int new_pencil = N;
    int old_pencil = 0;
    while(new_pencil > 0) {
        res += new_pencil;
        old_pencil += new_pencil;
		new_pencil = old_pencil / m * n;
		old_pencil -= old_pencil / m * m;
    }
    return res;
}

#ifndef _debug
int main() {
    int m, n, N;
    cin >> m >> n >> N;
    cout << solve(m, n, N) << endl;
    return 0;
}
#endif