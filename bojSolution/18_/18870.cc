#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N; cin >> N; vector<pii> v(N); vector<int> res(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first; v[i].second = i;
    }
    sort(v.begin(), v.end());

    for (int i = 0, c = 0; i < N; ++i, ++c) {
        int val = v[i].first, id = v[i].second;
        res[id] = c;
        while (++i < N && v[i].first == val) res[v[i].second] = c;
        if (--i == N - 1) break;
    }

    for (int r : res) cout << r << " ";


    return 0;
}