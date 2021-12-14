#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct A {
    int start;
    char color;
};

ll solve(string s) {
    int n = (int)s.size();
    vector<A> tasks;
    int i = 0;
    char prev = ' ';

    while(i < n - 1) {
        if(prev != s[i] && s[i] == s[i + 1]) {
            tasks.push_back({i, s[i]});
            prev = s[i];
            i += 2;
        } else {
            i++;
        }
    }
    tasks.push_back({n, ' '});
    ll res = 0ll;
    for(int i = 0; i < (int)tasks.size() - 1; i++) {
        ll temp = 0ll;
        for(int j = tasks[i].start; j < (int)tasks[i + 1].start; j++) {
            if(s[j] != tasks[i].color)
                temp++;
        }
        temp += n - tasks[i + 1].start;
        res += temp;
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
#endif