#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());
    return s < t ? "Yes" : "No";
}

#ifdef ONLINE_JUDGE
int main() {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
    return 0;
}
#endif