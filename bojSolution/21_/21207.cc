#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;

int N, L, P;
vector<int> car;
bool door[10010];

int carToPos(int n) {
  return (n * L) + (L / 2);
}
int posToCar(int n) {
  return (n - (L / 2)) / L;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N >> L >> P;

  car.resize(N, 0);

  for (int i = 0; i < N; ++i) {
    door[carToPos(i)] = true;
  }

  int res1 = 0;

  for (int i = 0, pos; i < P; ++i) {
    cin >> pos;
    if (pos >= carToPos(N-1)) {
      car[N-1] += 1;
      res1 = max(res1, pos - carToPos(N-1));
    }
    else {
      int lp = pos, rp = pos;
      while (1) {
        if (door[rp]) {
          car[posToCar(rp)] += 1;
          res1 = max(res1, abs(rp - pos));
          break;
        }
        if (door[lp]) {
          car[posToCar(lp)] += 1;
          res1 = max(res1, abs(lp - pos));
          break;
        }
        if (lp != 0) lp -= 1;
        rp += 1;
      }
    }
  }

  cout << res1 << "\n" << *max_element(car.begin(), car.end());
  
}