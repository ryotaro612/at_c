#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<int> solve(int n, int m, vector<int> &a, vector<int> &b) {
    vector<set<int>> deps(n + 1), rev_deps(n + 1);
    rep(i, m) {
        deps[a[i]].insert(b[i]);
        rev_deps[b[i]].insert(a[i]);
    }
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i = 1; i <= n; i++) {
        if(rev_deps[i].empty())
            que.push(i);
    }
    vector<int> res;
    while(!que.empty()) {
        int digit = que.top();
        que.pop();
        res.push_back(digit);
        // require_digit needs digit
        for(auto require_digit : deps[digit]) {
            rev_deps[require_digit].erase(digit);
            if(rev_deps[require_digit].empty())
                que.push(require_digit);
        }
        deps[digit].clear();
    }
    if(res.size() == n)
        return res;
    else
        return {-1};
}

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    vector<int> res = solve(n, m, a, b);
    rep(i, res.size()) {
        cout << res[i];
        if(i == (int)res.size() - 1)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}
#endif