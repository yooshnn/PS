#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tup;

bool dup[2001][2001];

int bfs(int tar) {
    queue<tup> que; que.push({ 1, 0, 0 }); // len, time, clip
    dup[0][0] = dup[1][0] = true;
    while (!que.empty()) {
        int len, time, clip; tie(len, time, clip) = que.front(); que.pop();
        if (len == tar) return time;
        if (len != 1 && !dup[len - 1][clip]) {
            que.push({ len - 1, time + 1, clip });
            dup[len - 1][clip] = true;
        }
        if (clip != 0 && len + clip <= 2000 && !dup[len + clip][clip]) {
            que.push({ len + clip, time + 1, clip });
            dup[len + clip][clip] = true;
        }
        que.push({ len, time + 1, len });
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int s; cin >> s;
    cout << bfs(s);

}