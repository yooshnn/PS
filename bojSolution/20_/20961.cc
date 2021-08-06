#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

// 0 plava : blue, 1 crvena : red, 2 magenta
enum Color { blue, red, magenta };

int
  N, // # of nodes
  paula, marin, // initial node
  dist[2][100010]; // distance from paula, marin

vector<pii>
  adj[100010]; // {to, color}

vector<int>
  route;
bool
  isRoute[100010],
  isRouteFull = true;

void rd();
void calcDist(int, int, int);
int getRoute(int, int);
bool findEsc(int, int, int, bool);

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  rd();

  memset(&dist[0][0], -1, sizeof dist);

  calcDist(0, paula, paula);
  calcDist(1, marin, marin);

  if (getRoute(paula, paula)) {
    route.push_back(paula), isRoute[paula] = true;
  }

  int winner = -1;

  bool stuck[2] = {true, true};

  for (auto [v, cc] : adj[paula]) {
    if (cc != 1 && v != marin) stuck[0] = false;
  }
  for (auto [v, cc] : adj[marin]) {
    if (cc != 0) stuck[1] = false;
  }

  if (stuck[0]) winner = 1;
  else if (stuck[1]) winner = 0;
  else {

    bool draw = false;
    if (route.size() % 2 == 1) {
      // Paula is likely to win
      // Check for draw conditions
      for (int i : route) {
        if (dist[1][i] == -1 || (dist[0][i] != -1 && dist[1][i] >= dist[0][i])) continue;
        if (findEsc(1, i, i, dist[0][i] == -1)) draw = true;
      }

      winner = (draw ? -1 : 0);
    }
    else {
      // Marin is likely to win
      // Check for 2 draw conditions
      for (int i : route) {
        if (dist[0][i] == -1 || (dist[1][i] != -1 && dist[0][i] > dist[1][i])) continue;
        if (findEsc(0, i, i, dist[1][i] == -1)) draw = true;
      }

      winner = (draw ? -1 : 1);
    }

  }

  switch (winner) {
    case 0: cout << "Paula"; break;
    case 1: cout << "Marin"; break;
    default: cout << "Magenta";
  }

  /* 
  cout << "===== DEBUG =====" << endl;

  cout << "Distance from Paula" << endl;
  for (int i = 1; i <= N; ++i) cout << dist[0][i] << " ";
  cout << endl;

  cout << "Distance from Marin" << endl;
  for (int i = 1; i <= N; ++i) cout << dist[1][i] << " ";
  cout << endl;

  cout << "Route (" << (isRouteFull ? "Full" : "Broken") << ")" << endl;
  for (int i : route) cout << i << ", ";
  /**/

  sad;


}

void rd() {
  cin >> N >> paula >> marin;
  
  for (int i = 0; i < N-1; ++i) {
    int u, v, w;
    string _w;

    cin >> u >> v >> _w;

    switch (_w[0]) {
      case 'p': w = 0; break;
      case 'c': w = 1; break;
      default: w = 2;
    }

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
}

void calcDist(int who, int u, int par) {
  dist[who][u] = dist[who][par] + 1;
  for (auto [v, cc] : adj[u]) {
    if (v != par && cc != !who && dist[who][v] == -1) calcDist(who, v, u);
  }
}

int getRoute(int cur, int par) {
  if (cur == marin) {
    route.push_back(cur), isRoute[cur] = true;
    return cur;
  }
  for (auto [nxt, _] : adj[cur]) {
    if (nxt == par) continue;
    if (getRoute(nxt, cur) != -1) {
      if (cur != paula) {
        route.push_back(cur), isRoute[cur] = true;
        /*
        if (dist[0][cur] != -1 && dist[1][cur] != -1) route.push_back(cur), isRoute[cur] = true;
        else isRouteFull = false;
        */
      }
      return cur;
    }
  }
  return -1;
}

bool findEsc(int who, int u, int par, bool pst) {
  bool ret = false;

  for (auto [v, cc] : adj[u]) {
    if (isRoute[v]) continue;
    if (v != par && cc != !who && dist[who][v] != -1) {
      if (dist[!who][v] == -1 && pst) return true;
      ret |= findEsc(who, v, u, dist[!who][v] == -1);
    }
  }

  return ret;
}