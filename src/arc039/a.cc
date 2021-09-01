#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    string a, b;
    cin >> a >> b;

    int ans = stoi(a) - stoi(b);

    for(int i = 1; i < 10; i++) {
        string aa = a, bb = b;
        aa[0] = bb[0] = i + '0';
        ans = max(stoi(aa) - stoi(b), ans);
        ans = max(stoi(a) - stoi(bb), ans);
    }
    for(int i = 0; i < 10; i++) {
        string aa = a, bb = b;
        aa[1] = bb[1] = i + '0';
        ans = max(stoi(aa) - stoi(b), ans);
        ans = max(stoi(a) - stoi(bb), ans);
    }
    for(int i = 0; i < 10; i++) {
        string aa = a, bb = b;
        aa[2] = bb[2] = i + '0';
        ans = max(stoi(aa) - stoi(b), ans);
        ans = max(stoi(a) - stoi(bb), ans);
    }
    cout << ans << endl;
    return 0;
}
#endif