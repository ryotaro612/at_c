#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<string> s) {
    vector<ll> count(26, 0);
    for(int i = 0; i < n; i++) {
        count[s[i][0] - 'A']++;
    }
    ll res = 0ll;
    string slot = "MARCH";
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 4; j++) {
            for(int k = j + 1; k < 5; k++) {
                res += count[slot[i] - 'A'] * count[slot[j] - 'A'] *
                       count[slot[k] - 'A'];
            }
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];

    cout << solve(n, s) << endl;
}
#endif