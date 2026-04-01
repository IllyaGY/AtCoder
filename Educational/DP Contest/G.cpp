#include <iostream>
#include <vector>
#include <queue>
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


    ll n, m ;
    cin >> n >> m;
    vector<vector<ll>> v(n+1);
    queue<ll> starts;
    vector<ll> prt_left (n + 1);
    while (m--)
    {
        ll x,y;
        cin >> x >> y;
        v[x].push_back(y);
        prt_left[y]++;
    }
    vector<ll> p(n+1, 0);
    for (ll i = 1; i < prt_left.size(); i++)
    {
        if (!prt_left[i])
            starts.push(i);
    }


    ll gl_mx = 0;
    while (!starts.empty())
    {
        auto i = starts.front();
        starts.pop();
        for (auto &child : v[i])
        {
            prt_left[child]--;
            if (p[child] < p[i] + 1)
            {
                p[child] = p[i] + 1;
            }
            if (prt_left[child] == 0)
            {
                starts.push(child);
            }
            gl_mx = max(gl_mx, p[child]);


        }
    }

    cout << gl_mx << endl;
    return 0;



}