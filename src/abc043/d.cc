#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    for(int i = 0; i < (int)s.size() - 1; i++) {
        if(s[i] == s[i + 1])
            return to_string(i + 1) + " " + to_string(i + 2);
    }
    for(int i = 0; i < (int)s.size() - 2; i++) {
        if(s[i] == s[i + 2])
            return to_string(i + 1) + " " + to_string(i + 3);
    }

    return "-1 -1";
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
#endif