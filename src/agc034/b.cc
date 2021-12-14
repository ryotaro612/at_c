#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    vector<string> chunk;
    string temp = "";
    for(int i = 0; i < (int)s.size();) {
        if(s[i] == 'A') {
            temp.push_back(s[i]);
            i++;
        } else if(i < (int)s.size() - 1 && s[i] == 'B' && s[i + 1] == 'C') {
            temp.push_back('D');
            i += 2;
        } else {
            if(temp != "") {
                chunk.push_back(temp);
                temp = "";
            }
            i++;
        }
    }
    if(temp != "") {
        chunk.push_back(temp);
    }

    ll ans = 0ll;
    for(auto c : chunk) {
        ll count = 0ll;
        vector<ll> sum((int)c.size() + 1, 0);
        for(int i = 0; i < (int)c.size(); i++) {
            sum[i + 1] = sum[i];
            if(c[i] == 'A')
                sum[i + 1]++;
        }
        for(int i = 0; i < (int)c.size(); i++) {
            if(c[i] == 'D')
                ans += sum[i];
        }
    }
    /*
    for(auto c : chunk) {
        cout << c << endl;
    }
    */
    cout << ans << endl;
    return 0;
}
#endif