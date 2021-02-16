#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

    int N; cin >> N;

    int pre, cur, M = 0, c = 0;
    cin >> pre;

    for (int i = 0; i < N-1; ++i) {
        cin >> cur;
        if (pre >= cur) c += pre - cur;
        else {
            M = max(M, c);
            c = 0;
        }
        pre = cur;
    }

    cout << max(M, c);
}