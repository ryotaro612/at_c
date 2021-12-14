#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gap_count(vector<ll> &b) {
    ll res = 0ll;
    for(int i = 1; i < (int)b.size(); i++) {
        res += abs(b[i - 1] - b[i]);
    }
    return res;
}

ll pattern(int n, vector<ll> &a) {
    vector<ll> b(n);
    int source = n - 1;
    for(int dest = 1; dest < n; dest += 2) {
        b[dest] = a[source];
        source--;
    }
    source = 0;
    for(int dest = 2; dest < n; dest += 2) {
        b[dest] = a[source];
        source++;
    }
    b[0] = a[source];
    return gap_count(b);
}

ll pattern2(int n, vector<ll> &a) {
    vector<ll> b(n);
    int source = n - 1;
    for(int dest = 2; dest < n; dest += 2) {
        b[dest] = a[source];
        source--;
    }
    source = 0;
    for(int dest = 1; dest < n; dest += 2) {
        b[dest] = a[source];
        source++;
    }
    b[0] = a[source];
    return gap_count(b);
}

ll solve(int n, vector<ll> a) {
    sort(a.begin(), a.end());
    return max(pattern(n, a), pattern2(n, a));
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif