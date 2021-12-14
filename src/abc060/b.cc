#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(int a, int b, int c) {
    for(int i = 1; i <= 101; i++) {
        if(a * i % b == c)
            return "YES";
    }
    return "NO";
}

#ifdef ONLINE_JUDGE
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
}
#endif