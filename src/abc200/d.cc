#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> mp(200);
int N;
vector<ll> A;

struct Ans {
    vector<ll> a, b;
};
Ans ans = {vector<ll>(0), vector<ll>(0)};

void dfs(int i, ll sum, vector<ll> chunk) {
    if(i == N || (int)ans.a.size() > 0 && (int)ans.b.size() > 0)
        return;

    vector<ll> sub(chunk.begin(), chunk.end());
    mp[sum % 200ll] = sub;
    dfs(i + 1, sum, sub);

    sub = vector<ll>(chunk.begin(), chunk.end());
    sub.push_back(i + 1);
    sum += A[i];
    ll key = sum % 200ll;
    if((int)mp[key].size() > 0ll) {
        ans = {mp[key], sub};
        return;
    }
    mp[key] = sub;
    dfs(i + 1, sum, sub);
}
Ans solve(int n, vector<ll> a) {
    N = n;
    A = a;
    vector<ll> chunk;
    dfs(0, 0ll, chunk);
    return ans;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    Ans ans = solve(n, a);
    /*
    for(int i = 0; i < 200; i++) {
        if(mp[i].size() > 0)
            cout << i << endl;
    }
    */

    if((int)ans.a.size() == 0 || (int)ans.b.size() == 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << (int)ans.a.size() << " ";
    for(int i = 0; i < (int)ans.a.size(); i++) {
        cout << ans.a[i];
        if(i != (int)ans.a.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
    cout << (int)ans.b.size() << " ";
    for(int i = 0; i < (int)ans.b.size(); i++) {
        cout << ans.b[i];
        if(i != (int)ans.b.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
#endif
