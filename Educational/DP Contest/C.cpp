#include<iostream>
#include <vector>

using namespace std;

int main (){

  int n = 0;
  cin >> n;
  vector<int> a;
  vector<int> b;
  vector<int> c;
  for(int i = 0; i < n; i++){
    int ai, bi, ci;
    cin >> ai >> bi >> ci;
    a.push_back(ai);
    b.push_back(bi);
    c.push_back(ci);
  }
    vector<int> ar = a;
    vector<int> br = b;
    vector<int> cr = c;
  for(int i = 1; i < n; i++){
      ar[i] = max(br[i-1] + a[i], cr[i-1] + a[i]);
      br[i] = max(ar[i-1] + b[i], cr[i-1] + b[i]);
      cr[i] = max(br[i-1] + c[i], ar[i-1] + c[i]);

  }
  cout << max(ar[n-1], max(br[n-1] , cr[n-1]));
  return 0;
}

