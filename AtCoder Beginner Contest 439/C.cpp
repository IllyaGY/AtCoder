#include <iostream>
#include <vector>
#include <math.h>
int main() {
    std::vector<int> s;
    int n;
    std::cin >> n;
    int ct = 0;
    while (n) {
        int t = 1;
        while (t < n/2) {
            int sqr = sqrt(n - t*t);
            if (((n - sqr * sqr) == (t * t)) && t && sqr && t != sqr ) {
                s.push_back(n); ct++;
                break;
            }
            t++;
        }
        n--;
    }
    std::cout << ct << "\n";
    while (ct) {
        std::cout << s[ct - 1] << " ";
        ct--;
    }



}


