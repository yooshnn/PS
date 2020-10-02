#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[101][101][2][2]; // row column dirSwitch(false,true) dir(R,U)
int w, h;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	for (int i = 1; i <= 100; ++i) dp[1][i][0][0] = 1; // 1행 1로 초기화
	for (int i = 1; i <= 100; ++i) dp[i][1][0][1] = 1; // 1열 1로 초기화

	for (int i = 2; i <= 100; ++i) {
		for (int j = 2; j <= 100; ++j) {
			dp[i][j][0][0] = (dp[i][j - 1][0][0] + dp[i][j - 1][1][0]) % 100000; // i행 j열로 두칸이상 이동, 진행방향은 오른쪽
			dp[i][j][1][0] = dp[i][j - 1][0][1];
			dp[i][j][0][1] = (dp[i - 1][j][0][1] + dp[i - 1][j][1][1]) % 100000; // i행 j열로 두칸이상 이동, 진행방향은 위쪽
			dp[i][j][1][1] = dp[i - 1][j][0][0];
		}
	}

	cin >> w >> h;

	cout << (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % 100000;

	return 0;
}
