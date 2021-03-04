#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, string s) { return -1ll; }

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << endl;
}
#endif