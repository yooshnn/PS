#include <bits/stdc++.h>
#define sad std::cout.flush(), std::system("pause")
using namespace std;
using ll = long long;

const int
  ADD[3][3] = { {0, 0, 2}, {0, 1, 1}, {2, 1, 2} },
  SUB[3][3] = { {0, 1, 0}, {1, 1, 2}, {0, 2, 2} },
  MUL[3][3] = { {0, 2, 1}, {2, 1, 0}, {1, 0, 2} },
  e97 = 1e9+7;

struct Val {
  vector<ll> RSP;
  Val() { RSP = {0, 0, 0}; }
  Val(int r, int s, int p) { RSP = {r, s, p}; }
  void put(int r, int s, int p) { Val(r, s, p); }

  Val operator+(Val &other) {
    vector<ll> ret(3, 0);
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
      ret[ADD[i][j]] += RSP[i] * other.RSP[j];
    }
    for (ll &i : ret) i %= e97;
    return Val(ret[0], ret[1], ret[2]);
  }
  Val operator-(Val &other) {
    vector<ll> ret(3, 0);
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
      ret[SUB[i][j]] += RSP[i] * other.RSP[j];
    }
    for (ll &i : ret) i %= e97;
    return Val(ret[0], ret[1], ret[2]);
  }
  Val operator*(Val &other) {
    vector<ll> ret(3, 0);
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
      ret[MUL[i][j]] += RSP[i] * other.RSP[j];
    }
    for (ll &i : ret) i %= e97;
    return Val(ret[0], ret[1], ret[2]);
  }
};

Val merge(char oper, Val &lhs, Val &rhs) {
  if (oper == '+') return lhs+rhs;
  if (oper == '-') return lhs-rhs;
  if (oper == '*') return lhs*rhs;
  assert(0);
}

int exprLen;
string expr;
int jankenResult;

void rd();
void parse();
Val calc();

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  rd();
  parse();
  Val res = calc();

  cout << res.RSP[jankenResult];

}

void rd() {
  cin >> exprLen;
  cin >> expr;
  char t; cin >> t;
  if (t == 'R') jankenResult = 0;
  if (t == 'S') jankenResult = 1;
  if (t == 'P') jankenResult = 2;
}

void parse() {
  string ret;

  map<char, int> prec = {
    {'(', 0}, {'+', 1}, {'-', 1}, {'?', 1}, {'*', 2}, {')', -1}
  };
  
  stack<char> A;
  for (char &c : expr) {
    if (c == 'R' || c == 'S' || c == 'P' || c == '?') ret.push_back(c);
    else if (c == '(') A.push(c);
    else if (c == '+' || c == '-' || c == '*') {
      while (!A.empty() && prec[c] <= prec[A.top()]) {
        ret.push_back(A.top());
        A.pop();
      }
      A.push(c);
    }
    else if (c == ')') {
      while (!A.empty() && A.top() != '(') {
        ret.push_back(A.top());
        A.pop();
      }
      A.pop();
    }
  }
  while (!A.empty()) ret.push_back(A.top()), A.pop();

  expr = ret;
}

Val calc() {
  stack<Val> A;
  for (char &c : expr) {
    if (c == 'R') A.push(Val(1, 0, 0));
    else if (c == 'S') A.push(Val(0, 1, 0));
    else if (c == 'P') A.push(Val(0, 0, 1));
    else if (c == '?') A.push(Val(1, 1, 1));
    else {
      Val lhs, rhs;
      rhs = A.top(), A.pop();
      lhs = A.top(), A.pop();
      A.push(merge(c, lhs, rhs));
    }
  }
  return A.top();
}