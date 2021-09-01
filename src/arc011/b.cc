#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++)
        cin >> words[i];

    vector<int> a(128, -1);
    a['b'] = a['c'] = 1;
    a['d'] = a['w'] = 2;
    a['t'] = a['j'] = 3;
    a['f'] = a['q'] = 4;
    a['l'] = a['v'] = 5;
    a['s'] = a['x'] = 6;
    a['p'] = a['m'] = 7;
    a['h'] = a['k'] = 8;
    a['n'] = a['g'] = 9;
    a['z'] = a['r'] = 0;

    vector<string> parts;
    for(int i = 0; i < n; i++) {
        string temp;
        for(auto c : words[i]) {
            char cc = tolower(c);
            if(a[cc] != -1) {
                temp.push_back('0' + a[cc]);
            }
        }
        if((int)temp.size() != 0)
            parts.push_back(temp);
    }
    string res;
    for(int i = 0; i < (int)parts.size(); i++) {
        res += parts[i];
        if(i != (int)parts.size() - 1)
            res += " ";
    }
    cout << res << endl;
    return 0;
}
#endif