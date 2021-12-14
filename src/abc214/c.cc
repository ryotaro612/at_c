#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll const INF = 1000000000000000ll;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> s(n), t(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        cin >> t[i];
    vector<pair<ll, int>> st(n);
    for(int i = 0; i < n; i++) {
        st[i] = {t[i], i};
    }
    sort(st.begin(), st.end());
    vector<ll> ans(n, INF);
    for(int i = 0; i < n; i++) {
        ans[i] = t[i];
    }
    for(int i = st[0].second; i < (st[0].second + n); i++) {
        int next_i = ((i + 1) % n);
        // ans[next_i] = min(ans[i], t[i]) + s[i];
        ans[next_i] = min(ans[next_i], ans[i % n] + s[i % n]);
    }

    for(auto aa : ans)
        cout << aa << endl;
    return 0;
}
#endif
