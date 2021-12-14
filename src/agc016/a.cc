#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    ll ans = numeric_limits<ll>::max();
    set<char> cs;
    for(auto c : s)
        cs.insert(c);
    for(auto c : cs) {
        string temp = s;
        ll temp_ans = 0ll;
        // cout << c << endl;
        while(true) {
            set<char> temp_cs;
            for(auto a : temp)
                temp_cs.insert(a);
            if((int)temp_cs.size() == 1) {
                ans = min(ans, temp_ans);
                break;
            }

            string next = string(temp.size() - 1, ' ');
            for(int i = 0; i < (int)next.size(); i++) {
                if(temp[i] == c || temp[i + 1] == c)
                    next[i] = c;
                else
                    next[i] = temp[i];
            }
            temp = next;
            temp_ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
#endif