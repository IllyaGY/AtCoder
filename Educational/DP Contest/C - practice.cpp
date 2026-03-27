#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<bool> vecb;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;  cin >> n;
    vector <ll> r (n+1, 0);
    vector<ll> s(n + 1, 0);
    vector<ll> c(n + 1, 0);
    vector<ll> h(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> c[i] >> h[i];
    }

    for (int i = 2; i <= n; i++)
    {
        s[i] = max(c[i-1], h[i-1]) + s[i];
        c[i] = max(s[i-1], h[i-1]) + c[i];
        h[i] = max(c[i-1], s[i-1]) + h[i];
    }
    cout << max(s[n], max(c[n], h[n]));
    return 0;
}