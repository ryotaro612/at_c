#include<utility>
#include<vector>

class Operation {
  public:
    std::pair<int, int> from;
    std::pair<int, int> to;
    Operation(std::pair<int, int> from, std::pair<int, int> to);
};

class  Answer {
  public:
    int n;
    std::vector<Operation> operations;
    Answer(int n, std::vector<Operation> operations);
};

Answer make_them_even(int h, int w, std::vector<std::vector<int>> a);
