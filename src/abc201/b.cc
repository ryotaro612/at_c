#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<pair<ll, string>> ts(n);
    for(int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;
        ts[i] = make_pair(t, s);
    }
    sort(ts.begin(), ts.end(), greater<pair<ll, string>>());
    cout << ts[1].second << endl;

    return 0;
}
#endif