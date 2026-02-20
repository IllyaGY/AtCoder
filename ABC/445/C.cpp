#include <iostream>
#include <vector>


using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(1, 0);
    int temp = n;
    while (temp--) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    for (int i = n; i >= 1; i--){
        if (i != v[i])  v[i] = v[v[i]];

    }
    for (int i = 1; i <= n; i++) cout << v[i] << " ";

    return 0;


}

