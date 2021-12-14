#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        a[l] += 1;
        a[r + 1] -= 1;
    }
    for(int i = 1; i < n + 1; i++) {
        a[i] += a[i - 1];
    }
    int ans = 0;
    for(auto aa : a)
        if(aa == m)
            ans++;
    cout << ans << endl;

    return 0;
}
#endif