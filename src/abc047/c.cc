#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(string s) {

    string a = string(1, s[0]);

    for(int i = 1; i < s.size(); i++) {
        if(a[a.size() - 1] != s[i])
            a.push_back(s[i]);
    }
    return (int)a.size() - 1;
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif