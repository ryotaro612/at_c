#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    if(s == "SUN") {
        return 7;
    }
    if(s == "MON") {
        return 6;
    }
    if(s == "TUE") {
        return 5;
    }
    if(s == "WED") {
        return 4;
    }
    if(s == "THU") {
        return 3;
    }
    if(s == "FRI") {
        return 2;
    }
    if(s == "SAT") {
        return 1;
    }
    return -1;
}
/*
int main() {
    string s;
    cin >> s;
    cout << solve(s);
}
*/