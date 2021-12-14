#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    int sum = m * n;
    vector<int> a(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for(auto aa : a)
        sum -= aa;

    int res;
    if(sum > k)
        res = -1;
    else
        res = max(sum, 0);

    cout << res << endl;
    return 0;
}
#endif