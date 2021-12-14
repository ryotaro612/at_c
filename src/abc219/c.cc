#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<string> solve(string x, int n, vector<string> s) {
    unordered_map<char, char> mp;
    rep(i, 26) {
        char key = 'a' + i;
        mp[x[i]] = key;
    }
    map<string, string> converted_map;
    for(auto name : s) {
        string converted_name = "";
        for(auto c : name)
            converted_name.push_back(mp[c]);
        converted_map[converted_name] = name;
    }
    vector<string> ans;
    for(auto p : converted_map) {
        ans.push_back(p.second);
    }
    // sort(converted.begin(), converted.end());
    // rep(i, n) { ans[i] = converted[i].second; }


    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    string x;
    cin >> x;
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<string> res = solve(x, n, s);
    for(auto a : res)
        cout << a << endl;

    return 0;
}
#endif