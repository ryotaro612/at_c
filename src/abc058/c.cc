#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];

    vector<int> alpha(26, 0);
    for(auto c : s[0]) {
        alpha[c - 'a']++;
    }
    for(int i = 1; i < n; i++) {
        vector<int> temp(26, 0);
        for(auto c : s[i])
            temp[c - 'a']++;
        for(int j = 0; j < 26; j++) {
            alpha[j] = min(alpha[j], temp[j]);
        }
    }
    string ans = "";
    for(int i = 0; i < 26; i++) {
        while(alpha[i] > 0) {
            ans.push_back(i + 'a');
            alpha[i]--;
        }
    }
    cout << ans << endl;
    return 0;
}
#endif