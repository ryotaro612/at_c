#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    string x;
    cin >> x;
    set<char> a;
    for(int i = 0; i < 4; i++)
        a.insert(x[i]);
    if(a.size() == 1) {
        cout << "Weak" << endl;
        return 0;
    }
    if((((x[0] - '0') + 1) % 10 == (x[1] - '0')) &&
       (((x[1] - '0') + 1) % 10 == (x[2] - '0')) &&
       (((x[2] - '0') + 1) % 10 == (x[3] - '0'))) {
        cout << "Weak" << endl;
        return 0;
    }
    cout << "Strong" << endl;
    return 0;
}
#endif