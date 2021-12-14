#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(vector<int> &p) {
    string s;

    rep(i, 26) { 
        //cout << p[i] << endl;
        s.push_back(p[i] - 1 + 'a'); 
    }
    //cout << s.size() << endl;
    return s;
}

#ifdef ONLINE_JUDGE
int main() {
    vector<int> p(26);
    rep(i, 26) cin >> p[i];
    cout << solve(p) << endl;
    return 0;
}
#endif