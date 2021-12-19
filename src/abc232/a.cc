#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(string s) {
    int a = s[0] - '0';
    int b = s[2] - '0';
    return a * b;
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif