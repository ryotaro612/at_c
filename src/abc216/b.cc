#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j] && t[i] == t[j]) {
                cout << "Yes" << endl;
				return 0;
			}
        }
    }
    cout << "No" << endl;
    return 0;
}
#endif