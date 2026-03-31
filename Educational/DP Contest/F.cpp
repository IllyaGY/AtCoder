#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<bool> vecb;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t ;
    cin >> s >> t;
    vector<vector<string>> p(2, vector<string> (t.size() + 1, ""));

    ll ctr = 0;
    while (ctr < s.size())
    {
        for (ll j = 1; j <= t.size(); j++)
        {
            if (p[0][j].size() >= p[1][j-1].size())
            {
                p[1][j] = p[0][j];
            }
            else p[1][j] = p[1][j-1];

            if (p[1][j].size() < (p[0][j-1].size() + (s[ctr] == t[j-1] ? 1 : 0)))
            {
                p[1][j] = p[0][j-1] + s[ctr];
            }


        }
        swap(p[1], p[0]);
        ctr++;
    }

    cout << p[0][t.size()] << endl;
    return 0;



}