#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<bool> vecb;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll h, w ;
    cin >> h >> w;
    vector<string> s(h + 1 , "");
    vector<vector<ll>> v(h+1, vector<ll>(w+1, 0));
    v[0][1] = 1;
    ll mod = 1e9 + 7 ;
    for (ll i = 1; i <= h; i++)
    {
        cin>>s[i];
        if (s[i][0] == '#') v[i][1] = 0;
        else v[i][1] = v[i-1][1];
        for (ll j = 2; j <= w; j++)
        {
            if (s[i][j-1] != '.') continue;

            v[i][j] = v[i][j-1] + v[i-1][j];
            v[i][j] %= mod;


        }
    }

    cout << v[h][w] << endl;
    return 0;



}