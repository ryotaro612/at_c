#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(string s) {
    vector<int> cs(26);
    for(auto c : s) {
        cs[c - 'a']++;
    }
    int num = 0;
    for(int i = 0; i < 26; i++) {
        if(cs[i] % 2 != 0) {
            cs[i]--;
            num++;
        }
    }
    if(num == 0)
        return (int) s.size();
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i = 0; i < num; i++) {
        que.push(1);
    }
    for(int i=0;i<26;i++) {
        while(cs[i] > 0) {
            int item = que.top();
            que.pop();
            que.push(item+2);
            cs[i] -= 2;
        }
    }
    return que.top();
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;

    cout << solve(s) << endl;
}
#endif