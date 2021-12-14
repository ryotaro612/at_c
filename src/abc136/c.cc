#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll n, vector<ll> h) {

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            h[i]--;
            continue;
        }

        if(h[i - 1] < h[i])
            h[i]--;
        else if(h[i - 1] > h[i])
            return "No";
    }
    return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    cout << solve(n, h) << endl;

    return 0;
}
#endif