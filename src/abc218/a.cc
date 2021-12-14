#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    string s;
    cin >> n >> s;

    if(s[n - 1] == 'o')
        cout << "Yes";
    else
        cout << "No";

    cout << endl;
    return 0;
}
#endif