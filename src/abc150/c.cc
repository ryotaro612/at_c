#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> dfs(set<int> a, string s) {
    if((int)a.size() == 0)
        return {s};
    vector<string> res;
    for(auto it : a) {
        set<int> aa(a);
        aa.erase(it);
        char ch = it + '0';
        string ss = string(s) + ch;
        vector<string> lst = dfs(aa, ss);
        res.insert(res.end(), lst.begin(), lst.end());
    }
    return res;
}

int find(int n, vector<string> &order, vector<int> p) {
    for(int i = 0; i < (int)order.size(); i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(order[i][j] != (p[j] + '0')) {
                ok = false;
                break;
            }
        }
        if(ok)
            return i + 1;
    }
    return -1;
}

int solve(int n, vector<int> p, vector<int> q) {
    set<int> a;
    for(int i = 1; i <= n; i++) {
        a.insert(i);
    }
    vector<string> order = dfs(a, "");
    int aa = find(n, order, p);
    int bb = find(n, order, q);
    return abs(aa - bb);
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> q[i];
    }
    cout << solve(n, p, q) << endl;
}
#endif