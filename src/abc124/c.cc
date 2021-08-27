#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0 && s[i] == '1') {
            ans++;
        } else if(i % 2 == 1 && s[i] == '0') {
            ans++;
        }
    }
    int ans1 = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0 && s[i] == '0') {
            ans1++;
        } else if(i % 2 == 1 && s[i] == '1') {
            ans1++;
        }
    }
    cout << min(ans, ans1) << endl;
    return 0;
}
#endif