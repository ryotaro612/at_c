#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int a, b;
    cin >> a >> b;
    string aa, bb;
    for(int i = 0; i < b; i++)
        aa.push_back(a + '0');
    for(int i = 0; i < a; i++)
        bb.push_back(b + '0');

    vector<string> res = {aa, bb};
    sort(res.begin(), res.end());
    cout << res[0] << endl;
    return 0;
}
#endif