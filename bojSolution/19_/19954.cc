#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll maxBanana = 0, minMove = 1000000001;
ll R, C, X;
unordered_map<ll, pii> IGRUS;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C >> X;
    for (int i = 0; i < X; ++i) {
        ll r, c, d, pos;
        cin >> r >> c >> d;
        pos = c + ((r - 1) % (C * 2)) * d;
        if (pos < 1) pos = pos * -1 + 1;

        if (((pos - 1) / C) % 2 == 0) pos = 1 + ((pos - 1) % C);
        else pos = C - ((pos - 1) % C);

        pii* req = &IGRUS[pos];
        req->first += 1;
        req->second = max(req->second, r - 1);

        if (req->first >= maxBanana) {
            minMove = (req->first > maxBanana) ? req->second : min(minMove, req->second);
            maxBanana = req->first;
        }
    }

    cout << maxBanana << " " << minMove;

    return 0;
}