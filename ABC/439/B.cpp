#include <iostream>
int main() {
    int v;
    std::cin >> v;
    int t = 0;
    int a[2027];
    while (v) {

        int tp = v%10;
        t+= tp * tp;
        v/=10;
        if (!v) {
            if (a[t]) break;
            a[t] = 1;
            v = t;
            t = 0;
        }
    }
    std::cout << (t == 1 ? "Yes" : "No");
    return 0;
}


