#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

class Query {
  private:
    bool is_rev;
    string head;
    string tail;
  public:
    Query() {
      is_rev = true;
      head = "";
      tail = "";
    }

    Query(bool is_head, string t) {
      is_rev = false;
      if(is_head) {
	head = t;
	tail = "";
      } else {
	head = "";
	tail = t;
      }
    }

    bool is_reverse() {
      return is_rev;
    }
    bool is_head() {
      return head.size() > 0;
    }
    bool is_tail() {
      return tail.size() > 0;
    }

    char get_char() {
      if (is_rev)
	throw logic_error("rev");

      return is_head() ? head[0] : tail[0]; 
    }
};

string string_formation(string s, int q, Query queries[]);
