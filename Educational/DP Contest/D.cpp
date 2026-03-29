#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<bool> vecb;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, wgt;
    cin >> n >> wgt;
    vector<pair<ll, ll>> p(n + 1, {0,0});
    for (ll i = 1; i <=n; i++)
    {
        cin >> p[i].first;
        cin >> p[i].second;
    }


    vector<vector<ll>> tb (wgt + 1, vector<ll> ( n + 1,0));

    for (ll i = 1; i <= wgt; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
           tb[i][j] = max(tb[i][j-1], tb[i-1][j]);
           if (i - p[j].first >= 0)
           {
               tb[i][j] = max(tb[i][j], tb[i - p[j].first][j - 1] + p[j].second);
           }

        }
    }
    cout << tb[wgt][n];
    return 0;



}