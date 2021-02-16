#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

    int N, n; cin >> N;
    n = N+10;

    vector<pli> v1(n);
    vector<ll> v2(n, 0), ml(n, 0), mr(n, 0), res(n);
    for (int i = 1; i <= N+1; ++i) cin >> v1[i].first, v1[i].second = i;
    for (int i = 1; i <= N; ++i) cin >> v2[i];

    sort(v1.begin() + 1, v1.begin() + N + 2);
    sort(v2.begin() + 1, v2.begin() + N + 1);

    for (int i = 1; i <= N; ++i) {
        ml[i] = max({ml[i-1], v1[i].first - v2[i], 0LL});
    }
    for (int i = N; i >= 1; --i) {
        mr[i] = max({mr[i+1], v1[i+1].first - v2[i], 0LL});
    }

    // for (int i = 1; i <= N; ++i) cout << ml[i] << " "; cout << endl;
    // for (int i = 1; i <= N; ++i) cout << mr[i] << " "; cout << endl;

    // ml[0] = mr[N+1] = 1e8;
    for (int i = 1; i <= N+1; ++i) {
        // cout << "i : " << i << ", " << ml[i-1] << " " << mr[i] << endl;
        res[v1[i].second] = max(ml[i-1], mr[i]);
    }

    for (int i = 1; i <= N+1; ++i) {
        cout << res[i] << " ";
    }
}