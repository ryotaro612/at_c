#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(int n, int m, set<int> &a, set<int> &b) {
    vector<int> res;

    for(auto aa : a) {
        if(b.find(aa) == b.end())
            res.push_back(aa);
    }
    for(auto bb : b) {
        if(a.find(bb) == a.end())
            res.push_back(bb);
    }
    sort(res.begin(), res.end());
    return res;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    set<int> a, b;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.insert(temp);
    }
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        b.insert(temp);
    }
    vector<int> res = solve(n, m, a, b);
    for(int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if(i != (int)res.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
#endif