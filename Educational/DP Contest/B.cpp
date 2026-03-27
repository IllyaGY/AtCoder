#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<bool> vecb;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ,k;  cin >> n >> k;
    vec v1 (n+1,  -1);
    vec v (n+1, LLONG_MAX - 300000);
    for (ll i = 1; i <= n; i++) cin >> v[i];
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = i - k; j < i; j++)
        {
            if (j >= 0)
                v1[i] = min(abs(v[j] - v[i]) + (v1[j] >= 0 ? v1[j] : 0), (v1[i] >= 0 ? v1[i] : LLONG_MAX));
        }
    }
    cout << v1[n];
    return 0;
}