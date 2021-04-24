#include <bits/stdc++.h>
using namespace std;

int solve(int n, string s) {
    int res = 1001;

    vector<char> lr = {'A', 'B', 'X', 'Y'};
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            for(int c = 0; c < 4; c++) {
                for(int d = 0; d < 4; d++) {
                    int temp = 0;
                    for(int i = 0; i < n;) {
                        if(i < n - 1) {
                            if(lr[a] == s[i] && lr[b] == s[i + 1] ||
                               lr[c] == s[i] && lr[d] == s[i + 1]) {
                                i += 2;
                                temp++;
                                continue;
                            }
                        }
                        temp++;
                        i++;
                    }
                    res = min(res, temp);
                }
            }
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    string c;
    cin >> c;
    cout << solve(n, c) << endl;
    return 0;
}
#endif