#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int root[100010];
int search(int tar) {
	if (tar == root[tar]) return tar;
	return root[tar] = search(root[tar]);
}
void merge(int a, int b) {
	a = search(a), b = search(b);
	if (a == b) return;
   root[b] = a;
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   ll N, Q;
   cin >> N >> Q;

   char type[N+1];

   for (int i = 1; i <= N; ++i) {
      root[i] = i;
      cin >> type[i];
   }

   for (int i = 0, u, v; i < N-1; ++i) {
      cin >> u >> v;
      if (type[u] == type[v]) merge(u, v);
   }

   for (int i = 0; i < Q; ++i) {
      int u, v; char t;
      cin >> u >> v >> t;
      if ((search(u)==search(v) && type[u]==t) || search(u) != search(v)) cout << 1;
      else cout << 0;
   }
}