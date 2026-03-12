#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    priority_queue<ll,vector<ll>,greater<ll>> posA;
    priority_queue<ll, vector<ll>, greater<ll>>posB;
    priority_queue<ll, vector<ll>, greater<ll>> posC;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin >> S;
    ll ctr = 0;
    for (int i = 0; i < S.size();i++) {
        if (S[i] == 'A') posA.push(i);
        else if (S[i] == 'B') posB.push(i);
        else  posC.push(i);
    }
    while (!posA.empty() && !posB.empty() && !posC.empty()) {
        while (!posB.empty() && posB.top() <= posA.top()) posB.pop();
        while (!posC.empty() && posC.top() <= posB.top()) posC.pop();
        if (!posB.empty() && !posC.empty()) {
            ctr++;
            posA.pop(); posB.pop(); posC.pop();
        }
        else break;
    }
    cout << ctr;
    return 0;
}
