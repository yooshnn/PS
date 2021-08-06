#define sad return 0
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1000000;

bool pass;
int R, C, K;
int nim[4] = {-INF, INF, INF, -INF};
string dirstr[4] = {"right", "top", "left", "bottom"};

void prep();
void move() {
  int x = (nim[0] ^ nim[1] ^ nim[2] ^ nim[3]);
  if (x == 0 && !pass) {
    cout << "pass" << endl;
    pass = true;
    return;
  }
  assert(x != 0);

  int dir = 0, amnt = 0;

  // cout << "X: " << x << endl;
  // cout << nim[0] << " " << nim[1] << " " << nim[2] << " " << nim[3] << endl;

  for (int d = 0; amnt == 0 && d < 4; ++d) {
    for (int i = 1; i <= nim[d]; ++i) {
      if ((x ^ nim[d] ^ (nim[d] - i)) == 0) {
        dir = d;
        amnt = i;
        break;
      }
    }
  }
  assert(amnt != 0);

  cout << dirstr[dir] << " " << amnt << endl;
  nim[dir] -= amnt;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  prep();

  string dir;
  int amnt;

  while (1) {
    move();

    cin >> dir;
    if (dir == "yuck!") break;
    cin >> amnt;

    switch (dir[0]) {
      case 'r': nim[0] -= amnt; break;
      case 't': nim[1] -= amnt; break;
      case 'l': nim[2] -= amnt; break;
      case 'b': nim[3] -= amnt; break;
      default: break;
    }
  }

  sad;
  
}

void prep() {
  cin >> R >> C >> K;
  for (int r, c; K; --K) {
    cin >> r >> c;
    nim[0] = max(nim[0], c);
    nim[1] = min(nim[1], r);
    nim[2] = min(nim[2], c);
    nim[3] = max(nim[3], r);
  }
  nim[0] = C - nim[0];
  nim[1] -= 1;
  nim[2] -= 1;
  nim[3] = R - nim[3];
}