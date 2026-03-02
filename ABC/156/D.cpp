#include <iostream>

using namespace std;
typedef long long ll;

ll pow_mod(ll base, ll exp, ll mod = 1000000000, ll mod_add = 7) {
    ll mod_f = mod + mod_add; // just in case it s not + 7;
    ll f = 1;
    base %= mod_f;
    while (exp >= 1) {
        if (exp & 1) f = (f * base) % mod_f;

        base = (base * base) % mod_f;

        exp /= 2;
    }
    return f;
}

ll nCr(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;

    ll top = 1;
    ll bottom = 1;
    ll MOD = 1000000007;

    ll bottom_nl = n - k;


    // TODO: Write a loop to calculate 'top' and 'bottom'
    for (int i = 1; i <= k; i++) {
        top = (top * (n - i + 1)) % MOD;
        bottom = (bottom * i) % MOD;
    }

    // Multiply top by the Modular Multiplicative Inverse of bottom
    return (top * pow_mod(bottom, 1000000005)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a, b;
    cin >> n >> a >> b;
    ll na = (nCr(n, a) + 1000000007) % 1000000007;
    ll nb = (nCr(n, b) + 1000000007) % 1000000007;
    cout << ((pow_mod(2, n) - 1 - na - nb) % 1000000007 + 1000000007) % 1000000007;
    return 0;
}
