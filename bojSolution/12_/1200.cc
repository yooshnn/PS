#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 0x7fffffffffffffff;

int R, C, H, V;
vector<int> cut;
ll board[20][20], dp[20][20], res = INF;

ll areaSum(int r1, int c1, int r2, int c2) {
  // cout << "  " << r1 << " " << c1 << " " << r2 << " " << c2 << " : " << dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1] << endl;
  return dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1];
}

ll solve() {
  ll lp = 0, rp = (ll)2000000*18*18, mid, ret = INF;

  while (lp <= rp) {
    mid = (lp+rp)/2;

    int w = 1, cnt = 0, good = true;
    for (int i = 1; good && i <= C; ++i) {
      int cei = 1, pp = 0;
      for (int c : cut) {
        if (areaSum(cei, w, c, i) > mid) {
          if (w == i || areaSum(cei, i, c, i) > mid) good = false;
          else pp = 1;
        }
        cei = c+1;
      }
      if (pp) w = i, cnt += 1;
    }
    if (cnt > V) good = false;

    if (good) rp = mid-1, ret = min(ret, mid);
    else lp = mid+1;
  }

  return ret;
}

void dfs(int las, int lef) {
	if (lef == 0) {
		cut.push_back(R);
		ll prevres = res;
		res = min(res, solve());
    	cut.pop_back();
	}
	for (int i = las+1; i < R; ++i) {
		cut.push_back(i);
		dfs(i, lef-1);
		cut.pop_back();
	}
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> R >> C >> H >> V;
	for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
		cin >> board[r][c];
	}
	for (int r = 1; r <= R; ++r) for (int c = 1; c <= C; ++c) {
		dp[r][c] = board[r][c] + dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1];
	}
	
	dfs(0, H);
	
  	cout << res;
	
}