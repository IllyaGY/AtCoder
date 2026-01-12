#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cmp {
  bool operator()(const std::pair<int,int>& a,
                  const std::pair<int,int>& b) const {


      return (a.first + a.second) <= (b.first + b.second);

  }
};


int func(int pairs) {
  priority_queue<pair<int, int>,std::vector<std::pair<int,int>>,Cmp> wp; //power, weight
  long long tw = 0;
  while (pairs--) {
    int p = 0, w = 0;
    cin >> w >> p;
    wp.push(pair(p, w));
    tw+=w;
  }

  long long pull = 0;
  int bulls = wp.size();
  while(bulls--) {
    pull+=wp.top().first;
    tw-=wp.top().second;
    wp.pop();
    if (tw <= pull) break;
  }
  return bulls;
}

int main(){

  int cases = 0;
  cin >> cases;

  while (cases--) {
    int i = 0;
    cin >> i;
    std::cout <<  func(i) << "\n";
  }



  return 0;
}
