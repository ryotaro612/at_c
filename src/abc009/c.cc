#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(string head, string s, int k) {
    int count = 0;

    vector<int> c_s(26, 0);
    for(auto ss : s) {
        c_s[ss - 'a']++;
    }

    for(int i = 0; i < (int)head.size(); i++) {
        c_s[head[i] - 'a']--;
        if(head[i] != s[i])
            count++;
    }

    for(int i = head.size(); i < (int)s.size(); i++) {
        int index = s[i] - 'a';
        if(c_s[index] > 0) {
            c_s[index]--;
        }
    }

    for(auto aa : c_s) {
        count += aa;
    }
    return count <= k;
}

string solve(int n, int k, string s) {
    string t = "";
    string cands = string(s);
    sort(cands.begin(), cands.end());
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (int)cands.size(); j++) {
            if(ok(t + cands[j], s, k)) {
                t += cands[j];
                cands.erase(cands.begin() + j);
                break;
            }
        }
    }
    return t;
}
/*
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << solve(n, k, s) << endl;
}
*/