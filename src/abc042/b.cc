#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(int n, int l, vector<string> s) {
    sort(s.begin(), s.end());
    string res;
    for(auto ss : s)
        res = res + ss;
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    cout << solve(n, l, s) << endl;
}
#endif