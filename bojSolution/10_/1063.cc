#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;
using pii = pair<int, int>;

int board[8][8];
pii king, rock;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  string s;
  cin >> s; king = {s[1]-'1', s[0]-'A'};
  cin >> s; rock = {s[1]-'1', s[0]-'A'};

  int N; cin >> N;
  while (N--) {
    cin >> s;
    if (s == "B") {
      if (king.first - 1 < 0) continue;
      if (king.first - 1 == rock.first && king.second == rock.second) {
        if (rock.first - 1 < 0) continue;
        rock.first -= 1;
      }
      king.first -= 1;
    }
    if (s == "T") {
      if (king.first + 1 > 7) continue;
      if (king.first + 1 == rock.first && king.second == rock.second) {
        if (rock.first + 1 > 7) continue;
        rock.first += 1;
      }
      king.first += 1;
    }
    if (s == "L") {
      if (king.second - 1 < 0) continue;
      if (king.second - 1 == rock.second && king.first == rock.first) {
        if (rock.second - 1 < 0) continue;
        rock.second -= 1;
      }
      king.second -= 1;
    }
    if (s == "R") {
      if (king.second + 1 > 7) continue;
      if (king.second + 1 == rock.second && king.first == rock.first) {
        if (rock.second + 1 > 7) continue;
        rock.second += 1;
      }
      king.second += 1;
    }
    if (s == "RT") {
      if (king.first + 1 > 7 || king.second + 1 > 7) continue;
      if (king.first + 1 == rock.first && king.second + 1 == rock.second) {
        if (rock.first + 1 > 7 || rock.second + 1 > 7) continue;
        rock.first += 1;
        rock.second += 1;
      }
      king.first += 1;
      king.second += 1;
    }
    if (s == "RB") {
      if (king.first - 1 < 0 || king.second + 1 > 7) continue;
      if (king.first - 1 == rock.first && king.second + 1 == rock.second) {
        if (rock.first - 1 < 0 || rock.second + 1 > 7) continue;
        rock.first -= 1;
        rock.second += 1;
      }
      king.first -= 1;
      king.second += 1;
    }
    if (s == "LT") {
      if (king.first + 1 > 7 || king.second - 1 < 0) continue;
      if (king.first + 1 == rock.first && king.second - 1 == rock.second) {
        if (rock.first + 1 > 7 || rock.second - 1 < 0) continue;
        rock.first += 1;
        rock.second -= 1;
      }
      king.first += 1;
      king.second -= 1;
    }
    if (s == "LB") {
      if (king.first - 1 < 0 || king.second - 1 < 0) continue;
      if (king.first - 1 == rock.first && king.second - 1 == rock.second) {
        if (rock.first - 1 < 0 || rock.second - 1 < 0) continue;
        rock.first -= 1;
        rock.second -= 1;
      }
      king.first -= 1;
      king.second -= 1;
    }
  }
  cout << char('A' + king.second) << char('1' + king.first) << endl;
  cout << char('A' + rock.second) << char('1' + rock.first) << endl;

}
