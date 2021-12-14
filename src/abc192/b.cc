#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    for(int i = 0; i < (int)s.size(); i++) {
        if(i % 2 == 0 && isupper(s[i]))
            return "No";
        else if(i % 2 == 1 && islower(s[i]))
            return "No";
    }
    return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
#endif