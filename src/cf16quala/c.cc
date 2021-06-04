#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = (int)s.size();
    for(int i = 0; i < n; i++) {
        int diff = 26 - (s[i] - 'a');
        //cout << "i " << i << " " << diff << endl;
        if(diff == 26)
            continue;
        if(k >= diff) {
            k -= diff;
            s[i] = 'a';
        }
    }
    k %= 26;
    while(k-- > 0) {
        if(s[n - 1] != 'z')
            s[n - 1]++;
        else
            s[n - 1] = 'a';
    }
    cout << s << endl;
    return 0;
}
#endif