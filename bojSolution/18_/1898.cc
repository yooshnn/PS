#include <bits/stdc++.h>
#define sad cout.flush(), system("pause")
using namespace std;

int N, arr[50010], p[50010];
bool dup[50010];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    p[arr[i]] = i;
  }

  for (int i = 0; i < N; ++i) {
    if (arr[i] == 1) continue;
    int pp = p[arr[i] - 1];
    if (dup[arr[i]] || dup[arr[i]-1] || pp < i) continue;
    dup[arr[i]] = dup[arr[i]-1] = true;

    swap(p[arr[i]], p[arr[i] - 1]);
    swap(arr[i], arr[pp]);
    
  }

  for (int i = 0; i < N; ++i) cout << arr[i] << " ";
  cout << endl;
}