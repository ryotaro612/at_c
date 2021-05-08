#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> ans;
void dfs(int n, string s) {
    if(n == 0) {
        ans.push_back(s);
        return;
    }

    for(int i = 0; i < 3; i++) {
        char c = 'a' + i;
        dfs(n - 1, s + c);
    }
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    dfs(n, "");
    sort(ans.begin(), ans.end());
    for(auto a : ans)
        cout << a << endl;
    return 0;
}
#endif