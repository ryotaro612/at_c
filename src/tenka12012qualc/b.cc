#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    vector<string> cards;
    string temp = "";
    for(int i = 0; i < (int)s.size(); i++) {
        if(i == 0) {
            temp.push_back(s[i]);
            continue;
        }
        if(s[i] == 'S' || s[i] == 'H' || s[i] == 'D' || s[i] == 'C') {
            cards.push_back(temp);
            temp = "";
        }
        temp.push_back(s[i]);
    }
    cards.push_back(temp);

    vector<vector<string>> discards(4, vector<string>());
    string heads = "SHDC";
    for(int i = 0; i < (int)heads.size(); i++) {
        map<string, bool> mp;
        mp[string(1, heads[i]) + "10"] = mp[string(1, heads[i]) + "J"] =
            mp[string(1, heads[i]) + "Q"] = mp[string(1, heads[i]) + "K"] =
                mp[string(1, heads[i]) + "A"] = false;

        for(auto card : cards) {

            if(mp.find(card) == mp.end()) {
                discards[i].push_back(card);
            } else {
                mp[card] = true;
            }
            bool ok = true;
            for(auto p : mp) {
                if(!p.second)
                    ok = false;
            }
            if(ok)
                break;
        }
    }
    int mini = 0;
    for(int i = 0; i < 4; i++) {
        if(discards[i].size() < discards[mini].size())
            mini = i;
    }
    string ans = "";
    for(auto s : discards[mini])
        ans += s;
    if((int)ans.size() == 0) {
        cout << "0" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
#endif