#define sad return 0
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int arr[3];
  for (int &i : arr) cin >> i;
  sort(arr, arr+3);

  if (arr[2] == arr[0]+2) cout << 0;
  else if (arr[1] == arr[0]+2 || arr[2] == arr[1]+2) cout << 1;
  else cout << 2;
  cout << "\n";
  cout << max(arr[2]-arr[1], arr[1]-arr[0]) - 1;
  
  sad;
}
