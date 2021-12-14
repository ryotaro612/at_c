#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    ll n = s.size();
    if(n == 1) {
        cout << "YES" << endl;
        return 0;
    }
    if(n == 2) {
        if(s[0] == s[1])
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        return 0;
    }
    vector<ll> a(3, 0ll);
    for(auto c : s) {
        a[c - 'a']++;
    }
    if(n % 3ll == 0ll) {
        if(a[0] == a[1] && a[2] == a[1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }

    ll tri = n / 3ll;
    if(n % 3ll == 1ll) {
        if(a[0] == tri && a[1] == tri && a[2] == tri + 1ll ||
           a[2] == tri && a[0] == tri && a[1] == tri + 1ll ||
           a[2] == tri && a[1] == tri && a[0] == tri + 1ll)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }
    if(a[0] == tri && a[1] == tri + 1ll && a[2] == tri + 1ll ||
       a[2] == tri && a[0] == tri + 1ll && a[1] == tri + 1ll ||
       a[1] == tri && a[2] == tri + 1ll && a[0] == tri + 1ll)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
#endif