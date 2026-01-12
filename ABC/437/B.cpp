#include <iostream>
#include <vector>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<std::vector<int>> v (a, std::vector<int> (91, 0));
    std::vector<int> mxv (a, 0);
    int temp = 0;
  while (a--) {
      int t = b;
      while (t--) {
          std::cin >> temp;
          v[a][temp]++;
      }
  }
  int mx = 0;

  while (c--) {
      int inp = 0;
      std::cin >> inp;
      for (int i = 0; i < mxv.size(); i++) {
          mxv[i] += v[i][inp];
          mx = mx > mxv[i] ? mx : mxv[i];
      }
  }
  std::cout << mx;
  return 0;
}
