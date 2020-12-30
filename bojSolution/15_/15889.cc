#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N; cin >> N; vector<int> p(N);
	for (int& x : p) cin >> x;

	int M = 0;
	for (int i = 1, t; i < N; ++i) {
		cin >> t;
		M = max(M, p[i-1] + t);
		if (M < p[i]) {
			cout << "엄마 나 전역 늦어질 것 같아";
			return 0;
		}
	}
	cout << "권병장님, 중대장님이 찾으십니다";

	//cout << endl; system("pause");
}