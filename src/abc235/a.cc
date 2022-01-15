#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    string abc;
    cin >> abc;
    int res = stoi(abc);
    string bca = {abc[1], abc[2], abc[0]};
    res += stoi(bca);
    string cab = {abc[2], abc[0], abc[1]};
    res += stoi(cab);
    cout << res << endl;
    return 0;
}
#endif