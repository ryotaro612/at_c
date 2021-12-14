#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, int p, vector<int> &a) {
    int res = 0;
    for(auto e : a) {
        if(e < p)
            res++;
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, p;
	cin >> n >> p;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cout << solve(n, p, a) << endl;
    return 0;
}
#endif