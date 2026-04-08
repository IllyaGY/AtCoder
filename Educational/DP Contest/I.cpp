#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<bool> vecb;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n;
    cin >> n;
    ll heads = n/2 + 1;
    vector<vector<ld>> dp(n + 2, vector<ld> (n + 1, 0));
    vector<ld> pr1(n, 0 );
    dp[0][0] = 1;
    for (ll i = 0; i < n; i++)
    {
        cin >> pr1[i];
    }


    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= i; j++)
        {
            dp[i + 1][j] += dp[i][j] * (1 - pr1[i]);
            dp[i + 1][j + 1] += dp[i][j] * pr1[i];
        }
    }
    ld total = 0;
    for (; heads <= n; heads++) total += dp[n][heads];

    cout << fixed << setprecision(15) << total << "\n";
    return 0;



}