#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
   	vector<ll> vec (n + 1, -1);
	vector<vector<pair<ll, ll>>> v;
    ll t = n;
   	while(t > 1){
   		ll f, s, l;
   		cin >> f >> s >> l;
   		if (vec[f]==-1) {
   			v.push_back({});
   			vec[f] = (ll) (v.size()-1);
   		}
   		if (vec[s]==-1) {
   			v.push_back({});
   			vec[s] = (ll) (v.size()-1);

   		}
   		v[vec[f]].emplace_back(s,l);
   		v[vec[s]].emplace_back(f,l);
   		t--;

   	}
	ll q , k;
	cin >> q >> k;
	queue<pair<ll,ll>> qe;
	vector<bool> seen (n + 1, 0);
	seen[k]=1;
	vector<ll> shortest_k (n + 1, 0);
	for (auto &i : v[vec[k]]) qe.push(i) ;
	while (!qe.empty()) {
		auto &t = qe.front();
		qe.pop();
		seen[t.first] = 1;
		shortest_k[t.first] = t.second;
		for (auto &i : v[vec[t.first]]) if (!seen[i.first]) qe.emplace(i.first, i.second + t.second);
	}
	while (q--) {
		ll f, s;
		cin >> f >> s;
		cout << shortest_k[f] + shortest_k[s] << "\n";
	}

    return 0;
}
