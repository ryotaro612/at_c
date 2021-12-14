#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char c = tolower(s[--k]);
    s[k] = c;
    cout << s << endl;

    return 0;
}
#endif