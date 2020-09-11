#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool u[51];
int w[51];

int T, N;
map<int, int> M;
int mx, mxid, res;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);

    cin >> T;
    while (T--) {
        M.clear();
        mx = 0;
        mxid = 0;
        res = 0;

        cin >> N;

        for (int i = 1; i <= N; ++i) {
            u[i] = 0;
            cin >> w[i];
        }

        for (int j = 2; j <= 100; ++j) {
            for (int i = 1; i < j; ++i) {
                if (count(w + 1, w + N + 1, i)) {
                    M[j] += min(count(w + 1, w + N + 1, i), count(w + 1, w + N + 1, j - i));
                }
            }
        }

        for (auto i : M) {
            if (mx < i.second) {
                mxid = i.first;
                mx = i.second;
            }
            mx = max(mx, i.second);
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; j++) {
                if ((u[i] || u[j]) || (i == j)) {
                    continue;
                }
                if (w[i] + w[j] == mxid) {
                    u[i] = 1;
                    u[j] = 1;
                    res++;
                }
            }
        }

        cout << res << "\n";
    }
}