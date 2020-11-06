#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    sort(s.begin(), s.end());
    if((int)s.length() <= 3) {
        do {
            int value = 0;
            for(int i = (int)s.length() - 1; i >= 0; i--) {
                value += (s[i] - '0') * pow(10, (int)s.length() - i - 1);
            }
            if(value % 8 == 0) {
                return "Yes";
            }
        } while(next_permutation(s.begin(), s.end()));
        return "No";
    }
    vector<int> digits(10, 0);
    for(char c : s) {
        digits[c - '0']++;
    }

    for(int i = 8; i < 1000; i += 8) {
        vector<int> e_d(10, 0);
        int eight = i;
        for(int j = 0; j < 3; j++) {
            e_d[eight % 10] += 1;
            eight /= 10;
        }

        for(int j = 0; j < 10; j++) {
            if(e_d[j] > digits[j]) {
                break;
            }
            if(j == 9) {
                return "Yes";
            }
        }
    }
    return "No";
}
/*
int main() {
    string s;
    cin >> s;
    cout << solve(s);
}
*/