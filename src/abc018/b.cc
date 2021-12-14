#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    int n;
    cin >> s >> n;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        reverse(s.begin() + l - 1, s.begin() + r);
    }
    cout << s << endl;
    return 0;
}
#endif