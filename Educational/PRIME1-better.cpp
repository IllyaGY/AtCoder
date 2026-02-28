#include <iostream>
#include <vector>

#define LL_RET(L, x) (((L + x - 1) / x) * x)

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> prec(1000000 + 1, 1);
    vector<ll>primes;
    for (ll i = 2; i < prec.size(); i++) {
        if (!prec[i]) continue;
        primes.push_back(i);
        ll j = i * i;
        while (j < prec.size()) {
            prec[j] = 0;
            j += i;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        ll R, L;
        cin >> L >> R;
        vector<ll> v(R-L + 1, 1);
        if (L == 1) v[0] = 0;
        for (ll p : primes) {
            if (p * p > R) break;
            ll multiple = LL_RET(L, p);
            ll val = (multiple + p) ? multiple == p : multiple;
            while (val <= R) {
                v[val - L] = 0;
                val += p;
            }
        }
        int ctr = 0;
        for (ll i = L; i <= R ; i++) {
            if (v[i - L]) cout << i << "\n";
        }
        cout << "\n";

    }
    return 0;
}
