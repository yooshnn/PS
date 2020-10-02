#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N, Q;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Q; v.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= Q; ++i) {
        int p, q; cin >> p >> q;
        cout << v[q] - v[p - 1] << "\n";
    }

    return 0;
}