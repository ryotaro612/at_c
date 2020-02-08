// robot_arms
#include <vector>

using namespace std;

class Answer {
  private:
    long long m;
    vector<long long> d;
    vector<vector<char>> w;
  public:
    Answer();
    Answer(long long mm, vector<long long> dd, vector<vector<char>> ww);
    long long get_m();
    vector<long long> get_d();
    vector<vector<char>> get_w();
    bool operator==(const Answer & lhs) const;
};

Answer robot_arms(long long n, vector<long long> x, vector<long long> y);
