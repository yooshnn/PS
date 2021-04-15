#include "videoclips.h"

int dp[100000][36]; // [i][j] continue 2^j times from i-th video
int num; // M:th video she will watch

void videos(int K, int M, int S[]) {
  num = M;
  for (int i = 0; i < K; ++i) dp[i][0] = S[i];

  for (int j = 1; j <= 32; ++j) {
    for (int i = 0; i < K; ++i) {
      dp[i][j] = dp[dp[i][j-1]][j-1];
    }
  }
}

int clip(int i) {
  // equivalent to decimal-binary conversion
  int p = num - 1, ret = i;
  for (int j = 0; j <= 32; ++j) {
    if (p & 1) ret = dp[ret][j];
    p /= 2;
  }
  return ret;
}