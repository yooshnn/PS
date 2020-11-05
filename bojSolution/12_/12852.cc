#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
int par[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i <= N; ++i) par[i] = -1;

    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push({ 0, N });

    while (!pque.empty()) {
        int cur, cd; tie(cd, cur) = pque.top(); pque.pop();

        if (cur == 1) {
            if (par[1] == -1) cout << "1\n1";
            else {
                vector<int> history(1, 1);
                int p = 1;
                while (par[p] != -1) {
                    p = par[p];
                    history.push_back(p);
                }
                cout << history.size() - 1 << "\n";
                for (int i = history.size() - 1; i >= 0; --i)
                    cout << history[i] << " ";
            }
        }

        if (cur % 3 == 0 && par[cur / 3] == -1) {
            par[cur / 3] = cur;
            pque.push({ cd + 1, cur / 3 });
        }
        if (cur % 2 == 0 && par[cur / 2] == -1) {
            par[cur / 2] = cur;
            pque.push({ cd + 1, cur / 2 });
        }
        if (par[cur - 1] == -1) {
            par[cur - 1] = cur;
            pque.push({ cd + 1, cur - 1 });
        }
    }

}