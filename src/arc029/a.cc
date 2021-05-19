#define _GLIBCXX_DEBUUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<int> t(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    if(n == 1) {
        cout << t[0] << endl;
        return 0;
    }
    if(n == 2) {
        cout << max(t[0], t[1]) << endl;
        return 0;
    }
    if(n == 3) {
        int ans = max(t[0] + t[1], t[2]);
        ans = min(max(t[0] + t[2], t[1]), ans);
        ans = min(max(t[2] + t[1], t[0]), ans);
        cout << ans << endl;
        return 0;
    }

    int ans = 210000000;
    vector<int> v = {0, 1, 2, 3};
    do {
        ans = min(ans, max(t[v[0]] + t[v[1]], t[v[2]] + t[v[3]]));
        ans = min(ans, max(t[v[0]], t[v[1]] + t[v[2]] + t[v[3]]));
    } while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}
#endif