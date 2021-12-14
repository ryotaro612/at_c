#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
int main() {
    char b;
    cin >> b;
    char res;
    switch(b) {
    case 'A':
        cout << 'T' << endl;
        break;
    case 'T':
        cout << 'A' << endl;
        break;
    case 'C':
        cout << 'G' << endl;
        break;
    case 'G':
        cout << 'C' << endl;
        break;
    }
    return 0;
}
#endif