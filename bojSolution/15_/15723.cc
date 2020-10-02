#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[26];
bool visit[26][26];

bool bfs(int b, int e) {
    queue<int> Q;
    Q.push(b);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (cur == e) return true;
        for (int edge : v[cur]) {
            if (visit[cur][edge]) continue;
            visit[cur][edge] = true;
            Q.push(edge);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; char p, q;
        cin >> p >> s >> q;
        v[p - 'a'].push_back(q - 'a');
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        memset(visit, false, sizeof(visit));
        string s; char p, q;
        cin >> p >> s >> q;
        cout << (bfs(p - 'a', q - 'a') ? "T" : "F") << "\n";
    }


    return 0;
}