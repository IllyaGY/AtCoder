#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v (100001);
    for(int i = 0; i < v.size(); i++) v[i] = i;

    for(int i = 2; i < v.size(); i++) {
        if(v[i] != i) continue;
        int j = i + i;
        while(j < v.size()) {
            v[j] = min(i, v[j]);
            j+=i;
        }
    }
    unordered_set<int> s;
    while(n--){
        int val;
        cin >> val;
        while(val > 1){
            if(v[val] > 1) s.insert(v[val]);
            val/=v[val];
        }
    }
    vector<int> vals = {1};  // 1 is included by default;
    for(int i = 2; i <= m; i++){
        int j = i;
        bool c = 0;
        while(j > 1){
            c = 1;
            if(s.contains(v[j])){
                c = 0;
                break;
            }
            j/=v[j];
        }
        if(c) {
            vals.push_back(i);
        }

    }
    cout << vals.size() << "\n";
    for(auto &&i : vals){cout << i << "\n"; }

    return 0;
}

