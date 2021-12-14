#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, vector<int> &a) {
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(i % 2 && a[i - 1] % 2)
            res++;
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cout << solve(n, a) << endl;
    return 0;
}
#endif