#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    map<string, string> mp;
    mp["Sunny"] = "Cloudy";
    mp["Cloudy"] = "Rainy";
    mp["Rainy"] = "Sunny";
    cout << mp[s] << endl;
    return 0;
}
#endif