#include <bits/stdc++.h>
using namespace std;

int N, input;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   cin >> N;
   for (int i = 0; i < N * N; ++i) {
      cin >> input;
      q.push(input);
      if (i >= N) q.pop();
   }

   cout << q.top();

   return 0;
}