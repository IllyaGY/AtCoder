#include <iostream>
#include <vector>

using namespace std;

int main(){

    long long n;
    cin >> n;
    vector<long long> v;
    while(n--){
        int t;
        cin >> t;
        v.push_back(t);

    }
    sort(v.begin(), v.end());
    if (v.size() % 2){
        cout << v.back();
        return 0;
    }
    else {
        long long repeat = -1;
        long long i = 0, j = v.size()-1;
        while(j && v[j] == v[j-1]) j--;
        if(j != static_cast<long long>(v.size())) j--;
        if(i < j) repeat = v[i] + v[j];
        else repeat = v[i]; 
        while(i < j){
            if(repeat != v[i] + v[j] || repeat < v.back()) {
                repeat = -1;
                break;

            }
            i++, j--;
        }
        if(i > j && repeat != -1) cout << repeat << " ";
        i = 0, j = v.size() - 1;
        long long full = v[i] + v[j];
        while(i < j){
            if(v[i] + v[j] != full) {
                full = -1;
                break;
            }
            i++, j--;
        }
        if(full >= 0 && repeat != full)cout << full << " ";




    }

    return 0;
}
