#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, int x, vector<int> &a) {
    rep(i, n) a[i]--;
    vector<bool> known(n, false);
    x--;
    known[x] = true;
    queue<int> que;
    que.push(x);
    while(!que.empty()) {
        int fri = que.front();
        que.pop();
        if(known[a[fri]] == false) {
            known[a[fri]] = true;
            que.push(a[fri]);
        }
    }
    int res = 0;
    rep(i, n) if(known[i]) res++;
    return res;
}

#ifndef _debug
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    cout << solve(n, x, a) << endl;
    return 0;
}
#endif