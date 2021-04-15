#include <bits/stdc++.h>
#define sad std::cout.flush(), system("pause")
using namespace std;
using ll = long long;

int n, k, res;
vector<string> stu;

void dfs(int depth, string &ans) {
  if (depth == 0) {
    vector<int> pp(n, 0);
    for (int i = 0; i < n; ++i) for (int j = 0; j < k; ++j) {
      if (stu[i][j] == ans[j]) pp[i] += 1;
    }
    res = max(res, *min_element(pp.begin(), pp.end()));
  }
  else {
    ans.push_back('T');
    dfs(depth - 1, ans);
    ans.pop_back();
    ans.push_back('F');
    dfs(depth - 1, ans);
    ans.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> n >> k;

  stu.resize(n);
  for (string &i : stu) cin >> i;

  string ans = "";
  dfs(k, ans);

  cout << res;

}