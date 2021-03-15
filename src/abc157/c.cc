#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int n, int m, vector<int> s, vector<char> c) {
    for(int i = 0; i <= 999; i++) {
        //cout << "i: " << i << endl;
        string cand = to_string(i);
        bool ok = true;
        if((int)cand.size() == n) {
            for(int j = 0; j < m; j++) {
                if(cand[s[j] - 1] != c[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok)
                return i;
        }
    }
    return -1;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    vector<char> c(m);
    for(int i = 0; i < m; i++) {
        cin >> s[i] >> c[i];
    }
    cout << solve(n, m, s, c) << endl;
    return 0;
}
#endif