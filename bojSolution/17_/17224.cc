#include <iostream>
using namespace std;

int N, L, K;
int k, r;
int sub1[100], sub2[100], visit[100];

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> L >> K;
	for (int i = 0; i < N; ++i) {
		cin >> sub1[i] >> sub2[i];
	}
	for (int i = 0; i < N; ++i) {
		if (k == K) continue;
		if (sub2[i] <= L) {
			visit[i] = 2;
			k++;
			r += 140;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (k == K || visit[i] == 2) continue;
		if (sub1[i] <= L) {
			visit[i] = 1;
			k++;
			r += 100;
		}
	}

	cout << r;

	return 0;
}