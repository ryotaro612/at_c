#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    map<string, bool> mp;
    mp["ABC"] = mp["ARC"] = mp["AGC"] = mp["AHC"] = false;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    mp[s1] = mp[s2] = mp[s3] = true;
    for(auto e : mp) {
        if(!e.second)
            cout << e.first << endl;
    }

    return 0;
}
#endif