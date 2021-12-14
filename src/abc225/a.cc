#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    set<string> res;
    sort(s.begin(), s.end());
    do {
        res.insert(s);
    } while(next_permutation(s.begin(), s.end()));
    return res.size();
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif