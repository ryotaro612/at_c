#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll to_n(string s, map<char, int> &mp) {
    ll n = 0ll;
    for(int i = 0; i < (int)s.size(); i++) {
        n *= 10;
        n += mp[s[i]];
    }
    return n;
}

vector<string> solve(string s1, string s2, string s3) {
    set<char> cs;
    for(auto s : s1)
        cs.insert(s);
    for(auto s : s2)
        cs.insert(s);
    for(auto s : s3)
        cs.insert(s);
    if((int)cs.size() > 10)
        return {"UNSOLVABLE"};

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        map<char, int> mp;
        int i = 0;
        for(auto c : cs)
            mp[c] = v[i++];
        ll n1 = to_n(s1, mp), n2 = to_n(s2, mp), n3 = to_n(s3, mp);
        if(n1 == 0 || n2 == 0 || n3 == 0)
            continue;
        if(n1 + n2 == n3) {
            string a1 = to_string(n1), a2 = to_string(n2), a3 = to_string(n3);
            if(a1.size() == s1.size() && a2.size() == s2.size() &&
               a3.size() == s3.size())
                return {a1, a2, a3};
        }

    } while(next_permutation(v.begin(), v.end()));
    return {"UNSOLVABLE"};
}

#ifdef ONLINE_JUDGE
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    auto res = solve(s1, s2, s3);
    for(auto r : res)
        cout << r << endl;
    return 0;
}
#endif