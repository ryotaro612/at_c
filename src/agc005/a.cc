#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    string x;
    cin >> x;
    stack<char> s;
    for(int i = 0; i < (int)x.size(); i++) {
        // cout << i << endl;
        s.push(x[i]);

        while(s.size() >= 2) {
            char a = s.top();
            s.pop();
            char b = s.top();
            s.pop();
            // cout << " @!" << endl;
            if(!(b == 'S' && a == 'T')) {
                s.push(b);
                s.push(a);
                break;
            }
        }
    }
    cout << s.size() << endl;
    return 0;
}
#endif