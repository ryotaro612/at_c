#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}
struct Div {

  Div(string s) : div(s) {
    ok = update_ok();
    is_flip = false;
  }

  void flip(int left, int right) {
    reset();
    for (int i = left; i < right; i++) {
      if (div[i] == '0')
        div[i] = '1';
      else
        div[i] = '0';
    }
    ok = update_ok();
  }
  void flip(int left) { flip(left, div.size()); }

  void flip() { is_flip = !is_flip; }

  char head() {
    char c = div[0];
    if (is_flip) {
      if (c == '0')
        return '1';
      else
        return '0';
    } else
      return c;
  }
  char tail() {
    char c = div.back();
    if (is_flip) {
      if (c == '0')
        return '1';
      else
        return '0';
    } else
      return c;
  }

  bool is_good(int left, int right) {
    for (int i = left; i < right - 1; i++) {
      if (div[i] == div[i + 1])
        return false;
    }
    return true;
  }
  bool is_good(int left) { return is_good(left, div.size()); }
  bool is_good() { return ok; }

private:
  string div;
  bool ok;
  bool is_flip;
  void reset() {
    if (is_flip) {
      for (auto &c : div) {
        if (c == '0')
          c = '1';
        else
          c = '0';
      }
    }
    is_flip = false;
  }

  bool update_ok() {
    rep(i, div.size() - 1) {
      if (div[i] == div[i + 1])
        return false;
    }
    return true;
  }
};
int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  int n_div = sqrt(n);
  vector<Div> divs;
  string temp;
  for (int i = 0; i < n; i++) {
    temp.push_back(s[i]);
    if ((int)temp.size() == n_div) {
      divs.push_back(Div(temp));
      temp.clear();
    }
  }
  if (temp.size())
    divs.push_back(Div(temp));
  rep(_, q) {
    int type, l, r;
    cin >> type >> l >> r;
    l--;
    r--;
    if (type == 1) {
      if (l / n_div == r / n_div) {
        divs[l / n_div].flip(l % n_div, r % n_div + 1);
      } else {
        divs[l / n_div].flip(l % n_div);
        for (int i = l / n_div + 1; i < r / n_div; i++)
          divs[i].flip();
        divs[r / n_div].flip(0, r % n_div + 1);
      }

    } else {
      if (l / n_div == r / n_div) {
        if (divs[l / n_div].is_good(l % n_div, r % n_div + 1))
          cout << "Yes";
        else
          cout << "No";
        cout << endl;
      } else {
        bool ok = divs[l / n_div].is_good(l % n_div);
        for (int i = l / n_div + 1; i < r / n_div; i++) {
          ok = ok && divs[i].is_good() && divs[i - 1].tail() != divs[i].head();
          if (!ok)
            break;
        }
        ok = ok && divs[r / n_div].is_good(0, r % n_div + 1) &&
             divs[r / n_div - 1].tail() != divs[r / n_div].head();
        if (ok)
          cout << "Yes";
        else
          cout << "No";
        cout << endl;
      }
    }
  }
  return 0;
}
