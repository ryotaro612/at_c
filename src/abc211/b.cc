#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    vector<string> s(4);
    for(int i = 0; i < 4; i++)
        cin >> s[i];

    set<string> ss;
    for(int i = 0; i < 4; i++)
        ss.insert(s[i]);
    if((int)ss.size() == 4) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
    return 0;
}
#endif