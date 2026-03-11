#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    ll t = n;
    vector<pair<ll, ll>> v;
    while(t--){
        ll val;
        cin >> val;
        v.push_back({val, n - t});
    }
    sort(v.begin(), v.end());
    while(q--){
        ll k;
        cin >> k;
        ll ctr = 0;
        unordered_set<ll> s;
        for(ll i = 0; i < k; i++){
            ll val;
            cin >> val;
            s.insert(val);
        }
        while(s.contains(v[ctr].second)) {
            ctr++;
        }
        cout << v[ctr].first << "\n";
    }
    return 0;
}
