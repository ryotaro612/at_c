// #ifndef ONLINE_JUDGE
// #define _GLIBCXX_DEBUG
// #include <string>
// #endif
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using ld = long double;
// using ull = unsigned long long;
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define as_int(a) static_cast<int>(a)

// bool is_dividable(int year, int month, int day) {
//   return year % month == 0 && year % (month * day) == 0;
// }
// string to_s(int year, int month, int day) {
//   string s = to_string(year);
//   s += "/";
//   if (month < 10)
//     s += "0";
//   s += to_string(month);
//   if (day < 10)
//     s += "0";
//   s += to_string(day);
//   return s;
// }

// //#ifdef ONLINE_JUDGE
// int main() {
//   string s;
//   cin >> s;
//   string temp = "";
//   int i = 0;
//   for (; s[i] != '/'; i++)
//     temp.push_back(s[i]);
//   i++;
//   int year = stoi(s);
//   temp = "";
//   for (; s[i] != '/'; i++)
//     temp.push_back(s[i]);
//   int month = stoi(s);
//   i++;
//   temp = "";
//   for (; i < as_int(s.size()); i++)
//     temp.push_back(s[i]);
//   int day = stoi(s);
//   set<int> a = {1, 3, }
//   while (true) {
//     if (is_dividable(year, month, day)) {
//       cout << to_s(year, month, day) << endl;
//     }
//     if(month == 12 && day == 31){
//       year ++;
//       month = 1;
//       day = 1;
//     } else if(month)

//   }
//   return 0;
// }
// //#endif
