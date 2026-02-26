#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v (1000001);
    for(int i = 0; i < v.size(); i++) v[i] = i;

    for(int i = 2; i < v.size(); i++) {
        if(v[i] != i) continue;
        int j = i + i;
        while(j < v.size()) {
            if(v[j] == j) v[j] = i;
            j+=i;
        }
    }
    vector<int> s(1000001, 0); //prime div and its count, if count == 1 pairwise , if any 2 -- setwise, else neither
    int size_of_array = n;
    while(n--){
        int val;
        cin >> val;
        int prev = -1; //min prev divisor . should not lose any by idea since it should only grow;
        while(val > 1){
            if(prev != v[val] && v[val] > 1) {
                s[v[val]]++;
                prev = v[val];
            }
            val/=v[val];
        }
    }
    int type = 1 ;
    for(auto && i : s){
        type = (i == size_of_array) ? type = max(type, 3) : (i > 1) ? max(type, 2) : type;
    }
    switch(type){
        case 1:
            cout << "pairwise coprime";
            break;
        case 2:
            cout << "setwise coprime";
            break;
        case 3:
            cout << "not coprime";
            break;
    }

    return 0;
}

