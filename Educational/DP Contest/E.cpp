#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    ll mx_val = 0; 
    for (ll i = 1; i <=n; i++)
    {
        cin >> p[i].first;
        cin >> p[i].second;
        mx_val += p[i].second; 
    }

    
    vector<vector<ll>> tb (mx_val + 1, vector<ll> (n + 1, -1));
    
    ll mx_val_ach = 0; 
    for (ll i = 0; i <= mx_val; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
           tb[i][j] = tb[i][j-1]; //we only need this, since taking the previous i-1 
           //value will not make the value of the weight at the cell equal to i
           if (i - p[j].second >= 0){
               ll weight = (tb[i - p[j].second][j-1] < 0 ? 0 : tb[i-p[j].second][j-1]) + p[j].first;
               ll value = tb[i - p[j].second][j - 1] < 0 ? 0 : i-p[j].second;

               if(weight <= wgt && value + p[j].second == i){
                    if(tb[i][j] == -1) tb[i][j] = weight;
                    else tb[i][j] = min(weight, tb[i][j]);
                }
           }


            if(tb[i][j] <= wgt && tb[i][j] >= 0) mx_val_ach = max(mx_val_ach, i);
        }
    }
    cout << mx_val_ach;
    return 0;



}