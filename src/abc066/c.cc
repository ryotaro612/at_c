#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(int n, vector<ll> a) {
    deque<ll> d;
    bool flip = false;
    for(int i = 0; i < n; i++) {
        if(!flip) {
            d.push_back(a[i]);
        } else {
            d.push_front(a[i]);
        }
        flip = !flip;
    }
    vector<ll> ans(n);

    for(int i = 0; i < n; i++) {
        ans[i] = d.front();
        d.pop_front();
    }
    if(flip)
        reverse(ans.begin(), ans.end());
    return ans;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    auto ans = solve(n, a);
    for(int i = 0; i < n; i++) {
        cout << ans[i];
        if(i == n - 1)
            cout << endl;
        else
            cout << " ";
    }

    return 0;
}
#endif