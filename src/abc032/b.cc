#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(string s, int k) {
    if(k > (int)s.size())
        return 0;
    set<string> patterns;
    for(int i = 0; i + k <= (int)s.size(); i++)
        patterns.insert(s.substr(i, k));
    return (ll)patterns.size();
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << solve(s, k) << endl;
}
#endif