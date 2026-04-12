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
    vector<vector<ll>> dp(n+1, vector<ll> (n+1, 0));
    vector<ll> s(n+1, 0);

    for (ll i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for (ll i = n; i; i--)
    {
        dp[i][i] = s[i];
        for (ll j = i + 1; j <= n; j++)
        {
            dp[i][j] = max(s[i] - dp[i+1][j], s[j] - dp[i][j-1]);
        }
    }

    cout << dp[1][n];

    return 0;



}
