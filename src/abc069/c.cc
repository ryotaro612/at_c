#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll n, vector<ll> a) {
    vector<queue<int>> d(3);
    for(int i = 0; i < n; i++) {
        if(a[i] % 4 == 0)
            d[2].push(a[i]);
        else if(a[i] % 2 == 0)
            d[1].push(a[i]);
        else
            d[0].push(a[i]);
    }

    vector<ll> b(n, -1);

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            if(!d[0].empty()) {
                b[i] = d[0].front();
                d[0].pop();
            } else if(!d[1].empty()) {
                b[i] = d[1].front();
                d[1].pop();
            } else {
                b[i] = d[2].front();
                d[2].pop();
            }
        } else {
            if(b[i - 1] % 2 == 1) {
                if(d[2].empty()) {
                    return "No";
                }
                b[i] = d[2].front();
                d[2].pop();
            } else if(b[i - 1] % 4 == 0) {
                if(!d[0].empty()) {
                    b[i] = d[0].front();
                    d[0].pop();
                } else if(!d[1].empty()) {
                    b[i] = d[1].front();
                    d[1].pop();
                } else {
                    b[i] = d[2].front();
                    d[2].pop();
                }
            } else { // if(b[i - 1] % 2 == 0)
                if(d[1].empty() && d[2].empty()) {
                    return "No";
                }
                if(!d[1].empty()) {
                    b[i] = d[1].front();
                    d[1].pop();
                } else {
                    b[i] = d[2].front();
                    d[2].pop();
                }
            }
        }
    }
    return "Yes";
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, a) << endl;
    return 0;
}
#endif