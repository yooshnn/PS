#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;

int p[110][110];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int C, R; cin >> C >> R;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cin >> p[r][c];
    }
  }

  for (int c = 0; c < C; ++c) {
    for (int r = 0; r < R; ++r) {
      int t; cin >> t;
      if (t != p[R-1-r][c]) {
        cout << "|>___/|     /}" << '\n';
        cout << "| O O |    / }" << '\n';
        cout << "( =0= )\"\"\"\"  \\" << '\n';
        cout << "| ^  ____    |" << '\n';
        cout << "|_|_/    ||__|" << '\n';
        return 0;
      }
    }
  }
  cout << "|>___/|        /}" << '\n';
  cout << "| O < |       / }" << '\n';
  cout << "(==0==)------/ }" << '\n';
  cout << "| ^  _____    |" << '\n';
  cout << "|_|_/     ||__|" << '\n';

}