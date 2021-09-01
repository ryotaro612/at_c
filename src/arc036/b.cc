#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int peek(int start, vector<ll> &h, vector<ll> &down) {
    ll m = h[start];
    int index = start + 1;
    while(index < (int)h.size()) {
        if(m > h[index]) {
            m = h[index];
            index++;
        } else { // m <= h[index];
            break;
        }
    }
    for(int i = start; i < index; i++)
        down[i] = index - 1;
    return index;
}
int peek_up(int start, vector<ll> &h, vector<ll> &up) {
    ll m = h[start];
    int index = start - 1;
    while(index >= 0) {
        if(m > h[index]) {
            m = h[index];
            index--;
        } else { // m <= h[index];
            break;
        }
    }
    for(int i = start; i > index; i--)
        up[i] = index + 1;
    return index;
}

ll solve(int n, vector<ll> h) {
    vector<ll> up(n), down(n);
    for(int i = 0; i < n;) {
        i = peek(i, h, down);
    }
    for(int i = n - 1; i >= 0;) {
        i = peek_up(i, h, up);
    }
    /*
    for(int i = 0; i < n; i++)
        cout << i << " " << h[i] << " " << down[i] << " " << up[i] << endl;
     */
    ll res = 0ll;
    for(int i = 0; i < n; i++)
        res = max(down[i] - up[i] + 1, res);

    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    cout << solve(n, h) << endl;
    return 0;
}
#endif
