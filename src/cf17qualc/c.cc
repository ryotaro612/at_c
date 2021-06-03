#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int can_palindrome(string s) {

    string a;
    for(auto c : s) {
        if(c != 'x')
            a.push_back(c);
    }

    int n = (int)a.size();
    for(int i = 0; i < n; i++) {
        if(a[i] != a[n - 1 - i])
            return -1;
    }

    return (n + 1) / 2;
}

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    int chunk_num = can_palindrome(s);
    if(chunk_num == -1) {
        cout << -1 << endl;
        return 0;
    }
    if(chunk_num == 0) {
        cout << 0 << endl;
        return 0;
    }

    int l = 0, r = s.size() - 1;
    int ans = 0;
    for(int i = 0; i < chunk_num; i++) {
        int c_l = 0;
        while(s[l] == 'x') {
            c_l++;
            l++;
        }
        l++;
        int c_r = 0;
        while(s[r] == 'x') {
            c_r++;
            r--;
        }
        r--;
        ans += abs(c_l - c_r);
    }
    cout << ans << endl;

    return 0;
}
#endif