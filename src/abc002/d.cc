#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int m, vector<int> x, vector<int> y) {
    int res = 1;
    vector<set<int>> buddies(n);
    for(int i = 0; i < m; i++) {
        buddies[x[i] - 1].insert(y[i] - 1);
        buddies[y[i] - 1].insert(x[i] - 1);
    }
    for(int i = 1; i < 1 << n; i++) {
        vector<int> shiriai;
        for(int j = 0; j < n; j++) {
            if(1 << j & i) {
                shiriai.push_back(j);
            }
        }
        bool ok = true;
        for(int j = 0; j < (int)shiriai.size(); j++) {
            for(int k = 0; k < (int)shiriai.size(); k++) {
                if(j == k)
                    continue;
                if(buddies[shiriai[j]].find(shiriai[k]) ==
                   buddies[shiriai[j]].end()) {
                    ok = false;
                }
            }
        }
        if(ok) {
            res = max((int)shiriai.size(), res);
        }
    }

    return res;
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    cout << solve(n, m, x, y) << endl;
}
*/
