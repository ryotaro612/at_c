#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

char solve(string sa, string sb, string sc) {
    map<char, string> mp;
    mp['a'] = sa;
    mp['b'] = sb;
    mp['c'] = sc;
    char turn = 'a';
    while(true) {
        if((int)mp[turn].size() == 0)
            return toupper(turn);
        char temp = mp[turn][0];
        mp[turn].erase(mp[turn].begin());
        turn = temp;
    }
    return ' ';
}

#ifdef ONLINE_JUDGE
int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    cout << solve(sa, sb, sc) << endl;
}
#endif