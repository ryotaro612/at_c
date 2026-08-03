#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// cand が a 進数表記で回文かどうか判定する関数
bool is_palindrome_in_base(long long cand, long long a) {
  vector<int> digits;
  long long c = cand;
  while (c > 0) {
    digits.push_back(c % a);
    c /= a;
  }

  int l = 0, r = digits.size() - 1;
  while (l < r) {
    if (digits[l] != digits[r]) {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

int main() {
  // 高速化のための入出力設定
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long a, n;
  if (!(cin >> a >> n))
    return 0;

  vector<long long> cands;

  // 1桁の回文数 (1〜9)
  for (int i = 1; i <= 9; ++i) {
    if (i <= n) {
      cands.push_back(i);
    }
  }

  // 2桁以上の回文数を生成
  long long i = 1;
  while (true) {
    string s = to_string(i);
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    // 偶数桁の回文数 (例: "1" -> "11")
    string p_even_str = s + rev_s;

    // 桁数が大きすぎて overflow するのを防ぐチェック
    if (p_even_str.length() > to_string(n).length()) {
      break;
    }

    long long p_even = stoll(p_even_str);
    if (p_even <= n) {
      cands.push_back(p_even);
    } else {
      break; // n を超えたら終了
    }

    // 奇数桁の回文数 (例: "1" -> "101", "111", ...)
    for (int j = 0; j < 10; ++j) {
      string p_odd_str = s + to_string(j) + rev_s;
      if (p_odd_str.length() <= to_string(n).length()) {
        long long p_odd = stoll(p_odd_str);
        if (p_odd <= n) {
          cands.push_back(p_odd);
        }
      }
    }

    i++;
  }

  // ソート (元のコードに合わせた処理)
  sort(cands.begin(), cands.end());

  // a進数でも回文になるものの総和を計算
  long long res = 0;
  for (long long cand : cands) {
    if (is_palindrome_in_base(cand, a)) {
      res += cand;
    }
  }

  cout << res << "\n";

  return 0;
}
