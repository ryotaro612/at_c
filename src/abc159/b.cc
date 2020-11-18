#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool kaibun(string s) {
    int n = s.size();
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

string solve(string s) {
    if(!kaibun(s)) {
        return "No";
    }
    int n = s.size();
    string ss = s.substr(0, (n - 1) / 2);
    if(!kaibun(ss)) {
        return "No";
    }
    ss = s.substr((n + 3) / 2 - 1, n - ((n + 3) / 2) + 1);
    if(!kaibun(ss)) {
        return "No";
    }
    return "Yes";
}
/*
int main() {
    string s;
    cin >> s;
    cout << solve(s);
}
*/