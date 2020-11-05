#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, K;
int par[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i <= 100000; ++i) par[i] = -1;

    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push({ 0, N });

    while (!pque.empty()) {
        int cur, cd; tie(cd, cur) = pque.top(); pque.pop();

        if (cur == K) {
            if (N == K) cout << "0\n" << K;
            else {
                vector<int> history(1, K);
                int p = K;
                while (p != N) {
                    p = par[p];
                    history.push_back(p);
                }
                cout << history.size() - 1 << "\n";
                for (int i = history.size() - 1; i >= 0; --i)
                    cout << history[i] << " ";
            }
            break;
        }

        if (cur * 2 <= 100000 && par[cur * 2] == -1) {
            par[cur * 2] = cur;
            pque.push({ cd + 1, cur * 2 });
        }
        if (cur - 1 >= 0 && par[cur - 1] == -1) {
            par[cur - 1] = cur;
            pque.push({ cd + 1, cur - 1 });
        }
        if (cur + 1 <= 100000 && par[cur + 1] == -1) {
            par[cur + 1] = cur;
            pque.push({ cd + 1, cur + 1 });
        }
    }

}