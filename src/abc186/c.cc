#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string to_oct(int i) {
    int index = 1;
    while(index < i)
        index *= 8;
    string res = "";
    while(i != 0) {
        char c = i / index + '0';
        res.push_back(c);
        i -= i / index * index;
        index /= 8;
    }
    return res;
}

int solve(int n) {
    int res = 0;
    for(int i = 1; i <= n; i++) {
        string i_str = to_string(i);
        if(i_str.find('7') != string::npos)
            continue;
        string oct = to_oct(i);
        //cout << i << "  -> " << oct << endl;
        if(oct.find('7') != string::npos)
            continue;
        res++;
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif