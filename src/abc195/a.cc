#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(int m, int h) {
    return h % m == 0 ? "Yes" : "No";
}

#ifdef ONLINE_JUDGE
int main() {
    int m, h;
    cin >> m >> h;
    cout << solve(m, h) << endl;
    return 0;
}
#endif