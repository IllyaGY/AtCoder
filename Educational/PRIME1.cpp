#include <iostream>
#include <vector>

#define LL_RET(L, x) (((L + x - 1) / x) * x)

using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while (t--) {
        ll R, L;
        cin >> L >> R;
        vector<ll> v(R-L + 1, 1);


        ll start = 2;
        if (L == 1) v[0] = 0;
        for (ll i = LL_RET(L, start); start * start <= R;) {
            ll val = (i / start) == 1 ? i + start : i;
            while (val <= R) {
                if (v[val-L] && val != start){
                    v[val - L] = 0;
                }
                val += start;
            }
            ++start;
            i = LL_RET(L, start);
        }
        int ctr = 0;
        for (ll i = L; i <= R ; i++) {
            if (v[i - L]) cout << i << "\n";
        }
        cout << "\n";

    }
    return 0;
}

