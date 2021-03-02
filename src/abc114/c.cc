#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dfs(string n) {
    int digit = n[0] - '0';
    ll head = 0ll;
    if(digit >= 7)
        head = 3ll;
    else if(digit >= 5)
        head = 2ll;
    else if(digit >= 3)
        head = 1ll;
    if((int)n.size() == 1)
        return head;
    ll rest = 0ll;
    for(int i = 1; i <= (int)n.size() - 1; i++) {
        rest += pow(3, i);
    }
    return head * pow(3, n.size() - 1) + rest;
}

ll dfs_mono(string n, int index) {
    ll rest = n.size() - 1ll;
    int digit = n[0] - '0';
    if(digit >= index)
        return rest + 1;
    return rest;
}

ll dfs_two(string n, int a, int b) {
    cout << "dfs_two " << a << "  " << b << endl;
    int digit = n[0] - '0';
    ll head;
    if(digit >= a)
        head = 2ll;
    else if(digit >= b)
        head = 1ll;
    else
        head = 0ll;
    if((int)n.size() == 1)
        return head;
    ll rest = 0ll;
    for(int i = 1; i <= (int)n.size() - 1; i++) {
        rest += pow(2, i);
    }
    cout << " rest -> " << rest << " head " << head << " pow "
         << pow(2, n.size() - 1) << endl;
    return head * pow(2, n.size() - 1) + rest;
}

ll solve(string n) {
    ll three = dfs(n);
    ll t75 = dfs_two(n, 7, 5);
    ll t53 = dfs_two(n, 5, 3);
    ll t73 = dfs_two(n, 7, 3);
    ll mono7 = dfs_mono(n, 7);
    ll mono5 = dfs_mono(n, 5);
    ll mono3 = dfs_mono(n, 3);
    cout << "75-> " << t75 << " 53-> " << t53 << " 73-> " << t73 << endl;
    cout << "mono7 " << mono7 << " mono5 " << mono5 << " momo3 " << mono3
         << endl;

    return three - t75 - t53 - t73 + mono7 + mono5 + mono3;
}

#ifndef _LOCAL
int main() {
    string n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif