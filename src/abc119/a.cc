#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    int year = stoi(string(s.begin(), s.begin() + 4));
    int month = stoi(string(s.begin() + 5, s.begin() + 7));
    string h = "Heisei", t = "TBD";
    if(year < 2019)
        return h;
    else if(2020 < year)
        return t;
    if(month <= 4)
        return h;
    return t;
}

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
#endif