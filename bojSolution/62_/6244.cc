#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using tup = tuple<double, double, double>; // S(y), S(x), N
using pdd = pair<double, double>;
using pii = pair<int, int>;
using ll = long long;

const int dir4[2][4] = {{0, -1, 0, 1}, {1, 0, -1, 0}};

int R, C;
char pic[260][260];

bool oob(int r, int c) { return r < 1 || c < 1 || r > R || c > C; }

pdd getCent() {
  bool dup[260][260];
  memset(&dup[0][0], 0, sizeof(bool)*260*260);

  int cntMax = -1;
  pdd ret = {0, 0};

  for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
    if (dup[r][c] || pic[r][c] == '.') continue;
    
    int cnt = 0;
    double ySum = 0, xSum = 0;
    dup[r][c] = true;

    queue<pii> que;
    for (que.push({r, c}); !que.empty(); que.pop()) {
      auto [ro, co] = que.front();
      ySum += ro;
      xSum += co;
      cnt += 1;
      for (int i = 0; i < 4; ++i) {
        int nr = ro + dir4[0][i], nc = co + dir4[1][i];
        if (oob(nr, nc) || dup[nr][nc] || pic[nr][nc] == '.') continue;
        dup[nr][nc] = true;
        que.push({nr, nc});
      }
    }

    if (cnt > cntMax) {
      cntMax = cnt;
      ret = {ySum/cnt, xSum/cnt};
    }
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  while (cin >> C >> R) {
    if (C + R == 0) break;
    
    vector<pdd> cent;
    double yRes = 0, xRes = 0;

    while (1) {
      for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
        cin >> pic[r][c];
      }
      cent.push_back(getCent());
      string hr; cin >> hr;
      if (hr[0] == '=') break;
    }

    double T = cent.size() / 2;
    for (int i = 0; i < T; ++i) {
      pdd &a = cent[i + T], &b = cent[i];
      yRes += (a.first - b.first) / T;
      xRes += (a.second - b.second) / T;
    }
    yRes /= T;
    xRes /= T;
    
    cout.precision(2);
    cout << fixed << xRes << " " << yRes << "\n";
  }
}