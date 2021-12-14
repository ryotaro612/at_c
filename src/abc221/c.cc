#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(string s) {

    vector<char> digits(s.begin(), s.end());
    sort(digits.begin(), digits.end());
    int n = s.size();
    ll ans = 0ll;
    do {
        for(int i = 1; i < n; i++) {
            string a(digits.begin(), digits.begin() + i);
            string b(digits.begin() + i, digits.end());
            if(a[0] != '0' || b[0] != '0') {
                ans = max(ans, stoll(a) * stoll(b));
            }
        }

    } while(next_permutation(digits.begin(), digits.end()));
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif