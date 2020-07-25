#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

typedef long long ll;

const int siz=2000;

int top[siz][siz];
int bottom[siz][siz];
int left[siz][siz];
int right[siz][siz];
int center[siz][siz];

long long lamp(std::vector<std::vector<char>> area) {

  int h = area.size();
  int w = area.at(0).size();

  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      // center
      if(area[i][j] == '.') {
	center[i][j]= 1;
      }

      // left
      if(j==0 || area[i][j-1] == '#') {
      } else {
	left[i][j] += left[i][j-1] + 1;
      }

      // top
      if(i==0 || area[i-1][j] == '#') {
      } else {
	top[i][j] += top[i-1][j] + 1;
      }     
    }
  }

  int ans = 0;

  for(int i=h-1;i>=0;i--) {
    for(int j=w-1;j>=0;j--) {
      // right
      if(j==w-1 || area[i][j+1] == '#') {
      } else {
	right[i][j] += right[i][j+1] + 1;
      }

      // bottom
      if(i==h-1 || area[i+1][j] == '#') {
      } else {
	bottom[i][j] += bottom[i+1][j] + 1;
      }
      //std::cout << bottom[i][j];

      if(area[i][j] != '#') {
	ans = std::max(ans, center[i][j] + top[i][j] + bottom[i][j] + left[i][j] + right[i][j]);
      }
    }
  }

  return ans;
  
}
/*
int main() {
  long long h, w;
  std::cin >> h;
  std::cin >> w;
  std::string s;
  std::getline(std::cin, s);
  
  std::vector<std::vector<char>> area(h);
  for(ll i=0;i<h;i++) {    
    std::getline(std::cin, s);
    std::vector<char> v(w);
    area[i] = v;
    for(ll j=0;j<w;j++) {
      area[i][j] = s[j];
    }
  }
  std::cout << lamp(area);
}
*/
