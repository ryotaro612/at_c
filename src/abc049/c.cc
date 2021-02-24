#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    queue<int> que;
    que.push(0);
    while(!que.empty()) {
        int start = que.front();
        que.pop();
        if(start >= (int)s.size())
            return "YES";

        if(s.substr(start, 5) == "dream" || s.substr(start, 5) == "erase") {
            que.push(start + 5);
        }
        if(s.substr(start, 6) == "eraser") {
            que.push(start + 6);
        }
        if(s.substr(start, 7) == "dreamer") {
            que.push(start + 7);
        }
    }
    return "NO";
}

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}
#endif